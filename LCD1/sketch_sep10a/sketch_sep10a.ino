#include<LiquidCrystal.h>

LiquidCrystal lcd(9,8,A0,A1,A2,A3);

void setup() {
  lcd.begin(16,2);
  // put your setup code here, to run once:

}

void loop() {

  lcd.setCursor(0,0);
  lcd.print("0123456789ABCDEF");
  lcd.setCursor(0,1);
  lcd.print("0123456789abcdef");
  // put your main code here, to run repeatedly:

}
