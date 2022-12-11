# Fireplace

This minimalistic device emulates a cozily flickering fireplace by applying a random
walk PWM on two output pins of an ATtiny13. Simply connect a red LED to pin 5
and a yellow LED to pin 6 (using appropriate series resistors of course).

Example:
```
GND--[100nF]--VCC

     +--------+
    -|1 °    8|--VCC
    -|2      7|-
    -|3      6|--[330R]--|>--GND
GND--|4      5|--[330R]--|>--GND
     +--------+
```

Consider adding 10uF to VCC/GND when using longer power wires. Enjoy!
