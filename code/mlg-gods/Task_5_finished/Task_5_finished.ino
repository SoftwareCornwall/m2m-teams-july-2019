int one = 2;
int two = 3;
int LOn = 9;
int LIN2 = 7;
int LIN1 = 8;
int ROn = 10;
int RIN4 = 11;
int RIN3 = 12;
int LS = 190;
int RS = 190;
int threshhold = 15;

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
  analogWrite(LOn, LS);   // turn the LED on (HIGH is the voltage level)                         
  analogWrite(ROn, RS);    // turn the LED off by making the voltage LOW                     
  digitalWrite(LIN1, HIGH);
  digitalWrite(RIN3, HIGH);
  digitalWrite(LIN2, LOW);
  digitalWrite(RIN4, LOW);

  if(millis() > 10000)
  {
   digitalWrite(LIN1, LOW);
   digitalWrite(RIN3, LOW);
   digitalWrite(LIN2, LOW);
   digitalWrite(RIN4, LOW);
   analogWrite(LOn, 0);                          
   analogWrite(ROn, 0);
   exit(0);
  }
  
  Serial.println("left");
  Serial.println(LS);
  Serial.println("right");
  Serial.println(RS);

  if(leftcounter > rightcounter+threshhold)
  {
    LS-=5;
  }
  else if(leftcounter+threshhold < rightcounter)
  {
    LS+=5;
  }
  if(RS > 255)
  {
    RS=255;
  }
  if(LS > 255)
  {
    LS=255;
  }
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
