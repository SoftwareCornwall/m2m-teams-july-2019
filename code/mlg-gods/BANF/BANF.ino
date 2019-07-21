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
int turningTime=1025; 
int driveTime=1600; 

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
  forward2metres();
 forward_eight();
 backwards_eight();
 exit(0);
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

  //turn(false);





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
