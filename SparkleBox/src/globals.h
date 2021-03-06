#ifndef GLOBALS_H
  #define GLOBALS_H

  // FastLED
  #define FASTLED_ALLOW_INTERRUPTS 0
  #include "FastLED.h"
  FASTLED_USING_NAMESPACE

  // Arduino
  #include "Arduino.h"

  // Pixel and Microcontroller settings
  #define DATA_PIN 2
  #define LED_TYPE WS2812B
  #define MAX_STRIPS 30
  #define MAX_LEDS 3000
  #define MAX_ANIMATIONS_PER_SCENE 30
  #define STRIP_COLOR_ORDER BGR

  // Structs
  typedef struct {
    uint16_t numberOfStrips;
    uint16_t numberOfLedsInEachStrip[MAX_STRIPS];
    uint16_t ledOffsetForEachStrip[MAX_STRIPS];
    uint16_t pinNumberForEachStrip[MAX_STRIPS];
    uint16_t totalNumberOfLeds;
    CRGB leds[MAX_LEDS];
    CRGB sceneWorkingLeds[MAX_LEDS];
  } globals_struct_t;

  namespace EEPROM {
    extern void loadData ();
  }

  // globals variables
  extern globals_struct_t Globals;

#endif
