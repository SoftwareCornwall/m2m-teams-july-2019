
int leftBack = 7,    rightBack = 11,
    leftEnable = 9,  rightEnable = 10,
    leftForward = 8, rightForward = 12,
    leftFeedback =2, rightFeedback = 3,
    leftCount = 0,   rightCount = 0;
// motor variables

int pause = 0, forward = 1, reverse = 2, leftTurn = 3, rightTurn = 4;
//movement mode variables

void setup() {
  Serial.begin(9600);
  analogWrite(leftEnable, 255);
  analogWrite(rightEnable, 255);
  //enable motors
  attachInterrupt(digitalPinToInterrupt(leftFeedback), leftMotorISR, RISING);
  attachInterrupt(digitalPinToInterrupt(rightFeedback), rightMotorISR, RISING);
  //interrupts the code at any point to increase the motor counts
} 

void loop() {
  figure_Of_Eight(); // launches code for figure of eight
  delay(1000);
  figure_Of_Eight_Reverse();
  hard_Stop(); // stops no matter what
}
void figure_Of_Eight(){
  Move(forward, 150);
  Move(rightTurn,90);
  Move(forward, 150);
  Move(rightTurn,84);
  Move(forward, 150);
  Move(rightTurn,84);
  Move(forward, 300);
  Move(leftTurn, 90);
  Move(forward, 150);
  Move(leftTurn, 90);
  Move(forward, 150);
  Move(leftTurn, 90);
  Move(forward, 150);
}
  void figure_Of_Eight_Reverse(){
  Move(reverse, 150);
  Move(rightTurn,75);
  Move(reverse, 150);
  Move(rightTurn,75);
  Move(reverse, 150);
  Move(rightTurn,75);
  Move(reverse, 300);
  Move(leftTurn, 96);
  Move(reverse, 150);
  Move(leftTurn,108);
  Move(reverse, 135);
  Move(leftTurn, 104);
  Move(reverse, 120);
}
void hard_Stop(){
  analogWrite(rightForward, 0);
  analogWrite(leftForward, 0);
  analogWrite(rightBack, 0);
  analogWrite(leftBack, 0);
  analogWrite(rightEnable, 0); // disables right motor
  analogWrite(leftEnable, 0); // disables left motor
}
void Move(int mode, int distance) {
  switch (mode){
    case 1: // forward
      while((leftCount + rightCount)/2 < distance){

        //if the left wheel has moved more than the right 
        if (leftCount < rightCount) {
          analogWrite(rightForward, 128);
          analogWrite(leftForward, 192);
        }
        else if (rightCount < leftCount) {
          analogWrite(leftForward, 128);
          analogWrite(rightForward, 192);
        }
        else {
          analogWrite(rightForward, 192);
          analogWrite(leftForward, 192);
        }
       }
       break;
    case 2: // reverse
      while((leftCount + rightCount)/2 < distance){
        if (leftCount < rightCount) {
          analogWrite(rightBack, 128);
          analogWrite(leftBack, 192);
        }
        else if (rightCount < leftCount) {
          analogWrite(leftBack, 128);
          analogWrite(rightBack, 192);
        }
        else {
          analogWrite(rightBack, 192);
          analogWrite(leftBack, 192);
        }
      }
      break;
    case 3: // left turn
      while((leftCount + rightCount)/2 < distance){
        if (leftCount < rightCount) {
          analogWrite(rightBack, 128);
          analogWrite(leftForward, 160);
        }
        else if (rightCount < leftCount) {
          analogWrite(leftForward, 128);
          analogWrite(rightBack, 160);
        }
        else {
          analogWrite(rightBack, 160);
          analogWrite(leftForward, 160);
        }
      }
      break;
    case 4: // right turn
      while((leftCount + rightCount)/2 < distance){
        if (rightCount < leftCount) {
          analogWrite(rightForward, 128);
          analogWrite(leftBack, 160);
        }
        else if (leftCount < rightCount) {
          analogWrite(leftBack, 128);
          analogWrite(rightForward, 160);
        }
        else {
          analogWrite(rightForward, 160);
          analogWrite(leftBack, 160);
        } 
      }
      break;
    default: break;
  }
  analogWrite(rightForward, 0); //stops movement
  analogWrite(leftForward, 0);
  analogWrite(rightBack, 0);
  analogWrite(leftBack, 0);
  //resets motors
  leftCount = rightCount = 0; // resets counters
}

void leftMotorISR() {
  leftCount++; // increases by 1
}
void rightMotorISR() {
  rightCount++; // increases by 1
}
