
void passorfail(int png,bool passval){
  fpng = png; 
  if (obstacle() == passval){
    Serial.println("pass");
  }
  else {
    Serial.println("fail");
  }  
}

void unitTest() {
  Serial.println("Running unit test\a\a\a");
  Serial.println("Checking for obstacle within 15cm of the rover.");
  passorfail(4, true);
  
  Serial.println("Checking if no obstacle is present");
  passorfail(0 , false);
  
  Serial.println("Checking if obstacle is pass 15cm of the rover");
  passorfail(15, false); 

  while(true) {}
}
