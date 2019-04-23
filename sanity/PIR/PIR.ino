const int PIR_PIN = D5;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  int val = digitalRead(PIR_PIN);    // read the value from the sensor
  Serial.println(val);

  delay(300);
}
