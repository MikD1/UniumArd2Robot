#include <NewPing.h>
#include <Servo.h>

int ENA = 3;
int IN1 = 2;
int IN2 = 4;
int ENB = 6;
int IN3 = 5;
int IN4 = 7;

NewPing sonar(11, 10);
Servo HeadServo;

int ServoDelay = 700;
int DistanceDelta = 2;
int CorrectTime = 100;
int TurnTime = 300;
int StepDelay = 100;

int Distance = 0;

void setup()
{
  delay(3000);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  HeadServo.attach(9);

  Serial.begin(9600);

  CalculateDistance();
  TurnHeadLeft();
  EnableMotors(255, 255);
  MoveForward();
}

void loop()
{
  int value = GetSonarValue();

  if (value > Distance * 2)
  {
    TurnLeft();
  }

  if (value < Distance - DistanceDelta)
  {
    CorrectRight();
  }

  if (value > Distance + DistanceDelta)
  {
    CorrectLeft();
  }

  delay(StepDelay);
}

void CalculateDistance()
{
  TurnHeadLeft();
  int leftDistance = sonar.ping_cm();

  TurnHeadRight();
  int rightDistance = sonar.ping_cm();

  Distance = (leftDistance + rightDistance) / 2;

  Serial.print("Distance = ");
  Serial.println(Distance);
}

int GetSonarValue()
{
  int value = sonar.ping_cm();
  Serial.print("value = ");
  Serial.println(value);

  return value;
}

void CorrectLeft()
{
  Serial.println("CorrectLeft");

  EnableMotors(100, 255);
  delay(CorrectTime);
  EnableMotors(255, 255);
}

void CorrectRight()
{
  Serial.println("CorrectRight");

  EnableMotors(255, 100);
  delay(CorrectTime);
  EnableMotors(255, 255);
}

void EnableMotors(int motorASpeed, int motorBSpeed)
{
  analogWrite(ENA, motorASpeed);
  analogWrite(ENB, motorBSpeed);
}

void StopMotors()
{
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

void MoveForward()
{
  Serial.println("MoveForward");

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void TurnLeft()
{
  Serial.println("TurnLeft");

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(TurnTime);

  MoveForward();
  delay(StepDelay);
}

void TurnRight()
{
  Serial.println("TurnRight");

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(TurnTime);

  MoveForward();
  delay(StepDelay);
}

void TurnHeadLeft()
{
  HeadServo.write(0);
  delay(ServoDelay);
}

void TurnHeadRight()
{
  HeadServo.write(180);
  delay(ServoDelay);
}

void TurnHeadFront()
{
  HeadServo.write(90);
  delay(ServoDelay);
}

