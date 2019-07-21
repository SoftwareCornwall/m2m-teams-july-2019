void countersLR() {
    Serial.begin(115200);
    attachInterrupt(digitalPinToInterrupt(right_motor_feedback),right_motor_isr, RISING);
    attachInterrupt(digitalPinToInterrupt(left_motor_feedback),left_motor_isr, RISING);
}

void left_motor_isr() {
    leftcounter++;
  }

void right_motor_isr() {
  rightcounter++;
}

//HIGH=255
void roverforward(int delaytime) { 
    digitalWrite(left_motor_forwards, LOW);
    digitalWrite(right_motor_forwards, LOW);
    analogWrite(left_motor_enabler, motorspeedL);
    analogWrite(right_motor_enabler,motorspeedR);
    delay(delaytime);
}

void line() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  //makes the rover move forwards
    analogWrite(left_motor_enabler, motorspeedL);
    analogWrite(right_motor_enabler,motorspeedR);
    ///delay(500);
    digitalWrite(left_motor_forwards, HIGH);
    digitalWrite(right_motor_forwards, HIGH);
    /*stabalises the rover by checking the revolutions of each 
    motor to see if they are equal, and adjusting them*/
   if (leftcounter > rightcounter + thresholdL) {
          motorspeedR = motorspeedR + 5;
          motorspeedL = motorspeedL - 5;
          analogWrite(left_motor_enabler, motorspeedL);
          analogWrite(right_motor_enabler,motorspeedR);
          //delay(25);
          }
   else if (rightcounter > leftcounter + thresholdR) {
          motorspeedL = motorspeedL + 5;
          motorspeedR = motorspeedR - 5;
          analogWrite(left_motor_enabler, motorspeedL);
          analogWrite(right_motor_enabler,motorspeedR);
          //delay(25);        
          }
        //delay(200);
        //makes the code run for 10 seconds
   /*if (millis() > 10000) {
     analogWrite(left_motor_enabler, LOW);
     analogWrite(right_motor_enabler,LOW);*/

     int floor_distance = sonar.ping_cm();
     Serial.println(floor_distance);

     if (floor_distance >= 15 or floor_distance == 0) {
      stoprover();
      motorspeedL = 175;
      motorspeedR = 175;
      state = 1;           
    }
}
  
void stoprover() {
  digitalWrite(left_motor_forwards, LOW);
  digitalWrite(right_motor_forwards, LOW);
  digitalWrite(left_motor_forwards, LOW);
  digitalWrite(right_motor_forwards, LOW);
  digitalWrite(left_motor_reverse, LOW);
  digitalWrite(right_motor_reverse, LOW);
  delay(300);
  
}

void zigzag() {
  digitalWrite(right_motor_enabler, motorspeedR);
  digitalWrite(left_motor_enabler, motorspeedL);
  rightturn(40);
  stoprover();
  forwardsquare(1500);
  stoprover();
  rightturn(80);
  stoprover();
  forwardsquare(1500);
  stoprover();
  leftturn(75);
  stoprover();
  forwardsquare(1500);
  stoprover();
  rightturn(90);
  stoprover();
  forwardsquare(1500);
  stoprover();
  state = 3;

  
  
  
}

void leftturn(int turncounter) {
  rightcounter = 0;
  while (rightcounter <= turncounter) {
    analogWrite(left_motor_enabler, motorspeedL);
    analogWrite(right_motor_enabler,motorspeedR);
    digitalWrite(left_motor_forwards, LOW);
    digitalWrite(right_motor_forwards, HIGH);
    digitalWrite(left_motor_reverse, HIGH);
    digitalWrite(right_motor_reverse, LOW);
  }
  
}


void rightturn(int turncounter) {
  leftcounter = 0;
  while (leftcounter <= turncounter) {
    analogWrite(left_motor_enabler, motorspeedL);
    analogWrite(right_motor_enabler,motorspeedR);
    digitalWrite(left_motor_forwards, HIGH);
    digitalWrite(right_motor_forwards, LOW);
    digitalWrite(left_motor_reverse, LOW);
    digitalWrite(right_motor_reverse, HIGH);
  }
}
void forwardsquare(int delaytime) {
  analogWrite(left_motor_enabler, motorspeedL);
  analogWrite(right_motor_enabler,motorspeedR);
  digitalWrite(left_motor_forwards, HIGH);
  digitalWrite(right_motor_forwards, HIGH);
  digitalWrite(left_motor_reverse, LOW);
  digitalWrite(right_motor_reverse, LOW);
  delay(delaytime);
  }
void leftsquare() {

  //second edge and left turn
  forwardsquare(1500);
  stoprover();
 
  leftturn(82);
  stoprover();
  //third edge and left turn
  forwardsquare(1500);
  stoprover();
  
  leftturn(80);
  stoprover();
  //fourth edge and left turn
  forwardsquare(1500);
  stoprover();

  leftturn(78);
  stoprover();

  forwardsquare(1500);
  stoprover();

  leftturn(80);
  stoprover();
}


void rightsquare() {
  rightturn(150);
  stoprover();
  //first edge and turn
  forwardsquare(1500);
  stoprover();
  
  rightturn(82);
  stoprover();

  //second edge and right turn
  forwardsquare(1500);
  stoprover();
 
  rightturn(81);
  stoprover();
  //third edge and right turn
  forwardsquare(1500);
  stoprover();
  
  rightturn(82);
  stoprover();
  //fourth edge and right turn
  forwardsquare(1500);
  stoprover();

  rightturn(81);
  stoprover();

  
}
