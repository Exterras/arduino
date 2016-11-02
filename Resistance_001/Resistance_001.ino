#include <LiquidCrystal.h>

int resistance;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, OUTPUT);
  lcd.begin(16, 2);
}

void lcd_Display(int _delay){
  resistance = analogRead(A1);
  lcd.clear();
  lcd.print(resistance); 
  Serial.println(resistance);
  delay(_delay); 
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd_Display(1000);
}


