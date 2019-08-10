#include "Lamp.h"

Lamp::Lamp(int outputPin)
    : dimmer(outputPin)
{
  //TEMP   Serial.println("Lamp 2!");
}

void Lamp::setup()
{
  dimmer.begin(NORMAL_MODE, ON);
}

void Lamp::setIntensity(int intensity)
{
  //TEMP   Serial.print("Lamp requested: ");
  //TEMP   Serial.println(intensity);

  int intensityToSet = intensity;

  if (intensity > MAX_INTENSITY)
    intensityToSet = MAX_INTENSITY;
  else if (intensity < MIN_INTENSITY)
    intensityToSet = MIN_INTENSITY;

  int currentIntensity = this->getCurrentIntensity();

  // if (intensityToSet != currentIntensity)
  // if (intensityToSet == MIN_INTENSITY)
  //   this->dimmer.setState(OFF);
  // else
  //   this->dimmer.setState(ON);

  // if (true)

  if (intensityToSet != currentIntensity)
  {
    //TEMP     Serial.print("Lamp old: ");
    //TEMP     Serial.print(currentIntensity);
    //TEMP     Serial.print(" new: ");
    //TEMP     Serial.println(intensityToSet);
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
