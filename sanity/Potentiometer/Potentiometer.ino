const int POT_PIN = A1;

void setup()
{
  Serial.begin(115200);
  pinMode(POT_PIN, INPUT);
}

void loop()
{
  int val = analogRead(POT_PIN); // read the value from the sensor
  Serial.println(val);
  // Serial.println(map(val, 5, 1024, 10, 300));

  delay(50);
}
