#include<Servo.h>

Servo myservo;

int ledPin = 8; // LED output
int motionPin = 2; // PIR sensor pin
int motionStatus = 0; // Motion detected status
 
void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(motionPin, INPUT);
    myservo.attach(6);
    Serial.begin(9600);
}
 
void loop() {
    motionStatus = digitalRead(motionPin);
    if (motionStatus == HIGH) { // When motion is detected
        digitalWrite(ledPin, HIGH); // turn LED ON
        myservo.write(180);
        Serial.println("Motion detected."); // Print motion detected message
        delay(1000);
    }
    else {
        digitalWrite(ledPin, LOW); // Turn LED OFF if no motion is detected
        Serial.println("All clear."); // Print all clear message
        myservo.write(0);
        delay(1000);
    }
}
