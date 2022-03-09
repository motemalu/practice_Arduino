#include<Servo.h>
const int SW_pin = 0;
const int Y_pin = A1;

Servo myservo;

int va1;

void setup() {
  myservo.attach(9);
  // put your setup code here, to run once:

}

void loop() {
  va1=analogRead(Y_pin);
  va1=map(va1,0,1023,0,180);
  myservo.write(va1);
  delay(15);
  // put your main code here, to run repeatedly:

}
