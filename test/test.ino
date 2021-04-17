// The Arduino Pro Mini is a simple & cheap board, ideal for leaving inside of
// your model. It only has a single Serial port, and the default SBUS code
// doesn't run on it. You can get it to work by not using the timer, but that
// means you can't use delay in the loop() function anymore.

#include <Servo.h>


Servo servoCyc1;
int signal = 1500;
void setup()
{
  servoCyc1.attach(3);
  pinMode(5, INPUT);
}

void loop()
{

  int in = digitalRead(5);
  if (in == HIGH) {
      if (signal < 1520) {
        signal += 1;
      }
      servoCyc1.writeMicroseconds(signal);
  }else {
      servoCyc1.writeMicroseconds(1500);
  }
}
