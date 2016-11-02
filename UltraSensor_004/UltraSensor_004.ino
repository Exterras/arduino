#include <LiquidCrystal.h>

// 초음파센서의 Trig, Echo 핀을 매크로 상수로 선언합니다. #define TRIG 2
#define TRIG 2
#define ECHO 3
long distance;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
// initialize the library with the numbers of the interface pins

void setup(){
  Serial.begin(9600);
    
  // 초음파센서의 Trig를 출력 모드로 설정합니다. 
  pinMode(TRIG, OUTPUT);
  // 초음파센서의 Echo를 입력 모드로 설정합니다. 
  pinMode(ECHO, INPUT);
  // set up the LCD's number of columns and rows
  
  lcd.begin(16, 2);
}

void title(){
  lcd.setCursor(0, 0);
  lcd.print("Ultrasonic");
}

void ultraSensor(float _distanceTrans){
    // 다음은 초음파센서의 Trig에서 초음파를 발사하는 코드입니다. 
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIG, LOW);
  // pulseIn명령어를 통해 Echo핀에 초음파가 들어오는 시간을 계산합니다. 
  // pulseIn에서 반환된 값에 58.2를 나눈 이유는 시간을 cm로 변경하기 위해서입니다. 
  distance = pulseIn(ECHO, HIGH)/_distanceTrans;
}

void lcd_Display(){
  lcd.clear();
  title();
  lcd.print("Dist. : ");
  lcd.print(distance); 
  lcd.print(" cm");
}

void lcd_DisplayMod(int _delay, int _abnormalValue){
  lcd.clear();
  title();
  lcd.setCursor(0, 1);
  lcd.print("Dist. : ");
  
  if(distance > _abnormalValue){
    lcd.print("abnormal");
  } else {
    lcd.print(distance);
  }
  
  lcd.print(" cm");

  Serial.println(distance);
  delay(_delay); 
}

void loop(){
  ultraSensor(58.2);
//  lcd_Display();
  lcd_DisplayMod(250,2000);
}
