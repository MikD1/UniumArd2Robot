int ENA = 6;
int IN1 = 7;
int IN2 = 8;
int ENB = 11;
int IN4 = 10;
int IN3 = 9;

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
  EnableMotors();
  MoveForward(1000);
  MoveBackward(1000);
  MoveClockwise(500);
  MoveCounterclockwise(500);
  StopMotors();

  delay(5000);
}

void EnableMotors()
{
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
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
