// The Arduino Pro Mini is a simple & cheap board, ideal for leaving inside of
// your model. It only has a single Serial port, and the default SBUS code
// doesn't run on it. You can get it to work by not using the timer, but that
// means you can't use delay in the loop() function anymore.

#include <SBUS.h>
#include <Servo.h>
#include <math.h>
#include <LiquidCrystal.h>

SBUS sbus(Serial);

Servo servoCyc1;
Servo servoCyc2;
Servo servoCyc3;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

float ele;
float ail;
float thr;
float rud;
float col;

void setup()
{
  sbus.begin(false);
  servoCyc1.attach(10);
  servoCyc2.attach(11);
  servoCyc3.attach(12);
  lcd.begin(16, 2);
}

void loop()
{
  sbus.process();
  ail = map(sbus.getChannel(1), 172, 1810, 1000, 2000);
  ele = map(sbus.getChannel(2), 172, 1810, 1000, 2000);
  thr = map(sbus.getChannel(3), 172, 1810, 1000, 2000);
  rud = map(sbus.getChannel(4), 172, 1810, 1000, 2000);
  col = map(sbus.getChannel(6), 172, 1810, 1000, 2000); 
  
  float signalCyc1 =  col - ele;
  float signalCyc2 = col + 0.5 * ele + 0.866 * ail;
  float signalCyc3 = col + 0.5 * ele - 0.866 * ail;

  signalCyc1 = map(signalCyc1, -1000, 1000, 1000, 2000);
  signalCyc2 = map(signalCyc2, 2366, 4732, 1000, 2000);
  signalCyc3 = map(signalCyc3, -232.0, 2134.0, 2000, 1000);

  servoCyc1.writeMicroseconds(signalCyc1);
  servoCyc2.writeMicroseconds(signalCyc2);
  servoCyc3.writeMicroseconds(signalCyc3);

//  lcd.setCursor(0, 0);
//  lcd.print("c1:" + String(ail));
//  lcd.setCursor(8, 0);
//  lcd.print("c2:" + String(ele));
//  lcd.setCursor(0, 1);
//  lcd.print("c3:" + String(col));
//  lcd.setCursor(8, 1);
//  lcd.print("c4:" + String(signalCyc2));

  lcd.setCursor(0, 0);
  lcd.print("c1:" + String(ail));
  lcd.setCursor(8, 0);
  lcd.print("c2:" + String(signalCyc1));
  lcd.setCursor(0, 1);
  lcd.print("c3:" + String(signalCyc2));
  lcd.setCursor(8, 1);
  lcd.print("c4:" + String(signalCyc3));

//    servoCyc1.writeMicroseconds(ail);
//  servoCyc2.writeMicroseconds(ele);
//  servoCyc3.writeMicroseconds(col);
}
