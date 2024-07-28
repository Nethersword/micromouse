#include <util/atomic.h>

#define ENCODER_LEFT_C1 3
#define ENCODER_LEFT_C2 12
#define ENCODER_RIGHT_C1 2
#define ENCODER_RIGHT_C2 11

volatile int left_counts = 0;
volatile int right_counts = 0;

void readEncoderRight()
{
    int rc2 = digitalRead(ENCODER_RIGHT_C2);
    if (rc2 == 1)
    {
        right_counts++;
    }
    else
    {
        right_counts--;
    }
}
void readEncoderLeft()
{
    int c2 = digitalRead(ENCODER_LEFT_C2);
    if (c2 == 1)
    {
        left_counts++;
    }
    else
    {
        left_counts--;
    }
}
void setupEncoders()
{
    pinMode(ENCODER_LEFT_C1, INPUT);
    pinMode(ENCODER_LEFT_C2, INPUT);
    pinMode(ENCODER_RIGHT_C1, INPUT);
    pinMode(ENCODER_RIGHT_C2, INPUT);
    attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT_C1), readEncoderLeft, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCODER_RIGHT_C1), readEncoderRight, RISING);
}

int getLeftCount()
{
    int ct = 0;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
        ct = left_counts;
    }
    return ct;
}
int getRightCount()
{
    int ct = 0;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
        ct = right_counts;
    }
    return ct;
}