#include "Lamp.h"

Lamp::Lamp(int outputPin)
    : dimmer(outputPin)
{
  // dimmer.begin(NORMAL_MODE, ON);
  Serial.println("Lamp 2!");
}

void Lamp::setup()
{
  dimmer.begin(NORMAL_MODE, ON);
}

void Lamp::setIntensity(int intensity)
{
  int intensityToSet = intensity;
  Serial.print("BLOOP ");
  Serial.println(intensity);
  if (intensity > MAX_INTENSITY)
    intensityToSet = MAX_INTENSITY;
  else if (intensity < MIN_INTENSITY)
    intensityToSet = MIN_INTENSITY;

  if (intensityToSet != this->getCurrentIntensity())
  {
    Serial.print("Lamp set: ");
    Serial.print(this->getCurrentIntensity());
    Serial.print(" ");
    Serial.println(intensityToSet);
    this->dimmer.setPower(intensityToSet);
  }
}

int Lamp::getCurrentIntensity()
{
  return this->dimmer.getPower();
}

void Lamp::brighter()
{
  this->setIntensity(this->getCurrentIntensity() + INTENSITY_STEP);
}

void Lamp::darker()
{
  this->setIntensity(this->getCurrentIntensity() - INTENSITY_STEP);
}

void Lamp::maxPower()
{
  this->setIntensity(MAX_INTENSITY);
}

void Lamp::off()
{
  this->setIntensity(MIN_INTENSITY);
}
