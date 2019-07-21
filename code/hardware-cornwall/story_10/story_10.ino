
int leftBack = 7,    rightBack = 11,
    leftEnable = 9,  rightEnable = 10,
    leftForward = 8, rightForward = 12,
    leftFeedback =2, rightFeedback = 3,
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
  analogWrite(leftEnable, 255);
  analogWrite(rightEnable, 255);
  //enable motors
  attachInterrupt(digitalPinToInterrupt(leftFeedback), leftMotorISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rightFeedback), rightMotorISR, CHANGE);
  //interrupts the code at any point to increase the motor counts
} 

void loop() {
  forward(1000);
//  reverse(500);
//  turn_Left(90);
//  turn_Right(90);
//  reverse(500);
  //carefulForward(5);
  hard_Stop(); // stops no matter what
}

//void figure_Of_Eight(){//  Move(forward, 150);
//  Move(rightTurn,90);
//  Move(forward, 150);
//  Move(rightTurn,86);
//  Move(forward, 150);
//  Move(rightTurn,84);
//  Move(forward, 300);
//  Move(leftTurn, 90);
//  Move(forward, 150);
//  Move(leftTurn, 90);
//  Move(forward, 150);
//  Move(leftTurn, 90);
//  Move(forward, 150);
//}
//  void figure_Of_Eight_Reverse(){
//  Move(reverse, 150);
//  Move(rightTurn,75);
//  Move(reverse, 150);
//  Move(rightTurn,75);
//  Move(reverse, 150);
//  Move(rightTurn,75);
//  Move(reverse, 300);
//  Move(leftTurn, 96);
//  Move(reverse, 150);
//  Move(leftTurn,96);
//  Move(reverse, 150);
//  Move(leftTurn, 96);
//  Move(reverse, 150);
//}

bool check_Objects(){
  delay(50);
  Serial.println(sonar_D.ping_cm());
  if(sonar_F.ping_cm() <= 15 && sonar_F.ping_cm() >= 5) return 1;
  if(sonar_D.ping_cm() >= 16) {
    Serial.println(12345678);
    return 2;
  }
  return 0;
}

void forward(int distance){
  int check = check_Objects();
  while((leftCount + rightCount)/2 < distance && !check){
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
    //delay(50);
    check = check_Objects();
    Serial.println(check);
  }
  if(check == 1){
    soft_Stop();
    turn_Left(132);
  } else if(check == 2){
    Serial.println(12345678);
    soft_Stop();
    reverse(100);
  }
  soft_Stop();
}

void reverse(int distance){
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
  soft_Stop();
}

void turn_Right(int distance){
  while((leftCount + rightCount)/2 < distance){
    analogWrite(rightBack, 160);
    analogWrite(leftForward, 160);
  }
  soft_Stop();
}

void turn_Left(int distance){
  while((leftCount + rightCount)/2 < distance){
    analogWrite(rightForward, 160);
    analogWrite(leftBack, 160);
  }
  soft_Stop();
}

//void carefulForward(int distance) {
//  while((leftCount + rightCount)/2 < distance && sonar.ping_cm() > 15 | sonar.ping_cm() == 0){
//
//        //if the left wheel has moved more than the right 
//        if (leftCount < rightCount) {
//          analogWrite(rightForward, 128);
//          analogWrite(leftForward, 192);
//        }
//        else if (rightCount < leftCount) {
//          analogWrite(leftForward, 128);
//          analogWrite(rightForward, 192);
//        }
//        else {
//          analogWrite(rightForward, 192);
//          analogWrite(leftForward, 192);
//        }
//    delay(50);    
//       }
//       if (sonar.ping_cm() < 15) 
//       {
//        analogWrite(rightForward, 0);
//        analogWrite(leftForward, 0);
//        Move(leftTurn, 90);
//       }
//}

void hard_Stop(){
  analogWrite(rightEnable, 0); // disables right motor
  analogWrite(leftEnable, 0); // disables left motor
}

void soft_Stop(){
  analogWrite(rightForward, 0);
  analogWrite(leftForward, 0);
  analogWrite(rightBack, 0);
  analogWrite(leftBack, 0);
  leftCount = rightCount = 0;
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
