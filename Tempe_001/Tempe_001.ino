#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int analogVCC = 17;
int analogSGN = 18;
int analogGND = 19;

void setup() {
  lcd.begin(16, 2);
  
  pinMode(analogVCC, OUTPUT);
  pinMode(analogGND, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  
  digitalWrite(analogVCC, HIGH);
  digitalWrite(analogGND, LOW);

  int adc = analogRead(A4);
  lcd.print(adc);
  delay(1000);
}
