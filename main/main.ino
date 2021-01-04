/* Author: Nabil Mansour
Date: 2020-12-19
Description:
Performs the parallel parking operation for Arduino Car
as requested in CPS 607 final assignment */

#include <Servo.h>
#include <NewPing.h>
#include "header.h"

NewPing sonar(trigPin, echoPin, 350);
Servo servo;

void setup()
{
  // Defining right wheel pinMode
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Defining left wheel pinMode
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Defining line reader pinMode
  pinMode(LRR, INPUT);
  pinMode(LRM, INPUT);
  pinMode(LRL, INPUT);

  // Attaching the servo
  servo.attach(3);

  EnableMotor(MAX_SPEED, MAX_SPEED);
}

void loop()
{
  ParallelPark();
  servo.write(90);
}

float distance_1 = 0;
float distance_2 = 0;
unsigned long time = 0;

void ParallelPark()
{
  // #1
  servo.write(0);
  EnableMotor(0, 0);
  delay(250);

  EnableMotor(MIN_SPEED, MIN_SPEED);
  Move(true);
  while (distance_1 < 20)
  {
    Update_distance_1();

  }

  // #2
  EnableMotor(0, 0);
  delay(250);

  EnableMotor(MIN_SPEED, MIN_SPEED);
  Move(true);
  while (distance_1 > 20)
  {
    Update_distance_1();
  }

  // #3
  EnableMotor(0, 0);
  delay(250);

  EnableMotor(MIN_SPEED, MIN_SPEED);
  Move(false);
  while (distance_1 < 20)
  {
    Update_distance_1();
  }

  // #4
  servo.write(180);
  EnableMotor(0, 0);
  delay(250);

  EnableMotor(MAX_SPEED, MAX_SPEED);
  Rotate(true);
  distance_1 = 100;
  while (distance_1 > 20)
  {
    Update_distance_1();
  }

  // #5
  Rotate(false);
  delay(100);

  // #6
  EnableMotor(MIN_SPEED, MIN_SPEED);
  Move(true);
  while (LRL && LRM && LRR);
  while (!(LRL && LRM && LRR));

  // #7
  EnableMotor(0, 0);
  delay(250);

  EnableMotor(MAX_SPEED, MAX_SPEED);
  Rotate(false);
  while (LRL && LRM && LRR);

  // Check if properly in parallel
  do
  {
    EnableMotor(0, 0);
    servo.write(80);
    distance_2 = (sonar.ping() / 2) * 0.0343;
    delay(250);
    servo.write(100);
    distance_1 = (sonar.ping() / 2) * 0.0343;
    delay(100);

    if (abs(distance_1 - distance_2) > 0.001)
    {
      EnableMotor(MAX_SPEED, MAX_SPEED);
      if (distance_2 > distance_1)
      {
        Rotate(true);
      }
      else
      {
        Rotate(false);
      }
      delay(25);
    }
    EnableMotor(0, 0);
    servo.write(80);
    distance_2 = (sonar.ping() / 2) * 0.0343;
    delay(250);
    servo.write(100);
    distance_1 = (sonar.ping() / 2) * 0.0343;
    delay(100);
  } while (abs(distance_1 - distance_2) > 0.001);

  // #8
  EnableMotor(0, 0);
  while (1);
}

void Update_distance_1()
{
  if (millis() - time > 29)
  {
    distance_1 = (sonar.ping() / 2) * 0.0343;
    time = millis();
  }
}

void EnableMotor(int speedAmountA, int speedAmountB)
{
  /*
     Enables or disables and sets the speed for each wheel.
  */
  analogWrite(ENA, speedAmountA);
  analogWrite(ENB, speedAmountB);
}

void Rotate(bool dir)
{
  /*
     Rotates the car. If dir is true, then the car rotates clockWise; otherwise, counterClockWise.
  */
  if (dir)
  { // If clockWise
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW); //RFWD

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW); //LBWD
  }

  else
  { // If counterClockWise
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH); //RBWD

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH); //LFWD
  }
}

void Move(bool dir)
{
  /*
    Moves the car forwards if dir is true, backwards otherwise.
  */
  if (dir)
  { // If forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW); //RFWD

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH); //LFWD
  }
  else
  { // If backwards
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH); //RBWD

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW); //LBWD
  }
}
