#include <Arduino.h>

#include "RoomBrightnessDetector.h"

RoomBrightnessDetector::RoomBrightnessDetector(int inputPin)
{
    pinMode(inputPin, INPUT);
    this->inputPin = inputPin;
}

// Heuristically returns values between 10 (dark) and 1024 (bright)
int RoomBrightnessDetector::getRoomBrightness()
{
    int val = analogRead(this->inputPin);

//TEMP     Serial.print("Room brightness: ");
//TEMP     Serial.println(val);

    return val;
}
