// 초음파센서의 Trig, Echo 핀을 매크로 상수로 선언합니다. #define TRIG 2
#define TRIG 2
#define ECHO 3

void setup(){
  Serial.begin(9600);
    
  // 초음파센서의 Trig를 출력 모드로 설정합니다. 
  pinMode(TRIG, OUTPUT);
  // 초음파센서의 Echo를 입력 모드로 설정합니다. 
  pinMode(ECHO, INPUT);
}

void loop(){
  // 다음은 초음파센서의 Trig에서 초음파를 발사하는 코드입니다. 
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIG, LOW);
  // pulseIn명령어를 통해 Echo핀에 초음파가 들어오는 시간을 계산합니다. 
  // pulseIn에서 반환된 값에 58.2를 나눈 이유는 시간을 cm로 변경하기 위해서입니다. 
  long distance = pulseIn(ECHO, HIGH)/58.2;

  Serial.println(distance);
  delay(1000);  
}
