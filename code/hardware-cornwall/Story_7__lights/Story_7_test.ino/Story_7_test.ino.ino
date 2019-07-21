
int leftBack = 7,    rightBack = 11,
    leftEnable = 9,  rightEnable = 10,
    leftForward = 8, rightForward = 12,
    leftFeedback =2, rightFeedback = 3,
    leftCount = 0,   rightCount = 0;

int pause = 0, forward = 1, reverse = 2, leftTurn = 3, rightTurn = 4;

void setup() {
  Serial.begin(9600);
  
  analogWrite(leftEnable, 255);
  analogWrite(rightEnable, 255);
  attachInterrupt(digitalPinToInterrupt(leftFeedback), leftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(rightFeedback), rightMotorISR, RISING);

Move(forward, 475);
Move(rightTurn,100);
Move(forward, 238);
Move(rightTurn,100);
Move(forward, 475);
Move(leftTurn, 100);
Move(forward, 238);
Move(leftTurn, 100);
Move(forward, 238);
Move(leftTurn, 100);

 /*Move(leftTurn, 100);
 Move(forward, 475);
 Move(leftTurn, 200);
 Move(rightTurn, 200);
 Move(reverse, 475);
 Move(rightTurn, 100);*/
} 

void loop() {
}

void Move(int mode, int distance) {
  switch (mode){
    case 1:
         while((leftCount + rightCount)/2 < distance){
    if (leftCount < rightCount) {
     analogWrite(rightForward, 0);
      analogWrite(leftForward, 192);
     }
     else if (rightCount < leftCount) {
     analogWrite(leftForward, 0);
     analogWrite(rightForward, 192);
    }
    else {
      analogWrite(rightForward, 192);
     analogWrite(leftForward, 192);
     }
         }
         break;
    case 2:
         while((leftCount + rightCount)/2 < distance){
     if (leftCount < rightCount) {
     analogWrite(rightBack, 0);
      analogWrite(leftBack, 192);
     }
     else if (rightCount < leftCount) {
     analogWrite(leftBack, 0);
     analogWrite(rightBack, 192);
    }
    else {
      analogWrite(rightBack, 192);
     analogWrite(leftBack, 192);
     }
         }
         break;
     case 3: 
          while((leftCount + rightCount)/2 < distance){
              analogWrite(leftBack, 192);
              analogWrite(rightForward, 192);
          }
          break;
     case 4: 
          while((leftCount + rightCount)/2 < distance){
              analogWrite(leftForward, 192);
              analogWrite(rightBack, 192); 
          }
          break;
     default: break;
     
  }
  Serial.println(leftCount);
  Serial.println(rightCount);
  analogWrite(rightForward, 0);
  analogWrite(leftForward, 0);
  analogWrite(rightBack, 0);
  analogWrite(leftBack, 0);
}

void leftMotorISR() {
  leftCount++;
}

void rightMotorISR() {
  rightCount++;
}

