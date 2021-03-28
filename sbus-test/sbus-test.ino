// The Arduino Pro Mini is a simple & cheap board, ideal for leaving inside of
// your model. It only has a single Serial port, and the default SBUS code
// doesn't run on it. You can get it to work by not using the timer, but that
// means you can't use delay in the loop() function anymore.

#include <SBUS.h>
#include <Servo.h>

SBUS sbus(Serial);

Servo servoCyc1;

void setup()
{
  sbus.begin(false);
  servoCyc1.attach(3);
}

void loop()
{
  sbus.process();
  int value = sbus.getChannel(1);
  servoCyc1.writeMicroseconds(value / 8);
}
