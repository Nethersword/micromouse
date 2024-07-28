#include <Arduino.h>
#include "encoders.h"

void setup()
{
  Serial.begin(9600);
  setupEncoders();
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.print(getLeftCount());
  Serial.print(" ");
  Serial.println(getRightCount());
}