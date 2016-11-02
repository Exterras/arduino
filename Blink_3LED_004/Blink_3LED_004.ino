
int inputPin[] = {2, 3, 4, 5};
int outputPin[] = {8, 9, 10};

int switchCon = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(inputPin[0], INPUT_PULLUP);
  pinMode(inputPin[1], INPUT_PULLUP);
  pinMode(inputPin[2], INPUT_PULLUP);
  pinMode(inputPin[3], INPUT_PULLUP);
  
  pinMode(outputPin[0], OUTPUT);
  pinMode(outputPin[1], OUTPUT);
  pinMode(outputPin[2], OUTPUT);

  digitalWrite(outputPin[0], HIGH);
  digitalWrite(outputPin[1], HIGH);
  digitalWrite(outputPin[2], HIGH);
}

void outputMethod(int a, int b, int c){
  digitalWrite(outputPin[0], a);
  digitalWrite(outputPin[1], b);
  digitalWrite(outputPin[2], c);
}

void switchOn(int a, int b, int c, int d){
  if(switchCon == 0 && digitalRead(a) == LOW){
    outputMethod(LOW,HIGH,HIGH);
    } // else if (digitalRead(b) == LOW){
//    outputMethod(HIGH,LOW,HIGH);
//  } else if (digitalRead(c) == LOW){
//    outputMethod(HIGH,HIGH,LOW);
//  } else if (digitalRead(d) == LOW){
//    outputMethod(LOW,LOW,LOW);
//  } else {
////    outputMethod(HIGH,HIGH,HIGH);
//  }
    switchCon = 1;
}

void switchOff(int a, int b, int c, int d){
  if(switchCon == 1 && digitalRead(a) == LOW){
    outputMethod(HIGH,HIGH,HIGH);
  } //else if (digitalRead(b) == LOW){
//    outputMethod(HIGH,LOW,HIGH);
//  } else if (digitalRead(c) == LOW){
//    outputMethod(HIGH,HIGH,LOW);
//  } else if (digitalRead(d) == LOW){
//    outputMethod(LOW,LOW,LOW);
//  } else {
//    outputMethod(HIGH,HIGH,HIGH);
//  }
    switchCon = 0;
}

// the loop function runs over and over again forever
void loop() {
  switchOn(inputPin[0], inputPin[1], inputPin[2], inputPin[3]);
  switchOff(inputPin[0], inputPin[1], inputPin[2], inputPin[3]);
}
