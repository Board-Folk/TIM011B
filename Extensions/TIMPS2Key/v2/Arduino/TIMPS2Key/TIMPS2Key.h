// TIMPS2Key.h
// @grandoldian 05/2024
// v2.0 25/05/2024

#ifndef TIMkeyboard_h
#define TIMkeyboard_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define DATA_PIN        12 // Data pin for PS2 keyboard
#define IRQ_PIN         3  // Interrupt pin for PS2 keyboard

#define LED_PORT        0x20
#define BUZZER_PIN      A0

#define CAPSLOCK_KEY    3
#define SHIFT_KEY       6
#define LCTRL_KEY       8
#define RCTRL_KEY       9

#define debug           0

class TIMkeyboard {
  public:
    TIMkeyboard();
    
    static void Input(uint16_t k);
    static void setLed(byte led);
    static void setSpecial(byte special);
    static void keyBeep();
    static void keyClick();
    static void beep(byte cmd);
    static void stopCmd();
    static void begin();
};

#endif
