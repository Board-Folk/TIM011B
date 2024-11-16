# TIMPS2Key

ATMega/Arduino based PS/2 Keyboard Adapter. Will soon be adding the daughter board for v1.2 or later main boards which will allow fitting within the original board footprint instead of the related serial circuitry and DIN socket.

## Versions

v0 Prototype / Development board using Arduino Nano and a MAX232.

v1 Final Arduino Nano Version. Now includes sound and i2c output for LED panel.

v2 ATMEGA328 Version of v1

## Notes

For use on v1.2 or later main boards with 5V power output selected, bypass voltage regulator at U3 connecting pins 1 and 3

## TIMI2CLEDPanel

This folder contains an I2C connected board to output the keyboard LED display. It's intended to fit within a 3.5" drive blanking front panel blanking plate.


