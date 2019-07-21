






void backwards_right_square(boolean lastTurn) 
{
  analogWrite(LOn, LS);  //turn on                    
  analogWrite(ROn, RS);
  digitalWrite(LIN2, HIGH);  //first side
  digitalWrite(RIN4, HIGH);
  digitalWrite(LIN1, LOW);   
  digitalWrite(RIN3, LOW);
  delay(driveTime);
  digitalWrite(RIN4, LOW);  //turns
  digitalWrite(RIN3, HIGH);
  delay(1015);

  digitalWrite(RIN3, LOW);
  digitalWrite(RIN4, HIGH);  //second side
  delay(1650);
  digitalWrite(RIN4, LOW);   //turns
  digitalWrite(RIN3, HIGH);
  delay(1015);
  

  digitalWrite(RIN3, LOW);
  digitalWrite(RIN4, HIGH);  //third side
  delay(1400);
  digitalWrite(RIN4, LOW);  //turns
  digitalWrite(RIN3, HIGH);
  delay(1015);

 
  digitalWrite(RIN3, LOW);
  digitalWrite(RIN4, HIGH);  //forth side
  delay(driveTime);
  
  if(lastTurn) {
    digitalWrite(RIN4, LOW);  //turns
    digitalWrite(RIN3, HIGH);
    delay(turningTime);
  
  }
  
  digitalWrite(LIN2, LOW);  //stops
  digitalWrite(LIN1, LOW);
  digitalWrite(RIN3, LOW);
  digitalWrite(RIN4, LOW);
}


void backwards_left_square(boolean lastTurn) 
{
  analogWrite(LOn, LS);  //turn on                    
  analogWrite(ROn, RS);
  digitalWrite(LIN2, HIGH);  //fifth side
  digitalWrite(RIN4, HIGH);
  digitalWrite(LIN1, LOW);   
  digitalWrite(RIN3, LOW);
  delay(driveTime);
  digitalWrite(LIN2, LOW);  //turns left
  digitalWrite(LIN1, HIGH);
  delay(1075);

  digitalWrite(LIN1, LOW);
  digitalWrite(LIN2, HIGH);  //sixth side
  delay(driveTime);
  digitalWrite(LIN2, LOW);  //turns left
  digitalWrite(LIN1, HIGH);
  delay(1025);

  digitalWrite(LIN1, LOW);
  digitalWrite(LIN2, HIGH);  //seventh side
  delay(driveTime);
  digitalWrite(LIN2, LOW);  //turns left
  digitalWrite(LIN1, HIGH);
  delay(1075);

  digitalWrite(LIN1, LOW);
  digitalWrite(LIN2, HIGH);  //eighth side
  delay(driveTime);

  if(lastTurn) {
  digitalWrite(LIN2, LOW);  //turns left
  digitalWrite(LIN1, HIGH);
  delay(turningTime);
  }

  digitalWrite(LIN2, LOW);  //stops
  digitalWrite(LIN1, LOW);
  digitalWrite(RIN3, LOW);
  digitalWrite(RIN4, LOW);
}

void left_square(boolean lastTurn) {

  analogWrite(LOn, LS);  //turn on                    
  analogWrite(ROn, RS);
  digitalWrite(LIN1, HIGH);  //fifth side
  digitalWrite(RIN3, HIGH);
  digitalWrite(LIN2, LOW);   
  digitalWrite(RIN4, LOW);
  delay(driveTime);
  digitalWrite(LIN1, LOW);  //turns left
  digitalWrite(LIN2, HIGH);
  delay(1040);                                                                                                                                                                                  

  digitalWrite(LIN2, LOW);
  digitalWrite(LIN1, HIGH);  //sixth side
  delay(driveTime);
  digitalWrite(LIN1, LOW);  //turns left
  digitalWrite(LIN2, HIGH);
  delay(910);

  digitalWrite(LIN2, LOW);
  digitalWrite(LIN1, HIGH);  //seventh side
  delay(driveTime);
  digitalWrite(LIN1, LOW);  //turns left
  digitalWrite(LIN2, HIGH);
  delay(910);

  digitalWrite(LIN2, LOW);
  digitalWrite(LIN1, HIGH);  //eighth side
  delay(driveTime);

  if(lastTurn) {
  digitalWrite(LIN1, LOW);  //turns left
  digitalWrite(LIN2, HIGH);
  delay(turningTime);
  }

  digitalWrite(LIN1, LOW);  //stops
  digitalWrite(LIN2, LOW);
  digitalWrite(RIN4, LOW);
  digitalWrite(RIN3, LOW);
}

void right_square(boolean lastTurn) {
  
  forward2metres();
  
  analogWrite(LOn, LS);  //turn on                    
  analogWrite(ROn, RS);
  digitalWrite(LIN1, HIGH);  //first side
  digitalWrite(RIN3, HIGH);
  digitalWrite(LIN2, LOW);   
  digitalWrite(RIN4, LOW);
  delay(driveTime);
  digitalWrite(RIN3, LOW);  //turns
  digitalWrite(RIN4, HIGH);
  delay(1100);

  digitalWrite(RIN4, LOW);
  digitalWrite(RIN3, HIGH);  //second side
  delay(driveTime);
  digitalWrite(RIN3, LOW);   //turns
  digitalWrite(RIN4, HIGH);
  delay(1010);
  

  digitalWrite(RIN4, LOW);
  digitalWrite(RIN3, HIGH);  //third side
  delay(driveTime);
  digitalWrite(RIN3, LOW);  //turns
  digitalWrite(RIN4, HIGH);
  delay(1075);

 
  digitalWrite(RIN4, LOW);
  digitalWrite(RIN3, HIGH);  //forth side
  delay(driveTime);
  
  if(lastTurn) {
    digitalWrite(RIN3, LOW);  //turns
    digitalWrite(RIN4, HIGH);
    delay(1050);
  
  }
  
  digitalWrite(LIN1, LOW);  //stops
  digitalWrite(LIN2, LOW);
  digitalWrite(RIN4, LOW);
  digitalWrite(RIN3, LOW);
}
