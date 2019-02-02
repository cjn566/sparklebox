#include "utils.h"

bool validPins[51] = {
TRUE	,//	0
TRUE	,//	1
TRUE	,//	2
TRUE	,//	3
TRUE	,//	4
TRUE	,//	5
FALSE	,//	6
FALSE	,//	7
FALSE	,//	8
FALSE	,//	9
FALSE	,//	10
FALSE	,//	11
TRUE	,//	12
TRUE	,//	13
TRUE	,//	14
TRUE	,//	15
TRUE	,//	16
TRUE	,//	17
TRUE	,//	18
TRUE	,//	19
FALSE	,//	20
TRUE	,//	21
TRUE	,//	22
TRUE	,//	23
FALSE	,//	24
TRUE	,//	25
TRUE	,//	26
TRUE	,//	27
FALSE	,//	28
FALSE	,//	29
FALSE	,//	30
FALSE	,//	31
FALSE	,//	32
FALSE	,//	33
FALSE	,//	34
FALSE	,//	35
FALSE	,//	36
FALSE	,//	37
FALSE	,//	38
FALSE	,//	39
FALSE	,//	40
FALSE	,//	41
FALSE	,//	42
FALSE	,//	43
FALSE	,//	44
FALSE	,//	45
FALSE	,//	46
FALSE	,//	47
FALSE	,//	48
FALSE	,//	49
FALSE	,//	50
FALSE	,//	51 
};

int offsetInGlobals = 0;
void instantiateAnLedStrip (uint16_t pin, uint16_t numberOfLeds) {
  // TODO - redo this. We're not building a general purpose framework that will run on anything.
  // This can be opinionated and pick 8 fixed pins on the ESP32.
  

  if(validPins[i]){
      FastLED.addLeds<LED_TYPE, pin, STRIP_COLOR_ORDER>(&Globals.leds[offsetInGlobals], numberOfLeds);
      //   offsetInGlobals += numberOfLeds;     ??
  } else {
    Serial.println("Pin not found!");
    Serial.println(pin);
  }
  offsetInGlobals += numberOfLeds; // Do we want to add to the offset if the pin wasn't found?
}


void instantiateLedStrips () {
  Serial.println("in instantiateLedStrips()");
  for (int i=0; i<Globals.numberOfStrips; i++) {
    instantiateAnLedStrip(
      Globals.pinNumberForEachStrip[i],
      Globals.numberOfLedsInEachStrip[i]
    );
  }
}
