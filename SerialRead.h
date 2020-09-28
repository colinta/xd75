#pragma once

#include <Keyboard.h>
#include <Mechy.h>

class SerialRead: public Plugin {
public:
    SerialRead();
    void tick();
    uint8_t defaultName();
    void run(Event* event);

protected:
    char *current;
};

#define SR(n) { .name = FN_USER(0), .key = (n) }
#define SR_PASTE SR(0)
