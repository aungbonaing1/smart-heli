// The Arduino Pro Mini is a simple & cheap board, ideal for leaving inside of
// your model. It only has a single Serial port, and the default SBUS code
// doesn't run on it. You can get it to work by not using the timer, but that
// means you can't use delay in the loop() function anymore.

#include <SBUS.h>
#include <Servo.h>
#include <math.h>

SBUS sbus(Serial);

Servo servoCyc1;
Servo servoCyc2;
Servo servoCyc3;

float ele;
float ail;
float thr;
float col;

void setup()
{
  sbus.begin(false);
  servoCyc1.attach(10);
  servoCyc2.attach(11);
  servoCyc3.attach(12);
}

void loop()
{
  sbus.process();
  ail = sbus.getChannel(1);
  ele = sbus.getChannel(2);
  thr = sbus.getChannel(3);
  col = sbus.getChannel(6);
  
  float signalCyc1 = col - ele;
  float signalCyc2 = col + 0.5 * ele + 0.866 * ail;
  float signalCyc3 = col + 0.5 * ele - 0.866 * ail;

  servoCyc1.writeMicroseconds(signalCyc1);
  servoCyc2.writeMicroseconds(signalCyc2);
  servoCyc3.writeMicroseconds(signalCyc3);
}
