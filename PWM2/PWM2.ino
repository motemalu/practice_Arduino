const int LED =9;
const int BUTTON =7;

int va1 =0;
int old_va1 =0;
int state =0;

int brightness =128;
unsigned long startTime =0;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  va1 = digitalRead(BUTTON);

  if((va1 == HIGH)&&(old_va1 == LOW)){
    state = 1-state;
    startTime = millis();


    delay(10);
    }

    if((va1 == HIGH)&&(old_va1 == HIGH)){
      if(state == 1 && (millis()-startTime)>500){
        brightness++;
        delay(10);
        if(brightness > 255){
          brightness = 0;
          }
        }
      }

      old_va1 = va1;

      if(state == 1){
        analogWrite(LED,brightness);
        }else{
          analogWrite(LED,0);
          }
  // put your main code here, to run repeatedly:

}
