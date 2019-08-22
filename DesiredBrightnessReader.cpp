#include <Arduino.h>

#include "DesiredBrightnessReader.h"

// Works better with 3.3V
DesiredBrightnessReader::DesiredBrightnessReader(int inputPin)
{
  pinMode(inputPin, INPUT);
  this->inputPin = inputPin;
}

int DesiredBrightnessReader::get()
{
  int val = analogRead(this->inputPin);
  
  return val;
}
