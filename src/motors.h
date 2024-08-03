#pragma once
#include <SparkFun_TB6612.h>

#define AIN1 4
#define BIN1 7
#define AIN2 6
#define BIN2 8
#define PWMA 5
#define PWMB 9
#define STBY 13

const int offsetA = 1;
const int offsetB = 1;

Motor motor_left = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor_right = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
int speed = 100;

void move_one_cell()
{
    resetEncoders();
    while (encoderPosition() <= 100)
    {
        back(motor_left, motor_right, speed);
    }
    resetEncoders();
    brake(motor_left,motor_right);
}