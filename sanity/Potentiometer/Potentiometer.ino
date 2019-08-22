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

  delay(50);
}
