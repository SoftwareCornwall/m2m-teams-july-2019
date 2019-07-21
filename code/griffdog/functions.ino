void goStraight(){
  if (leftcounter < rightcounter){
    leftSpeed = 240;
    rightSpeed = 225;
  } else if (leftcounter > rightcounter){
    leftSpeed = 225;
    rightSpeed = 255;
  } else {
    leftSpeed = 240;
    rightSpeed = 255;
  }
}

// Function for turning the rover right

void turnright(int wait){
  leftforward();
   rightbackward();
   delay(wait);
}

// Function for turning the rover left

void turnleft(int wait){
  leftbackward();
  rightforward();
  delay(wait);
}

// Function for hard stopping the rover

void hardstop(int wait){
  leftstop();
  rightstop(); 
  delay(wait); 
}

// Function for soft stopping the rover

void softstop(int wait){
  leftsstop();
  rightsstop();
  delay(wait);  
}

// Function for going forwards in a straight line

void forward(int wait){
  leftforward();
  rightforward();
  delay(wait);  
}

//Function for moving the rover backwards in a straight line

void backward(int wait){
  leftbackward();
  rightbackward();
  delay(wait);  
}

// Function for making the left motor move fowards

void leftforward() {
 analogWrite(LE, leftSpeed);
 digitalWrite(LF, HIGH);
 digitalWrite(LB, LOW); 
}

// Function for making the left motor move backwards

void leftbackward() {
 analogWrite(LE, leftSpeed);
 digitalWrite(LF, LOW);
 digitalWrite(LB, HIGH);  
}

// Function for the left motor to stop

void leftstop() {
 digitalWrite(LE, HIGH);
 digitalWrite(LF, HIGH);
 digitalWrite(LB, HIGH);
}

// Function for the right motor to move forwards

void rightforward() {
 analogWrite(RE, rightSpeed);
 digitalWrite(RF, HIGH);
 digitalWrite(RB, LOW); 
}

// Function for the right motor to move backwards

void rightbackward() {
 analogWrite(RE, rightSpeed);
 digitalWrite(RF, LOW);
 digitalWrite(RB, HIGH); 
}

// Function for the right motor to stop

void rightstop() {
 digitalWrite(RE, HIGH);
 digitalWrite(RF, HIGH);
 digitalWrite(RB, HIGH); 
}

//Function for the right motor to soft stop

void rightsstop() {
 digitalWrite(RE, LOW);
 digitalWrite(RF, LOW);
 digitalWrite(RB, LOW); 
}

// Function for the left motor to soft stop

void leftsstop() {
 digitalWrite(LE, LOW);
 digitalWrite(LF, LOW);
 digitalWrite(LB, LOW); 
}
