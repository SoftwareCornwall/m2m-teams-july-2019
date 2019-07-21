
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

void stoprover() {
  digitalWrite(left_motor_enabler, LOW);
  digitalWrite(right_motor_enabler, LOW);
  digitalWrite(left_motor_forwards, LOW);
  digitalWrite(right_motor_forwards, LOW);
  digitalWrite(left_motor_forwards, LOW);
  digitalWrite(right_motor_forwards, LOW);
  digitalWrite(left_motor_reverse, LOW);
  digitalWrite(right_motor_reverse, LOW);
  delay(500);
  
}

void countersLR(){
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
