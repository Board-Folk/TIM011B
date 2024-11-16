// TIMPS2Key
// Simple PS/2 Keyboard for the TIM-011
// @grandoldian 03/2024
// v0.1 09/04/2024

#include <PS2KeyAdvanced.h>
#include "TIMPS2Key.h"

PS2KeyAdvanced keyboard;
TIMkeyboard tkey;

void setup() {
  char outChar=0xff;

  keyboard.begin(DATA_PIN, IRQ_PIN);
  keyboard.setNoRepeat(0);
  keyboard.setNoBreak(0);
  keyboard.setLock(PS2_LOCK_CAPS + PS2_LOCK_NUM);
  tkey.begin();

  if (debug) {
    Serial.begin (9600,SERIAL_8N1);
  } else {
    Serial.begin (9600,SERIAL_8E1);
  }

  // Send 0xff denoting power up
  Serial.print(outChar);
  Serial.flush();
}

void loop() {
  if ( keyboard.available() ) {
    tkey.Input(keyboard.read());
  }
 
}
