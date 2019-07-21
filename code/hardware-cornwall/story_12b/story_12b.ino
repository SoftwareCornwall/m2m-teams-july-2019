
int leftBack = 7,    rightBack = 11,
    leftEnable = 9,  rightEnable = 10,
    leftForward = 8, rightForward = 12,
    leftFeedback =2, rightFeedback = 3,
    rightSensor = 2,middleSensor = 1, leftSensor = 0,
    leftCount = 0,   rightCount = 0;
// motor variables

//int pause = 0, forward = 1, reverse = 2, leftTurn = 3, rightTurn = 4;
//movement mode variables


#include <NewPing.h>

NewPing sonar_F(4, 5, 200);
NewPing sonar_D(13, 17, 50);// NewPing setup of pins and maximum distance.


void setup() {
  Serial.begin(9600);
  sonar_F.ping_cm();
  sonar_D.ping_cm();
  pinMode(rightSensor, INPUT);
  pinMode(middleSensor, INPUT);
  pinMode(leftSensor, INPUT);
  hardStart();
  //enable motors
  attachInterrupt(digitalPinToInterrupt(leftFeedback), leftMotorISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rightFeedback), rightMotorISR, CHANGE);
  //interrupts the code at any point to increase the motor counts
} 

 void loop() {
  forward(200);
  turnLeft(180);
  delay(100);
  forward(200);
  turnLeft(180);
  delay(100);
  forward(200);
  turnLeft(180);
  delay(100);
  forward(200);
  turnLeft(180);
  delay(1000);
  forward(10000);
  hardStart();
  turnRight(400);
  delay(1000);
  forward(10000);
  turnLeft(180);
  forward(200);
  delay(3000);
  while (true) {
    followBeacon();
  }
  hardStop(); // stops no matter what
}

void leftMotorISR() {
  leftCount++; // increases by 1
}
void rightMotorISR() {
  rightCount++; // increases by 1
}

