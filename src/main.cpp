#include <Arduino.h>
#include "encoders.h"
#include "motors.h"
void setup()
{
  Serial.begin(9600);
  setupEncoders();
}

void loop()
{
  move_one_cell();
  delay(1000);
}