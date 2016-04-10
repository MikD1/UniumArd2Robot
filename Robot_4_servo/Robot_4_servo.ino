#include <Servo.h>

Servo HeadServo;

void setup()
{
  HeadServo.attach(9);
}

void loop()
{
  HeadServo.write(0);
  delay(500);
  HeadServo.write(45);
  delay(500);
  HeadServo.write(90);
  delay(500);
  HeadServo.write(135);
  delay(500);
  HeadServo.write(180);
  delay(500);
}

