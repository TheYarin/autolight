#include <Arduino.h>

#include "DesiredBrightnessReader.h"

// Works better with 3.3V
DesiredBrightnessReader::DesiredBrightnessReader(int inputPin)
{
  pinMode(inputPin, INPUT);
  this->inputPin = inputPin;
}

// Heuristically returns values between 5 and 1024
int DesiredBrightnessReader::get()
{
  return 100; // Because of the broken potentiometer
  int val = analogRead(this->inputPin);
//TEMP   Serial.print("Desired brightness level: ");
//TEMP   Serial.println(val);
  return val;
}
