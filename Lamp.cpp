#include "Lamp.h"

Lamp::Lamp(int outputPin)
    : dimmer(outputPin)
{ }

void Lamp::setup()
{
  this->dimmer.setPower(MIN_INTENSITY); // To prevent the lamp from turning on by default when the whole thing is connected to a power source
  dimmer.begin(NORMAL_MODE, ON);
}

void Lamp::setIntensity(int intensity)
{
  int intensityToSet = intensity;

  if (intensity > MAX_INTENSITY)
    intensityToSet = MAX_INTENSITY;
  else if (intensity < MIN_INTENSITY)
    intensityToSet = MIN_INTENSITY;

  int currentIntensity = this->getCurrentIntensity();

  if (intensityToSet != currentIntensity)
    this->dimmer.setPower(intensityToSet);
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
