
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
  analogWrite(leftEnable, 255);
  analogWrite(rightEnable, 255);
  //enable motors
  attachInterrupt(digitalPinToInterrupt(leftFeedback), leftMotorISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rightFeedback), rightMotorISR, CHANGE);
  //interrupts the code at any point to increase the motor counts
} 

  void loop() {
  followBeacon();
  //hard_Stop(); // stops no matter what
}

void leftMotorISR() {
  leftCount++; // increases by 1
}
void rightMotorISR() {
  rightCount++; // increases by 1
}
