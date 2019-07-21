int one = 2;
int two = 3;
int LOn = 9;
int LIN2 = 7;
int LIN1 = 8;
int ROn = 10;
int RIN4 = 11;
int RIN3 = 12;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(one,OUTPUT);
  pinMode(two,OUTPUT);
  pinMode(LOn,OUTPUT);
  pinMode(LIN2,OUTPUT);
  pinMode(LIN1,OUTPUT);
  pinMode(ROn,OUTPUT);
  pinMode(RIN4,OUTPUT);
  pinMode(RIN3,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LOn, HIGH);   // turn the LED on (HIGH is the voltage level)                         
  digitalWrite(ROn, HIGH);    // turn the LED off by making the voltage LOW                     
  digitalWrite(LIN1, HIGH);
  digitalWrite(RIN3, HIGH);
  delay(1000);
  digitalWrite(LIN1, LOW);
  digitalWrite(RIN3, LOW);
  delay(1000);
  digitalWrite(LIN2, HIGH);
  digitalWrite(RIN4, HIGH);
  delay(1000);
  digitalWrite(LIN2, LOW);
  digitalWrite(RIN4, LOW);
  delay(1000);
}




