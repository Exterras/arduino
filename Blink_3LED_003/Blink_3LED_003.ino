
int inputAPin = 2;
int inputBPin = 3;
int inputCPin = 4;
int inputDPin = 5;

int outputAPin = 8;
int outputBPin = 9;
int outputCPin = 10;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(inputAPin, INPUT_PULLUP);
  pinMode(inputBPin, INPUT_PULLUP);
  pinMode(inputCPin, INPUT_PULLUP);
  pinMode(inputDPin, INPUT_PULLUP);
  
  pinMode(outputAPin, OUTPUT);
  pinMode(outputBPin, OUTPUT);
  pinMode(outputCPin, OUTPUT);
}

void outputMethod(int a, int b, int c){
  digitalWrite(outputAPin, a);
  digitalWrite(outputBPin, b);
  digitalWrite(outputCPin, c);
}

// the loop function runs over and over again forever
void loop() {

  outputMethod(HIGH,HIGH,HIGH);

  if(digitalRead(inputAPin) == LOW){
    outputMethod(LOW,HIGH,HIGH);
  } else if (digitalRead(inputBPin) == LOW){
    outputMethod(HIGH,LOW,HIGH);
  } else if (digitalRead(inputCPin) == LOW){
    outputMethod(HIGH,HIGH,LOW);
  } else if (digitalRead(inputDPin) == LOW){
    outputMethod(LOW,LOW,LOW);
  } else {
    outputMethod(HIGH,HIGH,HIGH);
  }
  
//  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)]
//  digitalWrite(9, HIGH); 
//  digitalWrite(10, HIGH);
//  delay(1000);                       // wait for a second
//  
//  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
//  digitalWrite(9, LOW);
//  digitalWrite(10, LOW); 
//  delay(1000);                       // wait for a second

  
}
