
#include "Servo.h"

int servo_in = 2;
int pos, a_pos = 0;
unsigned long t_start, t_stop, t_pulse = 0;
volatile int state = LOW;
Servo myservo;

void setup() {
     pinMode(servo_in, INPUT);
     attachInterrupt(digitalPinToInterrupt(servo_in), isr_start, RISING);
     attachInterrupt(digitalPinToInterrupt(servo_in), isr_stop, FALLING);
     myservo.attach(9);
 }
 
void loop() {
     a_pos = pos;
     pos = t_pulse/1000 * 180;

     if(pos < 80)
        pos = 76;
     else if(pos > 100)
        pos = 105;
     else
        pos = 90;

     if( pos != a_pos)
        myservo.write(pos);
 }
 
void isr_start() {
     t_start = micros();
 }

 void isr_stop() {
     t_stop = micros();
     t_pulse = t_stop - t_start;
 }
