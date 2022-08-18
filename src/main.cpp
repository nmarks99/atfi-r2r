#include <Arduino.h>
#include <HX711.h>
#include <stdio.h>
#include "usart.h"

#define DOUT 2
#define SCK 3
#define segA 6
#define segB 0
#define segC 10
#define segD 12
#define segE 13
#define segF 5
#define segG 9
#define segDP 11

#define D1 8
#define D2 1
#define D3 4
#define D4 7

/* SevSeg Counter Example
 
 Copyright 2020 Dean Reading
 
 This example demonstrates a very simple use of the SevSeg library with a 4
 digit display. It displays a counter that counts up, showing deci-seconds.
 */

#include <Arduino.h>
#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object
HX711 loadcell;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {D4, D3, D2, D1};
  byte segmentPins[] = {segA, segB, segC, segD, segE, segF, segG, segDP};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
  
  loadcell.begin(DOUT,SCK);
  loadcell.set_scale(3910);
  loadcell.tare();

}


void loop() {
  static unsigned long timer = millis();

  // refresh at 10 Hz  
  if (millis() - timer >= 100) {
    float x = loadcell.get_units();
    timer += 100;
    sevseg.setNumberF(x, 1);
  }

  sevseg.refreshDisplay(); // Must run repeatedly
}
