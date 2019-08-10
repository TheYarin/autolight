#include <RBDdimmer.h>

dimmerLamp dimmer(12);

void setup()
{
  Serial.begin(115200);
  delay(50);
  Serial.println("setup");
  delay(500);
  dimmer.begin(NORMAL_MODE, ON);
  Serial.println("setup after dimmer.begin()");
  //dimmer.setPower(60);
  //pinMode(D13, OUTPUT);
}

void loop()
{
  // playWithGetPower();
  readAndSet();
}

void playWithGetPower()
{
  dimmer.setPower(0);

  while (true)
  {
    int temp1 = dimmer.getPower();

    Serial.println(temp1);
  }
}

int power = 0;
void readAndSet()
{
  Serial.println("loop!");
  delay(50);
  //for (int i = 0; i < 103; i++) {
  int i = 0;

  while (i != -111)
  {
    Serial.print("power: ");
    Serial.println(i);
    dimmer.setPower(i);
    Serial.println(i);
    while (!Serial.available())
      ; // wait for serial
    i = Serial.parseInt();
  }

  Serial.println("loop end");
  return;
  Serial.println("power: 1");
  dimmer.setPower(1);
  while (!Serial.available())
    ; // wait for serial
  Serial.readString();
  Serial.println("power: 2");
  dimmer.setPower(2);
  while (!Serial.available())
    ; // wait for serial
  Serial.readString();
  Serial.println("power: 50");
  dimmer.setPower(50);
  while (!Serial.available())
    ; // wait for serial
  Serial.readString();
  Serial.println("power: 99");
  dimmer.setPower(99);
  while (!Serial.available())
    ; // wait for serial
  Serial.readString();
  Serial.println("power: 100");
  dimmer.setPower(100);
  while (!Serial.available())
    ; // wait for serial
  Serial.readString();
  return;
  //dimmer.setState(ON);
  //digitalWrite(D13, HIGH);
  Serial.println(power);
  //delay(100);
  //dimmer.setState(OFF);
  //digitalWrite(D13, LOW);
  //delay(100);
  power = (power + 1) % 100;
  dimmer.setPower(power);
  delay(50);
}

//int AC_LOAD = D13;    // Output to Opto Triac pin
//int ZC_PIN = D1;
//int dimming = 128;  // Dimming level (0-128)  0 = ON, 128 = OFF
//
//void setup()
//{
//  Serial.begin(115200);
//  delay(20);
//  Serial.println("hello?");
//  pinMode(AC_LOAD, OUTPUT);// Set AC Load pin as output
//  pinMode(ZC_PIN, INPUT);
//  Serial.println(digitalPinToInterrupt(D2));
//  Serial.println(digitalPinToInterrupt(D3));
//  Serial.println(digitalPinToInterrupt(D1));
//  Serial.println(digitalPinToInterrupt(D0));
//  attachInterrupt(digitalPinToInterrupt(ZC_PIN), zero_crosss_int, RISING);  // Choose the zero cross interrupt # from the table above
//}
//
//// the interrupt function must take no parameters and return nothing
//void zero_crosss_int()  // function to be fired at the zero crossing to dim the light
//{
//  Serial.println("zero_crosss_int triggered");
//  // Firing angle calculation : 1 full 50Hz wave =1/50=20ms
//  // Every zerocrossing thus: (50Hz)-> 10ms (1/2 Cycle) For 60Hz => 8.33ms (10.000/120)
//  // 10ms=10000us
//  // (10000us - 10us) / 128 = 75 (Approx) For 60Hz =>65
//
//  int dimtime = (75*dimming);    // For 60Hz =>65
//  delayMicroseconds(dimtime);    // Off cycle
//  digitalWrite(AC_LOAD, HIGH);   // triac firing
//  delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
//  digitalWrite(AC_LOAD, LOW);    // triac Off
//}
//
//void loop()  {
//  Serial.println("loop");
//  for (int i=5; i <= 120; i++){  // We use 120 as the lowest and 5 as the highest brightness setting. May be adjusted depending on the lamp used.
//    dimming=i;
//    delay(20);
//   }
//  for (int i=120; i >= 5; i--){  // Same as above
//    dimming=i;
//    delay(20);
//   }
//}
