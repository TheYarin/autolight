#include <Arduino.h>

#include "HumanPresenceDetector.h"

HumanPresenceDetector::HumanPresenceDetector(int inputPin) {
    pinMode(inputPin, INPUT);
    this->inputPin = inputPin;
}

bool HumanPresenceDetector::humanPresenceDetected() {
    return HIGH;
    int val = digitalRead(this->inputPin); // Should be 0 (LOW) if no presence is detected or 1 (HIGH) if presence detected

    return val == HIGH;
}
