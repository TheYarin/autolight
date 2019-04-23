#include <Arduino.h>
//#include <d1/pins_arduino.h>
#include <RBDdimmer.h>

#include "OperationStatus.h"
#include "HumanPresenceDetector.h"
#include "RoomBrightnessDetector.h"
#include "DesiredBrightnessReader.h"
#include "Lamp.h"

OperationStatus operationStatus;
Lamp lamp(D12, D3);
HumanPresenceDetector humanPresenceDetector(D5);
RoomBrightnessDetector roomBrightnessDetector(A0);
DesiredBrightnessReader desiredBrightnessReader(A0);

void setup() {
  Serial.begin(115200);
  Serial.println("Hello!");
}

void autoAdjustIntensity() {
  int roomBrightness = roomBrightnessDetector.getRoomBrightness();
  int desiredBrightness = desiredBrightnessReader.get();

  if (abs(desiredBrightness - roomBrightness) < 50)
    return;

  if (roomBrightness < desiredBrightness)
    lamp.brighter();
  else if (roomBrightness > desiredBrightness)
    lamp.darker();
}

void loop() {
  //Serial.println(desiredBrightnessReader.get());
  Serial.println(roomBrightnessDetector.getRoomBrightness());

  if (!humanPresenceDetector.humanPresenceDetected()) {
    lamp.off();

    return;
  }

  int currentOperationStatus = operationStatus.read();

  switch (currentOperationStatus) {
    case OperationStatus::OFF:
      lamp.off();
      break;
    case OperationStatus::AUTO:
      autoAdjustIntensity();
      break;
    case OperationStatus::ON:
      lamp.max();
      break;
    default: {
        //throw new Exception();
      }
  }
  //  delay(10);

  digitalWrite(D13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);                       // wait for a second
  digitalWrite(D13, LOW);    // turn the LED off by making the voltage LOW
  delay(10);                       // wait for a second
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
