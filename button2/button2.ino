const int LED = 13;
const int BUTTON = 7;

int val = 0;
int state = 0;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  val = digitalRead(BUTTON);

  if (val == HIGH){
    state=1-state;
    }

    if (state == 1){
      digitalWrite(LED,HIGH);
      }else{
        digitalWrite(LED,LOW);
        }
  // put your main code here, to run repeatedly:

}
