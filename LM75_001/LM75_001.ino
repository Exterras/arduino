#include <LiquidCrystal.h>
#include <Wire.h>
#include <LM75.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
LM75 sensor; 

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void lcd_Display(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(sensor.temp());
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

void loop() {
  lcd_Display();
  serial_Moniter();
  sensorFunc(false);
  delayFunc(1000);
}
