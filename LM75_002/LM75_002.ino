#include <LiquidCrystal.h>
#include <Wire.h>
#include <LM75.h>
#include <stdio.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
LM75 sensor; 

#define BLUE 2
#define RED 3
#define GREEN 4

void setup() {
  // put your setup code here, to run once:

  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  Wire.begin();
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void lcdClear(){
  lcd.clear();
}

void lcdTitle(String _str, int _startPoint){
  lcd.setCursor(_startPoint, 0);
  lcd.print(_str);
}

void lcd_Display(int _startPoint){
  float tempe = (float)sensor.temp();
  lcd.setCursor(_startPoint, 1);
  
  lcd.print("Temp: ");
  lcd.print(tempe);
  lcd.print("C");
}
void serial_Moniter(){
  Serial.print("Current temp: ");
  Serial.print(sensor.temp());
  Serial.println(" C");
}

void sensorFunc(boolean _binary){
  sensor.shutdown(_binary);
}

void delayFunc(int _delay){
  delay(_delay);
}

void ledLight(int _stdTemp){
  if(sensor.temp() < _stdTemp){
    digitalWrite(BLUE, HIGH);
  } else if(sensor.temp() >= _stdTemp && sensor.temp() <= (_stdTemp+10)){
    digitalWrite(GREEN, HIGH);
  } else {
    digitalWrite(RED, HIGH);
  }
}

void loop() {
  lcdClear();
  lcdTitle("Thermometer", 2);
  lcd_Display(0);
  serial_Moniter();
  sensorFunc(false);
  delayFunc(1000);
  ledLight(18);
}
