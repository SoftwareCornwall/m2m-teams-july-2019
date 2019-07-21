int one = 2;  //set values
int two = 3;
int LOn = 9;
int LIN2 = 7;
int LIN1 = 8;
int ROn = 10;
int RIN4 = 11;
int RIN3 = 12;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as output.
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
  digitalWrite(LOn, HIGH);   // turn the LED on (HIGH is the voltage level), mimics enabeling of motor                         
  digitalWrite(ROn, HIGH);                         
  digitalWrite(LIN1, HIGH);  //LEDs for moving forward turned on
  digitalWrite(RIN3, HIGH);
  delay(10000);
  digitalWrite(LIN1, LOW);   // turn the LED off by making the voltage LOW, stops moving
  digitalWrite(RIN3, LOW);
  delay(1000);
  digitalWrite(LIN2, HIGH);   // turn the LED on, move forward
  digitalWrite(RIN4, HIGH);
  delay(1000);
  digitalWrite(LIN2, LOW);   // turn the LED off by making the voltage LOW, stops moving
  digitalWrite(RIN4, LOW);
  delay(1000);
}




