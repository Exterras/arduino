

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, INPUT_PULLUP);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);

  if(digitalRead(2) == LOW){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
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
