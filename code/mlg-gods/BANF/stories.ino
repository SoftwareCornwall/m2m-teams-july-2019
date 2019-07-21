void forward_eight(){
  forward2metres();
  
  right_square(false);  //square with turns right without last turn

  left_square(false);
  
  digitalWrite(LIN1, LOW);  //stops
  digitalWrite(RIN3, LOW);
  
}

void backwards_eight(){
  backwards_left_square(false);     //squares without last turns
  backwards_right_square(false);
  digitalWrite(LIN1, LOW);          //stops
  digitalWrite(LIN2, LOW);
  digitalWrite(RIN3, LOW);
  digitalWrite(RIN4, LOW);
}

void forward2metres() {
  analogWrite(LOn, LS);   // turn the left Motor on (HIGH is the voltage level)                         
  analogWrite(ROn, RS);    // turn the right Motor off by making the voltage LOW                     
  digitalWrite(LIN1, HIGH);  //moves forwards
  digitalWrite(RIN3, HIGH);
  digitalWrite(LIN2, LOW);   //doesn't move backwards
  digitalWrite(RIN4, LOW);

  if(millis() > 8500)         //stop and exit when 2 meters (8.5 seconds) are over
  {
   digitalWrite(LIN1, LOW);
   digitalWrite(RIN3, LOW);
   digitalWrite(LIN2, LOW);
   digitalWrite(RIN4, LOW);
   analogWrite(LOn, 0);                          
   analogWrite(ROn, 0);
   exit(0);
  }
  
  Serial.println("left");    //prints speed
  Serial.println(LS);
  Serial.println("right");
  Serial.println(RS);

  if(leftcounter > rightcounter+threshhold)  //threshhold so that speed is only changed at a major difference
  {
    LS=190;
  }
  else if(leftcounter+threshhold < rightcounter)
  {                                                       
    LS=210;
  }
  else
  {
    LS=200;
  }
}
