#include <Arduino.h>
//#include <d1/pins_arduino.h>

#include "OperationStatus.h"
#include "HumanPresenceDetector.h"
#include "RoomBrightnessDetector.h"
#include "DesiredBrightnessReader.h"
#include "Lamp.h"

OperationStatus operationStatus(5);
Lamp lamp(12);
HumanPresenceDetector humanPresenceDetector(7);
RoomBrightnessDetector roomBrightnessDetector(A0);
DesiredBrightnessReader desiredBrightnessReader(A1);

void setup()
{
  Serial.begin(115200);
  lamp.setup();
  //TEMP   Serial.println("SETUP");
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
  //Serial.println(desiredBrightnessReader.get());
  //Serial.println(roomBrightnessDetector.getRoomBrightness());

  if (!humanPresenceDetector.humanPresenceDetected())
  {
    lamp.off();
  }
  else
  {
    int currentOperationStatus = operationStatus.read();

    switch (currentOperationStatus)
    {
    case OperationStatus::OFF:
      lamp.off();
      break;
    case OperationStatus::AUTO:
      autoAdjustIntensity();
      break;
    case OperationStatus::ON:
      lamp.maxPower();
      break;
    default:
      //TEMP       Serial.print("currentOperationStatus is out of range: ");
      //TEMP       Serial.println(currentOperationStatus);
      break;
    }
  }

  delay(10);

  //digitalWrite(D13, HIGH); // turn the LED on (HIGH is the voltage level)
  // delay(10); // wait for a second
  //digitalWrite(D13, LOW);  // turn the LED off by making the voltage LOW
  // delay(10); // wait for a second
  //
  //
  //  digitalWrite(D13, HIGH);   // turn the LED on (HIGH is the voltage level)
  //  delay(100);                       // wait for a second
  //  digitalWrite(D13, LOW);

  //  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //  delay(100);                       // wait for a second
  //  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //  delay(100);                       // wait for a second
  //
  //
  //  digitalWrite(D13, HIGH);   // turn the LED on (HIGH is the voltage level)
  //  delay(100);                       // wait for a second
  //  digitalWrite(D13, LOW);    // turn the LED off by making the voltage LOW
  //  delay(100);
  //
  //
  //  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //  delay(100);                       // wait for a second
  //  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //  delay(100);                       // wait for a second
  //
  //
  //  digitalWrite(D13, HIGH);   // turn the LED on (HIGH is the voltage level)
  //  delay(100);                       // wait for a second
  //  digitalWrite(D13, LOW);    // turn the LED off by making the voltage LOW
  //
  //  delay(1500);
}
