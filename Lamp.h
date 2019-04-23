#include <Arduino.h>
#include <RBDdimmer.h>

class Lamp {
public:
  Lamp(int outputPin, int zciPin);
  void brighter();
  void darker();
  void max();
  void off();

private:
  const int MAX_INTENSITY = 99;
  const int MIN_INTENSITY = 7; // Anything lower than that results in flickering or max brightness
  const int INTENSITY_STEP = 1;

  int lightIntensity = -1;
  dimmerLamp dimmer;
  
  void setIntensity(int intensity);
  int getCurrentIntensity();
};
