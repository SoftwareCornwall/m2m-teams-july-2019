//pin numbers on rover
int leftMotorIN2 = 7;
int leftMotorIN1 = 8;
int leftMotorENA = 9;
int rightMotorENB = 10;
int rightMotorIN4 = 11;
int rightMotorIN3 = 12;

//sets the speed for the left and right motors
int leftspeed = 255;
int rightspeed = 255;

//constants for pin numbers on the rover
const int LEFT_FEEDBACK = 2;
const int RIGHT_FEEDBACK = 3;

//ammount of rotations on the rovers tracks
volatile int leftcounter = 0; int rightcounter = 0;

void setup() {
  //turns number of rotations into interupts
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR, RISING);

  //makes them all an output so they can be used later in the code
  pinMode(leftMotorIN2 , OUTPUT);
  pinMode(leftMotorIN1 , OUTPUT);
  pinMode(leftMotorENA, OUTPUT);
  pinMode(rightMotorENB, OUTPUT);
  pinMode(rightMotorIN4, OUTPUT);
  pinMode(rightMotorIN3, OUTPUT);
}

//the robot will do multiple squares to become a figure eight
void loop() {
  straightboy();
  straightboy();
  straightboy();
  straightboy();
  straightboy();
  turnright(850);
  straightboy();
  turnright(850);
  straightboy();
  turnright(870); 
  straightboy();
  turnright(750);
  straightboy();
  straightboy();
  turnleft(750);
  straightboy();
  turnleft(750);
  straightboy();
  turnleft(650);
  straightboy();
  turnright(850);
  analogWrite (leftMotorENA, leftspeed);
  analogWrite (rightMotorENB, rightspeed);
  digitalWrite(leftMotorIN1, HIGH);
  digitalWrite(rightMotorIN3, HIGH);
  delay(400);
  digitalWrite(leftMotorIN1, LOW);
  digitalWrite(rightMotorIN3, LOW);
  turnoffrover();
  exit(0);

  if (leftcounter > rightcounter)
  {
    if (leftspeed > 100)
    {
      leftspeed = 240;
      analogWrite (leftMotorENA, leftspeed);
      delay(50);
    }
  }

  if (rightcounter > leftcounter)
  {
    if (rightspeed > 100)
    {
      rightspeed = 240;
      analogWrite (rightMotorENB, rightspeed);
      delay(50);
    }
  }
}


