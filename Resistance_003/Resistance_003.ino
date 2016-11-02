#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int adc;
float volt;
int tempe;

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

int tempMethod(float _size){
  tempe = adcRead() * (_size/1023.0);
  return tempe;
}

void lcdClear(){
  lcd.clear();
}

void lcd_DisplayADC(int _adc){
  lcd.setCursor(0, 0);
  lcd.print("adc : ");
  lcd.print(_adc);
}

void lcd_DisplayVolt(float _volt){
  lcd.setCursor(0, 1);
  lcd.print("volt : ");
  lcd.print(_volt);
}

void lcd_DisplayTemp(int _tempa){
  lcd.setCursor(0, 1);
  lcd.print("temp : ");
  lcd.print(_tempa);
}

void serialPrintADC(int _adc){
  Serial.print("adc : ");
  Serial.println(_adc);
}

void serialPrintVolt(float _volt){
  Serial.print("volt : ");
  Serial.println(_volt);
}

void serialPrintTemp(int _tempe){
  Serial.print("temp : ");
  Serial.println(_tempe);
}

void loop() {
  int adcValue = adcRead();
  float voltValue = voltConverter();
  int tempeValue = tempMethod(50.0);
    
  lcdClear();
  lcd_DisplayADC(adcValue);
  //  lcd_DisplayVolt(voltValue);
  lcd_DisplayTemp(tempeValue);
  // lcd display 
  
  serialPrintADC(adcValue);
  serialPrintTemp(tempeValue); 
  // serial moniter
  
  delay(1000);
}
