## Flashing a new XD75

1. Flash an Arduino UNO with the **ArduinoISP** Example
2. Wire it up. The XD75 has vertical ISP pins. GND is at the top, followed by RESET. MISO is the square "pin" at the bottom.

  ```
   USB-C
    | |
                            ( ) GND
                            ( ) RESET
                            ( ) MOSI
                            ( ) SCK
                            ( ) Vcc
                            [ ] MISO
  ```

  On the Arduino UNO, the pins are:
  - RESET 10
  - MOSI  11
  - MISO  12
  - SCK   13

3. Select "Tools > Board: Grayduino Atmega 32u4" (this custom board makes the LED pins available for the keyboard)
4. Select "Tools > Programmer: Arduino as ISP"
5. "Burn Bootloader"
6. Keyboard should be ready! Plug it into USB directly.
7. Double check Board and Port
8. Select "Tools > Programmer: AVR ISP"
9. Upload **xd75.ino**
