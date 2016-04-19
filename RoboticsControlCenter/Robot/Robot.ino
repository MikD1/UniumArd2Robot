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
Radio radio("robo1", 2);

void setup()
{
  pinMode(led, OUTPUT);
  Blink(1);
}

void loop()
{
  RadioHandle();
  delay(100);
}

void RadioHandle()
{
  if (radio.available())
  {
    byte value = radio.receiveValue();
    Blink(value);
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
