#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int adc;
float volt;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, OUTPUT);
  lcd.begin(16, 2);
}

int adcRead(){
  adc = analogRead(A1);
  return adc;
}

float voltConverter(){
  volt = adcRead() * (5.0/1023.0);
  return volt;
}

void lcd_Display(int _adc, float _volt){
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("adc : ");
  lcd.println(_adc);
  
  lcd.setCursor(0, 1);
  lcd.print("volt : ");
  lcd.println(_volt);
}

void serialPrint(){
  Serial.print("adc : ");
  Serial.println(_adc);
  Serial.print("volt : ");
  Serial.println(_volt);
}

void loop() {
  // put your main code here, to run repeatedly:

  int adcValue = adcRead();
  float voltValue = voltConverter();
  
  lcd_Display(adcValue, voltValue);
  serialPrint();
  
  delay(1000);
}
