# TIMPS2KeyMini

ATMega328 based PS/2 Keyboard Adapter. A daugherboard that will fit within the mainboard footprint instead of the traditional 5 pin DIN ASCII keyboard socket. This includes the i2c connector for the TIMI2CLEDPanel board which provides the LEDs.

## Versions

v1.1 Initial release

## Main board modifications

This fits instead of the external RS232 functionality of the original keyboard and connector. Do not fit the MAX232 at J9, the 5 pin DIN socket J3 and the charge caps C58-C61, fitting the 4 pin header J5 instead. Standoffs will needed to be mounted to secure the mini keyboard board and the pin length of the J5 header should match the standoff length. Recommendations may follow.

## Programming the ATMega328

The board doesn't include a programming header, the ATMega328 chip needs programming separately. The simplest way of doing this is with a Minipro with the appopriate fuse settings set in Xgpro. Tested settings are in the screenshot below and the exported binary and hex files for programming can be found in the Arduino/export folder.




