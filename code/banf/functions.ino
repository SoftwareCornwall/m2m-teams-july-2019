void finish() {
  while (true) {
    pause();
    delay(1000);
  }
}

void pause() {moveMotors(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH);} // makes the rover stop in it's tracks

void pauseTime(int tme) {pause(); delay(tme);}

void off(int tme) {
  moveMotors(LOW,LOW,LOW,LOW,LOW,LOW);
  delay(tme);
}

void moveMotors(int rme, int rmf, int rmb, int lme, int lmf, int lmb) {
  digitalWrite(rightMotorON_OFF, rme);
  digitalWrite(rightMotorFwd, rmf);
  digitalWrite(rightMotorBack, rmb);

  digitalWrite(leftMotorON_OFF, lme);
  digitalWrite(leftMotorFwd, lmf);
  digitalWrite(leftMotorBack, lmb);
}

void fwd(int tme) { // foward movement for a set time 
  ifwd();
  delay(tme);
}

void back(int tme) { // backward movement for a set time 
  iback();
  delay(tme);
}

void ifwd () { // instantaneous foward movement
    moveMotors(HIGH,HIGH,LOW,HIGH,HIGH,LOW);
}

void iback() { // intantaneous backward movemen  
  moveMotors(HIGH,LOW,HIGH,HIGH,LOW,HIGH);
}

void superClock() { // turns clockwise at full speed
  moveMotors(HIGH,LOW,HIGH,HIGH,HIGH,LOW);

}

void superAntiClock() { // turns anti-clockwise at full speed
  moveMotors(HIGH,HIGH,LOW,HIGH,LOW,HIGH);

}

void turn90anti_clock() { 
  superAntiClock();
  delay(810);
}

void turn90clock() {
  superClock();
  delay(870);
}

void turn(int tme, int rs, int ls) { // rs = right speed, ls = left speed
  analogWrite(rightMotorON_OFF, rs);
  digitalWrite(rightMotorFwd, HIGH);
  digitalWrite(rightMotorBack, LOW);

  analogWrite(leftMotorON_OFF, ls);
  digitalWrite(leftMotorFwd, HIGH);
  digitalWrite(leftMotorBack, LOW);
  
  delay(tme);
}

void moveBackTicks(int ticks) {
  rightcounter = 0;
  iback();
  Serial.println(dpng);
  if (rightcounter > ticks) {finish();}
}

void getPings() { // reads both pings
  delay(50);
  dpng = dsonar.ping_cm(); // reads the distance to the ground
  delay(50);
  fpng = fsonar.ping_cm(); // reads the distance to the nearest obstacle
}

int leftlight() {return analogRead(7);}
int rightlight() {return analogRead(2);}
int midlight() {return analogRead(6);}

bool obstacle() {return fpng < 15 and fpng > 3;}

bool clearLightSource() { // identifies whether there is a clear light source
  if (leftlight()<500 or rightlight()<500 or midlight()<500) {
    return true;
  }
  else {
    return false;
  }
}

void mtl() { // move to light, the code to tell the robot to move in the right direction
  if (leftlight() < midlight()) {
        superAntiClock();
        delay(100);
   }
   else if (rightlight() < midlight()) {
     superClock();
     delay(100);
   }   
   else {ifwd();}
}

void getDownCliff() {
  pauseTime(1000);
  back(500);
  turn90clock();
  turn90clock();
  back(3000);
  turn90clock();
  turn90clock();
}

void getAroundCliff() {
  pauseTime(1000);
  back(3000);
  turn90clock();
}

void fACsquare() { // forward anti-clockwise
  for (int i=0; i < 3; i++) {
    Serial.println("test");
    fwd(1000);
    turn90anti_clock();
    pauseTime(150);
  }  
  fwd(1050);
  turn90anti_clock();
  pauseTime(150);  
}

void bACsquare() { // backwards anti-clockwise
  for (int i=0; i<4;i++){
    back(1000);
    turn90anti_clock();
    pauseTime(150); 
  }
}

void fCsquare() { // forward clockwise
  for (int i=0; i<4;i++) {
    fwd(1000);
    turn90clock();
    pauseTime(150);
  }
}

void bCsquare() { // backwards clockwise
  for (int i=0; i<3;i++) {
    back(1000);
    turn90clock();
    pauseTime(150);
  }
  back(1400);
  turn90clock();
  pauseTime(150);
}

void fwdStraight(){
  if (rightcounter > leftcounter){
    leftAdd = 50;
    rightAdd = 0;
  }
  else if (leftcounter > rightcounter){
    rightAdd = 100;
    leftAdd = 0;
  }  
  rightAdd += 150;
  leftAdd += 150;
  
  turn(500, rightAdd, leftAdd);
}


