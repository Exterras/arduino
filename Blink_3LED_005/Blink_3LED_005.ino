
int inputPin[] = {2, 3, 4, 5};
int outputPin[] = {8, 9, 10};
int switchCon = 0;
// 입력핀과 출력핀을 각각 inputPin, outputPin 배열로 지정하였다.
// 한번 누르면 불이 켜지고 다시 한번 켜지면 불이 꺼지겠금 불의 상태를 확인하는 변수 switchCon 을 0으로 초기화했다.

int buzzerPin = 6;

void setup() {
  pinMode(inputPin[0], INPUT_PULLUP);
  pinMode(inputPin[1], INPUT_PULLUP);
  pinMode(inputPin[2], INPUT_PULLUP);
  pinMode(inputPin[3], INPUT_PULLUP);
  
  pinMode(outputPin[0], OUTPUT);
  pinMode(outputPin[1], OUTPUT);
  pinMode(outputPin[2], OUTPUT);

  pinMode(buzzerPin, OUTPUT);
  
  digitalWrite(outputPin[0], HIGH);
  digitalWrite(outputPin[1], HIGH);
  digitalWrite(outputPin[2], HIGH);
}
// 처음 실행했을 때 최초 실행되는 함수
// 입력핀과 출력핀을 pinMode 함수를 통하여 설정하였으며 최초 실행시 모든 불이 꺼지도록 설계하였다.

void outputMethod(int a, int b, int c){
  digitalWrite(outputPin[0], a);
  digitalWrite(outputPin[1], b);
  digitalWrite(outputPin[2], c);
}
// 3색 led 

void buzzerMethod(int buzzerPin, int frequency, int miliSec, int delaySec){
  tone(buzzerPin, frequency, miliSec);
  delay(delaySec);
}

void switchOn(int a, int b, int c, int d){
  if(switchCon == 0){
    if(digitalRead(a) == LOW){
      outputMethod(LOW,HIGH,HIGH);
    } else if (digitalRead(b) == LOW){
      outputMethod(HIGH,LOW,HIGH);
    } else if (digitalRead(c) == LOW){
      outputMethod(HIGH,HIGH,LOW);
    } else if (digitalRead(d) == LOW){
      outputMethod(LOW,LOW,LOW);
      buzzerMethod(buzzerPin, 500, 1000, 2000);
    } else {
    }
    switchCon = 1;
  } else { 
  }
}

void switchOff(int a, int b, int c, int d){
    if(switchCon == 1){
      if(digitalRead(a) == LOW || digitalRead(b) == LOW || digitalRead(c) == LOW || digitalRead(d) == LOW){
        outputMethod(HIGH,HIGH,HIGH);
      } else {
      }
      switchCon = 0;
    } else {
    } 
}


// the loop function runs over and over again forever
void loop() {
  switchOn(inputPin[0], inputPin[1], inputPin[2], inputPin[3]);
  switchOff(inputPin[0], inputPin[1], inputPin[2], inputPin[3]);  
  
}
