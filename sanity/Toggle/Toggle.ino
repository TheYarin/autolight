
const int TOGGLE_PIN = 5;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    int val = analogRead(TOGGLE_PIN); // read the value from the sensor
    // Serial.println(map(val, 5, 1024, 10, 300));
    Serial.println(val);

    int newval = val / 100;

    // Serial.println(newval);

    delay(50);
}
