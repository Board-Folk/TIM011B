// TIMkeyboard.cpp
// @grandoldian 03/2024
// v0.1 09/04/2024

#include "TIMPS2key.h"
#include "keymap.h"

int lctrl_pressed=0;
int rctrl_pressed=0;
int capslock=1;

void TIMkeyboard::Input(uint16_t k) {
  byte ekey=0;
  byte kmap=0;
  byte kout=0;
  char outChar=0;
  
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
