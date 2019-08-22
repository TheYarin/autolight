#include <Arduino.h>;

#include "OperationStatus.h";

OperationStatus::OperationStatus(int inputPin)
{
  pinMode(inputPin, INPUT);
  this->inputPin = inputPin;
}

int OperationStatus::read()
{
  int analogReadVal = analogRead(this->inputPin);

  // Heuristically, analogReadVal should be either 0, 338, or 612. In order to overcome the values being slightly different, this value will be
  int roundedValue = analogReadVal / 100;

  switch (roundedValue)
  {
  case 0:
    return OperationStatus::OFF;
  case 6:
    return OperationStatus::AUTO;
  case 3:
    return OperationStatus::ON;
  default:
  {
    return OperationStatus::OFF;
  }
  }
}
