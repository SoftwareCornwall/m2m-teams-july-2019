int checkObjects(){
  delay(50);
  //if(sonar_F.ping_cm() <= 15 && sonar_F.ping_cm() >= 5) return 1;
  //if(sonar_D.ping_cm() >= 16) return 2;
  return 0;
}

void forward(int distance){
  int check = checkObjects();
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
    check = checkObjects();
  }
  if(check == 1){
    softStop();
    turnLeft(132);
  } else if(check == 2){
    softStop();
    reverse(50);
    hardStop(); //turnLeft(132);
  }
  softStop();
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
  softStop();
}

void turnRight(int distance){
  while((leftCount + rightCount)/2 < distance){
    analogWrite(rightBack, 160);
    analogWrite(leftForward, 160);
  }
  softStop();
}

void turnLeft(int distance){
  while((leftCount + rightCount)/2 < distance){
    analogWrite(rightForward, 160);
    analogWrite(leftBack, 160);
  }
  softStop();
}

void followBeacon() {
  int rightS = analogRead(rightSensor);
  int middleS = analogRead(middleSensor);
  int leftS = analogRead(leftSensor);

  
    if (rightS < middleS && rightS < leftS) {
      if (rightS < 200) {
      if (rightS + 200 < middleS) {
        turnRight(32);
      } else {
        //forward(32);
      }}
    }
    else if (middleS < leftS) { 
      if (middleS < 200) forward(32);
    }
    else {
      if (leftS < 200) {
      if (leftS + 200 < middleS) {
        turnLeft(32);
      } else {
        //forward(12);
      }
      }
  }
}

void hardStop(){
  analogWrite(rightEnable, 0); // disables right motor
  analogWrite(leftEnable, 0); // disables left motor
}

void softStop(){
  analogWrite(rightForward, 0);
  analogWrite(leftForward, 0);
  analogWrite(rightBack, 0);
  analogWrite(leftBack, 0);
  leftCount = rightCount = 0;
}


