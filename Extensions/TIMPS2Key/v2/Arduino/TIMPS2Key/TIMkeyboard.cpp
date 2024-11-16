// TIMkeyboard.cpp
// @grandoldian 05/2024
// v2.0 25/05/2024

#include <Wire.h>
#include "TIMPS2key.h"
#include "keymap.h"

int lctrl_pressed=0;
int rctrl_pressed=0;
int capslock=1;
byte ledTrack=0;
byte keylock=0;
byte autorepeat=0;  // 0 off, 1 slow, 2 fast
byte linelocal=0;   // 0 local, 1 line
byte keybeep=0;
byte keyclick=0;
byte repeatdelay=0; // 0 short, 1 long

void TIMkeyboard::setLed(byte led) {
  byte outLed=0;

    if (debug) {
      Serial.println("LED");
      Serial.println(led,HEX);
      Serial.println("");
    }

    ledTrack=led;

    outLed=(led&0x3f)+(capslock<<5)+(1<<(!linelocal+6));

    // invert appropriate bits
    outLed=outLed^0xcf;

    keylock=(outLed & 0x10)!=0;

    if ((keylock) && (debug)) {
      Serial.println("Keyboard Locked");
    } 

    if ((!keylock) && (debug)) {
      Serial.println("Keyboard Unlocked");
    } 

    Wire.beginTransmission(LED_PORT);
    Wire.write(outLed);
    Wire.endTransmission();
}

void TIMkeyboard::setSpecial(byte special)
{

  if ((special & 0x40)>0) {
  autorepeat=1;
  } else {
    if ((special & 0x20)>0) {
      autorepeat=2;
    } else {
      autorepeat=0;
    }
  }

  keybeep=((special & 0x08)>0);
  keyclick=((special & 0x04)>0);
  repeatdelay=((special & 0x02)==0);
  linelocal=((special & 0x01)>0);

  if (debug) {
    Serial.print("Autorepeat: ");
    Serial.println(autorepeat,DEC);
    Serial.print("Key Beep: ");
    Serial.println(keybeep,DEC);
    Serial.print("Key Click: ");
    Serial.println(keyclick,DEC);
    Serial.print("Repeat Delay: ");
    Serial.println(repeatdelay,DEC);
    Serial.print("Line Local: ");
    Serial.println(linelocal,DEC);
  }
}

void TIMkeyboard::keyBeep()
{
  tone(BUZZER_PIN, 770);
  delay(5);
  noTone(BUZZER_PIN);
}

void TIMkeyboard::keyClick()
{
  tone(BUZZER_PIN, 1256);
  delayMicroseconds(500);
  noTone(BUZZER_PIN);
}

