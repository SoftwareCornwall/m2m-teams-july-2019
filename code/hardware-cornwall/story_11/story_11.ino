
int leftBack = 7,    rightBack = 11,
    leftEnable = 9,  rightEnable = 10,
    leftForward = 8, rightForward = 12,
    leftFeedback =2, rightFeedback = 3,
    rightSensor = 16,middleSensor = 15, leftSensor = 14,
    leftCount = 0,   rightCount = 0;
// motor variables

//int pause = 0, forward = 1, reverse = 2, leftTurn = 3, rightTurn = 4;
//movement mode variables


#include <NewPing.h>

NewPing sonar_F(4, 5, 200);
NewPing sonar_D(13, 17, 50);// NewPing setup of pins and maximum distance.


void setup() {
  Serial.begin(9600);
  pinMode(rightSensor, INPUT);
  pinMode(middleSensor, INPUT);
  pinMode(leftSensor, INPUT);
  sonar_F.ping_cm();
  sonar_D.ping_cm();
  analogWrite(leftEnable, 255);
  analogWrite(rightEnable, 255);
  //enable motors
  attachInterrupt(digitalPinToInterrupt(leftFeedback), leftMotorISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rightFeedback), rightMotorISR, CHANGE);
  //interrupts the code at any point to increase the motor counts
} 

void loop() {
  Serial.println(analogRead(rightSensor));
  Serial.println(analogRead(middleSensor));
  Serial.println(analogRead(leftSensor));
  forward(1024);
//  reverse(500);
//  turn_Left(90);
//  turn_Right(90);
//  reverse(500);
  //carefulForward(5);
  //hard_Stop(); // stops no matter what
}
