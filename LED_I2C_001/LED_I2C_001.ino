#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
 
// set the LCD address to 0x27 for a 16 chars 2 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup() {
  Serial.begin(9600);  // Used to type in characters
  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("5tronix I2C LCD"); // Print text on second line
}

void loop() {
}
