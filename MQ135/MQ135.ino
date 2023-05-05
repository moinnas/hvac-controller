#include "MQ135.h"

// This link provides details of how to use the MQ135 repository:
// https://steemit.com/utopian-io/@cha0s0000/arduino-basics-tutorials-use-mq135-air-quality-detecting-module

const int ANALOGPIN=0;
MQ135 gasSensor = MQ135(ANALOGPIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Run this first and get rzero value
  // Then set RZERO value in MQ135.h 
  float rzero = gasSensor.getRZero();
  Serial.println(rzero);

  // Comment out the two lines above after getting rzero value and setting RZERO variable
  // Now run this code below and you should get the correct ppm reading
  // float ppm = gasSensor.getPPM();
  // Serial.println(ppm);
  
  delay(2000);
  
}