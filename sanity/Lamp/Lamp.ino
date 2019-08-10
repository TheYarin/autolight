#include "Lamp.h"
Lamp lamp(12);
// Lamp lamp(D13,D3);

void setup()
{
  Serial.begin(115200);
  delay(50);
  lamp.setup();
  Serial.println("setup");
}

void loop()
{
  Serial.println("loop 1");

  for (int i = 0; i < 50; i++)
  {
    lamp.brighter();
    delay(30);
  }

  lamp.off();

  delay(500);
  Serial.println("loop 2");
}