#include<LiquidCrystal.h>

LiquidCrystal lcd(9,8,A0,A1,A2,A3);

void setup() {
  lcd.begin(16,2);
  // put your setup code here, to run once:

}

void loop() {

  lcd.print("LCD");
  

  while(1){
    lcd.blink();
    delay(1000);
    lcd.noBlink();
    delay(1000);
    }
  // put your main code here, to run repeatedly:
}
