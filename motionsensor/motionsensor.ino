#define BLYNK_PRINT Serial  // BLYNKの詳細情報を表示するか否か

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPL5oyoJ1qD"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "8le8asDz7YJJOoBZ_HqCT-ndPWPbMrgx"

char auth[] = BLYNK_AUTH_TOKEN;

/* Ethernet LIBRARY */
#include <Ethernet.h>            // Ethernet
#include <BlynkSimpleEthernet.h> // BlynkサーバのEthernet


#include<Servo.h>
unsigned int buzzer1[8]={261,293,329,349,391,440,493,523};
unsigned char count = 0;


int motionPin = 2; // PIR sensor pin
int buzzer = 5;
int motionStatus = 0; // Motion detected status
 
void setup() {
    pinMode(motionPin, INPUT);
    pinMode(buzzer,OUTPUT);
    Serial.begin(9600);  // Serialの初期設定
    Blynk.begin(auth);   // Blynkの初期設定
}
 
void loop() {
    Blynk.run();//Blynkプログラムを動作
    motionStatus = digitalRead(motionPin);
    if (motionStatus == HIGH) { // When motion is detected
        tone(buzzer,buzzer1[count]);
        count++;
        if(count>7)
          count = 0;
         while(digitalRead(motionStatus) == 1);
        Serial.println("Motion detected."); // Print motion detected message
        delay(1000);
    }
    else {
        noTone(buzzer);
        Serial.println("All clear."); // Print all clear message
        delay(1000);
    }
}
