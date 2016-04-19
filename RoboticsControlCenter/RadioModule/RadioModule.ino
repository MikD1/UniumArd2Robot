/*
 * Pins:
 * MISO -> 12
 * MOSI -> 11
 * SCK  -> 13
 * CE   -> 8
 * CSN  -> 7
*/

#include <RadioSimple.h>

int led = 2;
Radio radio("pult1", 2);

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  Blink(1);
}

void loop()
{
  SerialHandle();
  delay(100);
}

void SerialHandle()
{
  if (Serial.available())
  {
    byte data[1];
    Serial.readBytes(data, 1);

    //Blink(data[0]);
    radio.sendValue("robo1", data[0]);
  }
}

void Blink(int count)
{
  for (int i = 0; i < count; i = i + 1)
  {
    digitalWrite(led, HIGH);
    delay(300);
    digitalWrite(led, LOW);
    delay(300);
  }
}

