#include <LiquidCrystal.h>
#include <Wire.h>
#include <LM75.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
LM75 sensor; 

#define BLUE 2
#define GREEN 3
#define RED 4

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

void lcd_TempeDisplay(int _startPoint){
  float tempe = (float)sensor.temp();
  lcd.setCursor(_startPoint, 1);
  
  lcd.print("Temp: ");
  lcd.print(tempe);
  lcd.print("C");
}

void serial_Moniter(String _str, String _celsius){
  Serial.print(_str);
  Serial.print(sensor.temp());
  Serial.println(_celsius);
}

void sensorFunc(boolean _binary){
    sensor.shutdown(_binary);
}

void delayFunc(int _delay){
  delay(_delay);
}

void ledLight(float _stdTemp){
  float tempe = (float)sensor.temp();
  
  if(tempe < _stdTemp){
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, LOW);
  } else {
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  }
}

void loop() {
  lcdClear(); // LCD is Clearing while information is changed.
  lcdTitle("Thermometer", 2); // Program Intro Display ("Title", startpoint)
  lcd_TempeDisplay(0); // LCD Tempereture Display (startpoint)
  serial_Moniter("Current temp: ", " C"); // LCD Tempereture Serial Display("Title", "Celsius")
  sensorFunc(false); // LM75 Sensor Activated = true
  delayFunc(1000); // delay time (ms)
  ledLight(18); // led activate function (standard light change celsius)
}