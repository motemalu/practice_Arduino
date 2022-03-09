unsigned long distance_time = 0;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(2,HIGH);
  delayMicroseconds(10);

  digitalWrite(2,LOW);

  distance_time = pulseIn(3,HIGH);

  Serial.print(distance_time/58);
  Serial.println("cm");

  delay(100);
  // put your main code here, to run repeatedly:

}
