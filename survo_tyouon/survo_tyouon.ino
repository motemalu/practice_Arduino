#include<Servo.h>

Servo myservo;
#define PIN 8
#define TRG 12
#define ECH 11
#define HIGHTIME 10
int loopdis = 100;
int newloopdis = 100;

void setup() {
  myservo.attach(10);
  myservo.write(30);
  pinMode(TRG,OUTPUT);
  pinMode(ECH,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  myservo.write(30);
  for(int i=30;i<=150;i++){
    myservo.write(i);
    delay(5);
    loopdis = measure();
    if(loopdis<10){
      while(true){
        tone(PIN,445,50);
        newloopdis = measure();
        if(newloopdis > 10){
          break;
          }
        }
      }
    }
  for(int i=150;i>=30;i--){
    myservo.write(i);
    delay(5);
    loopdis = measure();
    if(loopdis<10){
      while(1){
        tone(PIN,445,50);
        newloopdis = measure();
        if(newloopdis > 10){
          break;
          }
        }
      }
    }
    
    
  // put your main code here, to run repeatedly:

}

float measure(){
  int diff;
  float dis;
  digitalWrite(TRG,HIGH);
  delayMicroseconds(10);

  digitalWrite(TRG,LOW);

  diff = pulseIn(ECH,HIGH);
  dis = (float)diff*0.0175;
  return dis;
}
