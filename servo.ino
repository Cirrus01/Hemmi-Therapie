
#include "Servo.h"

#define MIN_THR_ANGLE    80
#define MAX_THR_ANGLE    100
#define MIN_ANGLE        70
#define MID_ANGLE        90
#define MAX_ANGLE        110

int servo_in = 2;
float pos;
int a_pos = 0;
unsigned long t_start, t_stop, t_pulse = 0;
//volatile int state = LOW;
Servo myservo;

void setup() {
  pinMode(servo_in, INPUT);
  myservo.attach(9);
}

void loop() {
  //a_pos = pos;
  t_pulse = pulseIn(servo_in, HIGH, 2400);
  if (t_pulse > 0)
  {
    if (t_pulse < 700)
      t_pulse = 700;
    Serial.println(t_pulse);
    pos = ((t_pulse - 700) / 1500.0) * 180.0;
    a_pos = abs(pos);
    Serial.println(pos);

    if(a_pos < MIN_THR_ANGLE)
       a_pos = MIN_ANGLE;
    else if(a_pos > MAX_THR_ANGLE)
       a_pos = MAX_ANGLE;
    else
       a_pos = MID_ANGLE;
 
    if ( pos != a_pos)
      myservo.write(a_pos);
  }
}
