#define BLYNK_PRINT Serial  // BLYNKの詳細情報を表示するか否か

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPL5oyoJ1qD"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "8le8asDz7YJJOoBZ_HqCT-ndPWPbMrgx"

#include<Servo.h>

char auth[] = BLYNK_AUTH_TOKEN;

/* Ethernet LIBRARY */
#include <Ethernet.h>            // Ethernet
#include <BlynkSimpleEthernet.h> // BlynkサーバのEthernet

const int motionPin = 2; // PIR sensor pin
int buzzer = 5; //Buzzer pin

int motionStatus = 0; // Motion detected status
int rad = 0; //servo 角度
unsigned int time = 0;//millis()で数える時間1
int signal = 0;
int flag = 1;
int count = 0;
unsigned int time2 = 0;//millis()で数える時間1
Servo myservo;//serovo
 
void setup() {
    pinMode(motionPin, INPUT); //PIR sensor pin 設定
    pinMode(buzzer,OUTPUT); //Buzzer pin 設定
    myservo.attach(6);//servopin
    Serial.begin(9600);  // Serialの初期設定
    Blynk.begin(auth);   // Blynkの初期設定
}
 
void loop() {
    Blynk.run();//Blynkプログラムを動作
    myservo.write(rad); //servo 動作
    motionStatus = digitalRead(motionPin);//人感センサの値を読む
   
    //信号安定
    if (motionStatus == HIGH){
      time = millis();
      signal = 1;
      flag = 1;
      if(count == 0){
        count = 1;
      }
      Serial.println("Motion detected."); 
    }   
    //millis() - time が５秒以上のときsignal off
    else if((millis() - time) > 5000 && flag == 1){
      signal = 0;
      Serial.println("signal off."); 
    }
    //signal on のときブザー鳴る
    if(signal == 1){
      tone(buzzer,523);
      Serial.println("signal on."); // Print motion detected message
    }
    //signal offのときブザー鳴らない＆フラグ0
    else if(signal == 0){
      noTone(buzzer);
      flag = 0;
      Serial.println("All clear."); // Print all clear message
    }

    //窓開け感覚
    if (count == 1){
       time2 = millis();
       count = 2;
    }
    //感知して10秒たったらサーボ回転180
    else if ((millis() - time2) > 10000 && count == 2){
      rad=180;
      myservo.write(rad);
      time2 = millis();
      count = 3;
    }
    //サーボ回転して5秒たったらサーボ回転0
    else if ((millis() - time2 > 5000) && count == 3){
      rad = 0;
      myservo.write(rad);
      count = 0;
    }
    delay(100);
}
void sendSensor(){
  //int r = signal; 
  //Blynk.virtualWrite(V0, r);
  Blynk.virtualWrite(V0, count);         
}
