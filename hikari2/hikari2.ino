const int LED = 9;
int va1 = 0;

void setup() {
  pinMode(LED,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  va1 = analogRead(0);

  analogWrite(LED, va1/4);
  delay(10);
  // put your main code here, to run repeatedly:

}
