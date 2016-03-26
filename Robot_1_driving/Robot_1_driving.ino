int ENA = 3;
int IN1 = 2;
int IN2 = 4;
int ENB = 6;
int IN3 = 5;
int IN4 = 7;

void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  EnableMotors(255, 255);
  MoveForward(1000);
  MoveBackward(1000);
  MoveClockwise(500);
  MoveCounterclockwise(500);
  StopMotors();

  delay(5000);
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

void MoveForward(int duration)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(duration);
}

void MoveBackward(int duration)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(duration);
}

void MoveClockwise(int duration)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(duration);
}

void MoveCounterclockwise(int duration)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(duration);
}
