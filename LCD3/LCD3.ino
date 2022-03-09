#include<LiquidCrystal.h>

LiquidCrystal lcd(9,8,A0,A1,A2,A3);

int i = 0;

void setup() {
  lcd.begin(16,2);
  // put your setup code here, to run once:

}

void loop() {

  while(1){
    lcd.home();
    lcd.setCursor(15,0);
    lcd.rightToLeft();
    for(i=0;i<16;i++){
      lcd.write('a'+i);
      delay(250);
      }
      lcd.clear();
    }
  // put your main code here, to run repeatedly:

}
