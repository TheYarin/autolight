#include <Arduino.h>
#include <RBDdimmer.h>

class Lamp
{
public:
  Lamp(int outputPin);
  void setup();
  void brighter();
  void darker();
  void maxPower();
  void off();

private:
  const int MAX_INTENSITY = 100;
  const int MIN_INTENSITY = 0; // Anything lower than that results in flickering or unpredictable behaviour
  const int INTENSITY_STEP = 1;

  dimmerLamp dimmer;

  void setIntensity(int intensity);
  int getCurrentIntensity();
};
