
//Left Track = 46.98cm
//Right Track = 46.17cm

int leftBack = 7,    rightBack = 11,
    leftEnable = 9,  rightEnable = 10,
    leftForward = 8, rightForward = 12,
    leftFeedback =2, rightFeedback = 3,
    leftCount = 0,   rightCount = 0;

int pause = 0, forward = 1, reverse = 2, leftTurn = 3, rightTurn = 4;

void setup() {
  //for (int i = 2; i < 7; i++ ) pinMode(i, OUTPUT);
  Serial.begin(9600);
  
  analogWrite(leftEnable, 192);
  analogWrite(rightEnable, 192);
  attachInterrupt(digitalPinToInterrupt(leftFeedback), leftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(rightFeedback), rightMotorISR, RISING);
  
 Move(forward, 950);
} 

void loop() {
  //
}

void Move(int mode, int distance) {
  while((leftCount + rightCount)/2 < distance){
   if (leftCount < rightCount) {
    analogWrite(rightForward, 102);
    analogWrite(leftForward, 192);
   }
   else if (rightCount < leftCount) {
    analogWrite(leftForward, 102);
    analogWrite(rightForward, 192);
   }
   else {
    analogWrite(leftForward, 192);
    analogWrite(rightForward, 192);
    
   }
  }
  //leftCount = rightCount = 0;
  Serial.println(leftCount);
  Serial.println(rightCount);
  analogWrite(rightForward, 0);
  analogWrite(leftForward, 0);
}

void leftMotorISR() {
  leftCount++;
}

void rightMotorISR() {
  rightCount++;
}

