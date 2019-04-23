//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(115200);
//  while (!Serial) ;
//  delay(30);
//  Serial.println("hello?");
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  Serial.println("loop");
//  delay(200);
//}

#include <RBDdimmer.h>

dimmerLamp dimmer(D13, digitalPinToInterrupt(D1));

void setup() {
  Serial.begin(115200);
  delay(50);
  Serial.println("setup");
  dimmer.begin(NORMAL_MODE, ON);
  //dimmer.setPower(60); 
  //pinMode(D13, OUTPUT);
}
int power = 0;
void loop() {
  //dimmer.setState(ON);
  //digitalWrite(D13, HIGH);
  Serial.println("boom");
  //delay(100);
  //dimmer.setState(OFF);
  //digitalWrite(D13, LOW);
  //delay(100);
  dimmer.setPower(power++%100);
  delay(50);
}
