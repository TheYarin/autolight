#include <Arduino.h>

#include "OperationStatus.h"
#include "HumanPresenceDetector.h"
#include "RoomBrightnessDetector.h"
#include "DesiredBrightnessReader.h"
#include "Lamp.h"

OperationStatus operationStatus(5);
Lamp lamp(8);
HumanPresenceDetector humanPresenceDetector(7);
RoomBrightnessDetector roomBrightnessDetector(A0);
DesiredBrightnessReader desiredBrightnessReader(A1);

void setup()
{
  Serial.begin(115200);
  lamp.setup();
}

void autoAdjustIntensity()
{
  int roomBrightness = roomBrightnessDetector.getRoomBrightness();
  int desiredBrightness = desiredBrightnessReader.get();

  if (abs(desiredBrightness - roomBrightness) < 20)
    return;

  if (roomBrightness < desiredBrightness)
    lamp.brighter();
  else if (roomBrightness > desiredBrightness)
    lamp.darker();
}

void loop()
{
  if (!humanPresenceDetector.humanPresenceDetected())
  {
    lamp.darker();
  }
  else
  {
    int currentOperationStatus = operationStatus.read();

    switch (currentOperationStatus)
    {
    case OperationStatus::OFF:
      lamp.darker();
      break;
    case OperationStatus::AUTO:
      autoAdjustIntensity();
      break;
    case OperationStatus::ON:
      lamp.brighter();
      break;
    default:
      break;
    }
  }

  delay(10);
}
