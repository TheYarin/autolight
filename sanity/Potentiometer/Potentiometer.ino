const int POT_PIN = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int val = analogRead(POT_PIN);    // read the value from the sensor
  Serial.println(map(val, 5, 1024, 10, 300));

  delay(50);
}