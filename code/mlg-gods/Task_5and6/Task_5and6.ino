int one = 2;
int two = 3;
int LOn = 9;
int LIN2 = 7;
int LIN1 = 8;
int ROn = 10;
int RIN4 = 11;
int RIN3 = 12;
int LS = 200;
int RS = 190;
int threshhold = 20;   

const int LEFT_FEEDBACK = 2;
const int RIGHT_FEEDBACK = 3;

volatile int leftcounter = 0;
volatile int rightcounter = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(one,OUTPUT);
  //pinMode(two,OUTPUT);
  pinMode(LOn,OUTPUT);
  pinMode(LIN2,OUTPUT);
  pinMode(LIN1,OUTPUT);
  pinMode(ROn,OUTPUT);
  pinMode(RIN4,OUTPUT);
  pinMode(RIN3,OUTPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  
  
}

// the loop function runs over and over again forever
void loop() {
  analogWrite(LOn, LS);   // turn the left Motor on (HIGH is the voltage level)                         
  analogWrite(ROn, RS);    // turn the right Motor off by making the voltage LOW                     
  digitalWrite(LIN1, HIGH);  //moves forwards
  digitalWrite(RIN3, HIGH);
  digitalWrite(LIN2, LOW);   //doesn't move backwards
  digitalWrite(RIN4, LOW);

  if(millis() > 8500)         //stop and exit when 10 seconds are over
  {
   digitalWrite(LIN1, LOW);
   digitalWrite(RIN3, LOW);
   digitalWrite(LIN2, LOW);
   digitalWrite(RIN4, LOW);
   analogWrite(LOn, 0);                          
   analogWrite(ROn, 0);
   exit(0);
  }
  
  Serial.println("left");    //prints speed
  Serial.println(LS);
  Serial.println("right");
  Serial.println(RS);

  if(leftcounter > rightcounter+threshhold)  //threshhold so that speed is only changed at a major difference
  {
    LS=190;
  }
  else if(leftcounter+threshhold < rightcounter)
  {
    LS=210;
  }
  else
  {
    LS=200;
  }

  analogWrite(LOn, LS);                     
  analogWrite(ROn, RS);
  digitalWrite(LIN1, HIGH);  //moves forwards
  digitalWrite(RIN3, HIGH);
  digitalWrite(LIN2, LOW);   //doesn't move backwards
  digitalWrite(RIN4, LOW);
  delay(1700);
  digitalWrite(RIN3, LOW);
  delay(1000)
  
 /* 
  if(RS > 255)
  {
    RS=255;
  }
  if(LS > 255)
  {
    LS=255;
  }
  */
}




void LeftMotorISR() {
  leftcounter++;
  //Serial.println(leftcounter);
}

void RightMotorISR() {
  rightcounter++;
  //Serial.println(rightcounter);
}

/*void functionName(itemValue)
{
  Code runs here using this number itemValue;
}

if(leftCounter > rightCounter)
{
  do something
}
if(x = 0; x < 5; x++)  // x == 0, x >= 6, not same as !=, And is &&, or is or 
{
  if True run this code;
}
*/
