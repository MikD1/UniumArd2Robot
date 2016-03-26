int sensorPin = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop()
{
  int value = digitalRead(sensorPin);
  Serial.println(value);
  delay(500);
}