void TIMkeyboard::beep(byte cmd) {
   if (debug) {
    Serial.println("Beep");
    Serial.println(cmd,HEX);
    Serial.println("");
   }
   switch (cmd) {
    case 0x40:
     tone(BUZZER_PIN, 770);
     delay(1000);
     noTone(BUZZER_PIN);
     break;
    case 0x41:
     break;
    case 0x42:
    case 0x62:
     tone(BUZZER_PIN, 165);
     break;
    case 0x43:
    case 0x63:
     tone(BUZZER_PIN, 174);
     break;
    case 0x44:
    case 0x64:
     tone(BUZZER_PIN, 185);
     break;
    case 0x45:
    case 0x65:
     tone(BUZZER_PIN, 196);
     break;
    case 0x46:
    case 0x66:
     tone(BUZZER_PIN, 207);
     break;
    case 0x47:
    case 0x67:
     tone(BUZZER_PIN, 220);
     break;
    case 0x48:
    case 0x68:
     tone(BUZZER_PIN, 233);
     break;
    case 0x49:
    case 0x69:
     tone(BUZZER_PIN, 247);
     break;
    case 0x4a:
    case 0x6a:
     tone(BUZZER_PIN, 261);
     break;
    case 0x4b:
    case 0x6b:
     tone(BUZZER_PIN, 277);
     break;
    case 0x4c:
    case 0x6c:
     tone(BUZZER_PIN, 294);
     break;
    case 0x4d:
    case 0x6d:
     tone(BUZZER_PIN, 310);
     break;
    case 0x4e:
    case 0x6e:
     tone(BUZZER_PIN, 330);
     break;
    case 0x4f:
    case 0x6f:
     tone(BUZZER_PIN, 349);
     break;
    case 0x50:
    case 0x70:
     tone(BUZZER_PIN, 370);
     break;
    case 0x51:
    case 0x71:
     tone(BUZZER_PIN, 390);
     break;
    case 0x52:
    case 0x72:
     tone(BUZZER_PIN, 415);
     break;
    case 0x53:
    case 0x73:
     tone(BUZZER_PIN, 440);
     break;
    case 0x54:
    case 0x74:
     tone(BUZZER_PIN, 466);
     break;
    case 0x55:
    case 0x75:
     tone(BUZZER_PIN, 494);
     break;
    case 0x56:
    case 0x76:
     tone(BUZZER_PIN, 523);
     break;
    case 0x57:
    case 0x77:
     tone(BUZZER_PIN, 554);
     break;
    case 0x58:
    case 0x78:
     tone(BUZZER_PIN, 586);
     break;
    case 0x59:
    case 0x79:
     tone(BUZZER_PIN, 622);
     break;
    case 0x5a:
    case 0x7a:
     tone(BUZZER_PIN, 660);
     break;
    case 0x5b:
    case 0x7b:
     tone(BUZZER_PIN, 698);
     break;
    case 0x5c:
    case 0x7c:
     tone(BUZZER_PIN, 740);
     break;
    case 0x5d:
    case 0x7d:
     tone(BUZZER_PIN, 784);
     break;
    case 0x5e:
    case 0x7e:
     tone(BUZZER_PIN, 830);
     break;
    case 0x5f:
     tone(BUZZER_PIN, 515);
     break;
    case 0x7f:
     tone(BUZZER_PIN, 770);
     delay(100);
     noTone(BUZZER_PIN);
     break;
   }
}

void TIMkeyboard::stopCmd() {
   if (debug) {
    Serial.println("Stop Command");
   }
   noTone(BUZZER_PIN);
}

void TIMkeyboard::Input(uint16_t k) {
  byte ekey=0;
  byte kmap=0;
  byte kout=0;
  char outChar=0;

  // Key Lock
  if (keylock) return;

  ekey=(k & 0x00ff);

  if (ekey == LCTRL_KEY) {
    lctrl_pressed=((k & 0x8000)==0);
  }

  if (ekey == RCTRL_KEY) {
    rctrl_pressed=((k & 0x8000)==0);
  }

  if ((ekey == LCTRL_KEY) || (ekey == RCTRL_KEY)) return;

  if (ekey == CAPSLOCK_KEY) {
    capslock = !capslock;
    setLed(ledTrack);
    if (debug) {
      if (capslock) {
        Serial.println("Caps Lock on");
      } else {
        Serial.println("Caps Lock off");
      }
    }
    return;
  }

  if (ekey==250) return;

  if (( k & 0x8000 ) == 0) {
    // Not release 

    // Key Sounds
    if (keybeep) keyBeep();
    if (keyclick) keyClick();

    if (( k & 0x4000 ) == 0) {
    
    // no shift
    if (ekey<256) kmap=ekey;

    if (lctrl_pressed || rctrl_pressed) {
        kout=keymap_ctrl[kmap];
    } else {
        kout=keymap_noshift[kmap];
    }
    
    } else {
    
    // shift
    if (ekey<256) kmap=ekey;
    kout=keymap_shift[kmap];
    
    }

    if (kmap==SHIFT_KEY) return;   // shift

    // Caps Lock

    if (capslock) {
      if (keymap_capsmod[kmap]!=0xff) kout=keymap_capsmod[kmap];
    } else {
      // Invert A-Z/a-z
      if ((kout>=0x41) && (kout<=0x5A)) {   // A-Z
        kout=kout+0x20;
      } else {
        if ((kout>=0x61) && (kout<=0x7A)) {   // a-z
          kout=kout-0x20;
        }
      }
    }

    if (debug) {
        Serial.println(kmap,DEC);
        Serial.println(kout,DEC);
        Serial.println("");
    }

    if (kout!=0xff) {
      outChar=kout;
      if (debug) Serial.print("Output: '");
      Serial.print(outChar);
      if (debug) Serial.println("'");
      Serial.flush();
    } 
   
  }
}

void TIMkeyboard::begin(){
}

TIMkeyboard::TIMkeyboard(){
}
