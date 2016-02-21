/*
 * http://playground.arduino.cc/Code/NewPing
 */

#include <NewPing.h>

NewPing sonar(3, 2);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int value = sonar.ping();
  Serial.println(value);
  delay(500);
}

