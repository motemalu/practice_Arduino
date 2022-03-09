const int SENSOR =0;
int va1 = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  va1= analogRead(SENSOR);

  Serial.println(va1);
  delay(100);
  
  // put your main code here, to run repeatedly:
 

 
}
