#include "SerialRead.h"
#include <Mechy/Sticky.h>
#include <EEPROM.h>

SerialRead::SerialRead() {
    current = NULL;
    if (int length = EEPROM.read(0)) {
        current = (char*)calloc((size_t)length, sizeof(char));
        int value;
        for (uint16_t index = 0; index < length; ++index) {
            value = EEPROM.read(1 + index);
            current[index] = value & 0b11111111;
        }
    }
}

uint8_t SerialRead::defaultName() {
    return FN_USER(0);
}

void SerialRead::run(Event* event) {
    if (!current|| !event->isPressed()) { return; }

    uint16_t mods = mechy->currentModifiers();
    mechy->clearModifiers();
    Keyboard.print(current);
    Keyboard.print("\n");
    mechy->updateModifiers(mods);
}

void SerialRead::tick() {
    if (!Serial.available()) {
        return;
    }

    unsigned int expectedLength = Serial.available();
    unsigned int allocLength = expectedLength + 1;
    unsigned int actualLength = 0;
    if (current) {
        free(current);
    }
    current = (char*)calloc((size_t)allocLength, sizeof(char));
    if (!current) { return; }

    char incomingByte;
    while (Serial.available()) {
        incomingByte = Serial.read() & 0b11111111;
        current[actualLength] = incomingByte;
        actualLength += 1;
        if (actualLength == allocLength) {
            char *prev = current;

            allocLength += expectedLength + 1;
            current = (char*)calloc((size_t)allocLength, sizeof(char));
            if (current && prev) {
                strcpy(current, prev);
            }

            if (prev) {
                free(prev);
            }

            if (!current) {
                EEPROM.write(0, 0);
                return;
            }
        }
    }

    if (actualLength && current[actualLength - 1] == '\n') {
        current[actualLength - 1] = '\0';
    }

    if (actualLength < 512) {
        EEPROM.write(0, (int)actualLength);
        for (uint16_t index = 0; index < actualLength; ++index) {
            EEPROM.write(index + 1, (int)current[index]);
        }
    } else {
        EEPROM.write(0, 0);
    }
}
