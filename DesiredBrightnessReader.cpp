#include <Arduino.h>

#include "DesiredBrightnessReader.h"

// Works better with 3.3V
DesiredBrightnessReader::DesiredBrightnessReader(int inputPin) {
  pinMode(inputPin, INPUT);
  this->inputPin = inputPin;
}

// Heuristically returns values between 5 and 1024
int DesiredBrightnessReader::get() {
  return 500;
  int val = analogRead(this->inputPin);
  return val;
}
