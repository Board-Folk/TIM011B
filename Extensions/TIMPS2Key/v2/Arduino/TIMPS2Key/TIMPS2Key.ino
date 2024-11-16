// TIMPS2Key v2
// PS/2 Keyboard interface for the TIM-011
// v2 including Sound and LEDs via I2C
// @grandoldian 05/2024
// v2.0 25/05/2024

#include <Wire.h>
#include <PS2KeyAdvanced.h>
#include "TIMPS2Key.h"

PS2KeyAdvanced keyboard;
TIMkeyboard tkey;

byte cmdState=0;
// cmdState = 0 - no command
//            1 - command being received
//            2 - command active

byte ledState=0xcf;  // bits of led

void setup() {
  char outChar=0xff;

  keyboard.begin(DATA_PIN, IRQ_PIN);
  keyboard.setNoRepeat(0);
  keyboard.setNoBreak(0);
  keyboard.setLock(PS2_LOCK_CAPS + PS2_LOCK_NUM);
  Wire.begin();
  tkey.begin();

  if (debug) {
    Serial.begin (9600,SERIAL_8N1);
  } else {
    Serial.begin (9600,SERIAL_8E1);
  }

  // Initialise LED
  tkey.setSpecial(0x25);    // What's the default?
  tkey.setLed(ledState);

  // Send 0xff denoting power up
  Serial.print(outChar);
  Serial.flush();
}

void loop() {

      byte readByte=0;

      if ( keyboard.available() ) {
        tkey.Input(keyboard.read());
      }

    if (Serial.available() > 0) {
      readByte=Serial.read();
      if (debug) {
        Serial.print("Read byte:");
        Serial.println(readByte,HEX);
      }
      if ((readByte==0x40) && (cmdState==2)) {
        tkey.stopCmd();
        cmdState=0;
      } else {
        // Reset, start again
        if ((readByte==0x00) && (cmdState==2)) {
          tkey.stopCmd();
          cmdState=0;
        }
        // Reset End
        if ((readByte==0x00) && (cmdState==0)) {
          cmdState++; 
        } else {
          if (cmdState==1) {
            // Process Command

            // Beep
            if ((readByte>=0x40) && (readByte<=0x7f)) {
              cmdState++;
              tkey.beep(readByte);
              if ((readByte==0x40) || (readByte==0x7f)) {
                // that's all you get
                cmdState=0;
              }
            }

            // LED 
            if (readByte<=0x3f) {
              cmdState=0;
              ledState=(((readByte & 0x01)<<4)+   // kb lock
                        ((readByte & 0x20)>>5)+   // l4
                        ((readByte & 0x10)>>3)+   // l3
                        ((readByte & 0x08)>>1)+   // l2
                        ((readByte & 0x04)<<1));  // l1
              if (readByte & 0x02) {
                ledState+=0x80;                   // line
              } else {
                ledState+=0x40;                   // local
              }
              tkey.setLed(ledState);
            }

            // Special bit 7

            if ((cmdState==1) && (readByte & 0x80)) {
              cmdState=0;
              tkey.setSpecial(readByte);
            }

            // Unknown command, leave the state
            if (cmdState==1) {
              cmdState=0;
            }

          }
        }
      }
    } 
}
