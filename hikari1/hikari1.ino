const int LED = 13;
int va1 = 0;

void setup() {
  pinMode(LED,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  va1 = analogRead(0);

  digitalWrite(13,HIGH);
  delay(va1);

  digitalWrite(13,LOW);
  delay(va1);
  // put your main code here, to run repeatedly:

}
