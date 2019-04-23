#include <RBDdimmer.h>

#include "Lamp.h";

Lamp::Lamp(int outputPin, int zciPin)
  : dimmer(outputPin, zciPin) {
  dimmer.begin(NORMAL_MODE, ON);
}

void Lamp::setIntensity(int intensity) {
  int intensityToSet = intensity;

  if (intensity > MAX_INTENSITY)
    intensityToSet = MAX_INTENSITY;
  else if (intensity < MIN_INTENSITY)
    intensityToSet = MIN_INTENSITY;

  if (intensityToSet != this->getCurrentIntensity()) {
    Serial.print("Lamp set: ");
    Serial.print(this->getCurrentIntensity());
    Serial.print(" ");
    Serial.println(intensityToSet);
    this->dimmer.setPower(intensityToSet);
  }
}

int Lamp::getCurrentIntensity() {
  return this->dimmer.getPower();
}

void Lamp::brighter() {
  this->setIntensity(this->getCurrentIntensity() + INTENSITY_STEP);
}

void Lamp::darker() {
  this->setIntensity(this->getCurrentIntensity() - INTENSITY_STEP);
}

void Lamp::max() {
  this->setIntensity(MAX_INTENSITY);
}

void Lamp::off() {
  this->setIntensity(MIN_INTENSITY);
}
