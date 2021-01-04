#ifndef HEADER_H
#define HEADER_H

// Defining Motors
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define MAX_SPEED 190
#define MIN_SPEED 110

// Defining LineReader
#define LRR digitalRead(10)
#define LRM digitalRead(4)
#define LRL digitalRead(2)

// Defining servo
#define trigPin A5
#define echoPin A4

void EnableMotor(int speedAmountA, int speedAmountB);

void Rotate(bool dir);

void Move(bool dir);

#endif // HEADER_H

