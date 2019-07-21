void follow_light(){                                 //general following the light function
 int left_light = analogRead(light_sensor_left);     //reading light intensity
  int middle_light = analogRead(light_sensor_middle);
  int right_light = analogRead(light_sensor_right);
  
    analogWrite(LOn, LS);   // turn the Motor on (HIGH is the voltage level)                         
    analogWrite(ROn, RS);

/*
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
*/    
    if(sonar.ping_cm()>15){       //in case of cliff
      digitalWrite(LIN1, LOW);
      digitalWrite(RIN3, LOW);
      digitalWrite(LIN2, HIGH);
      digitalWrite(RIN4, HIGH);
      delay(600);
      digitalWrite(LIN2, LOW);
      digitalWrite(RIN4,LOW);
 
    }
    delay(50);
    int front_distance = sonar_forward.ping_cm();   
    if(front_distance < 15 && front_distance > 0){       //in case of object infront
      digitalWrite(LIN1, LOW);
      digitalWrite(LIN2, HIGH);
      delay(1000);
      digitalWrite(LIN2, LOW);
      digitalWrite(RIN3,LOW);
    }  
    
    if(left_light < 350 || middle_light< 350 || right_light < 350){    //if bright enough light
      if(middle_light < left_light && middle_light < right_light){     //light forwards brightest, drive forwards
        digitalWrite(LIN1, HIGH);
        digitalWrite(RIN3, HIGH);
        digitalWrite(LIN2, LOW);
        digitalWrite(RIN4, LOW);
      }
      else if(left_light < middle_light && left_light < right_light){   //light left brightest, turn left
        digitalWrite(LIN1, LOW);
        digitalWrite(LIN2, HIGH);
        digitalWrite(RIN3, HIGH);
        digitalWrite(RIN4, LOW);
      
      }
      else if(right_light < middle_light && right_light < left_light){   //light left brightest, turn left
        digitalWrite(LIN2, LOW);
        digitalWrite(LIN1, HIGH);
        digitalWrite(RIN4, HIGH);
        digitalWrite(RIN3, LOW);

      } 
    }
    else {                              //search for light
      digitalWrite(LIN2, LOW);
      digitalWrite(LIN1, HIGH);
      digitalWrite(RIN4, HIGH);
      digitalWrite(RIN3, LOW);
    }
}

void follow_light_until_cliff(){                      //follow light but stop after first cliff
  int left_light = analogRead(light_sensor_left);     //reading light intensity
  int middle_light = analogRead(light_sensor_middle);
  int right_light = analogRead(light_sensor_right);
  
    analogWrite(LOn, LS);   // turn the Motor on (HIGH is the voltage level)                         
    analogWrite(ROn, RS);

/*
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
*/    
    if(sonar.ping_cm()>15){       //in case of cliff
      digitalWrite(LIN1, LOW);
      digitalWrite(RIN3, LOW);
      digitalWrite(LIN2, HIGH);
      digitalWrite(RIN4, HIGH);
      delay(600);
      digitalWrite(LIN2, LOW);
      digitalWrite(RIN4,LOW);
      exit(0);                    //leave loop
 
    }
    delay(50);
    int front_distance = sonar_forward.ping_cm();   
    if(front_distance < 15 && front_distance > 0){       //in case of object infront
      digitalWrite(LIN1, LOW);
      digitalWrite(LIN2, HIGH);
      delay(1000);
      digitalWrite(LIN2, LOW);
      digitalWrite(RIN3,LOW);
      state = 3;
    }  
    
    if(left_light < 350 || middle_light< 350 || right_light < 350){    //if bright enough light
      if(middle_light < left_light && middle_light < right_light){     //light forwards brightest, drive forwards
        digitalWrite(LIN1, HIGH);
        digitalWrite(RIN3, HIGH);
        digitalWrite(LIN2, LOW);
        digitalWrite(RIN4, LOW);
      }
      else if(left_light < middle_light && left_light < right_light){   //light left brightest, turn left
        digitalWrite(LIN1, LOW);
        digitalWrite(LIN2, HIGH);
        digitalWrite(RIN3, HIGH);
        digitalWrite(RIN4, LOW);
      
      }
      else if(right_light < middle_light && right_light < left_light){   //light left brightest, turn left
        digitalWrite(LIN2, LOW);
        digitalWrite(LIN1, HIGH);
        digitalWrite(RIN4, HIGH);
        digitalWrite(RIN3, LOW);

      } 
    }
    else {                              //search for light
      digitalWrite(LIN2, LOW);
      digitalWrite(LIN1, HIGH);
      digitalWrite(RIN4, HIGH);
      digitalWrite(RIN3, LOW);
    }
}



void follow_light_until_wall(){                       //follow light but stop after first cliff
  int left_light = analogRead(light_sensor_left);     //reading light intensity
  int middle_light = analogRead(light_sensor_middle);
  int right_light = analogRead(light_sensor_right);
  
    analogWrite(LOn, LS);   // turn the Motor on (HIGH is the voltage level)                         
    analogWrite(ROn, RS);

/*
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
*/    
    if(sonar.ping_cm()>15){       //in case of cliff
      digitalWrite(LIN1, LOW);
      digitalWrite(RIN3, LOW);
      digitalWrite(LIN2, HIGH);
      digitalWrite(RIN4, HIGH);
      delay(600);
      digitalWrite(LIN2, LOW);
      digitalWrite(RIN4,LOW);
 
    }
    delay(50);
    int front_distance = sonar_forward.ping_cm();   
    if(front_distance < 15 && front_distance > 0){       //in case of object infront
      digitalWrite(LIN1, LOW);
      digitalWrite(LIN2, HIGH);
      digitalWrite(RIN4, HIGH);
      digitalWrite(RIN3,LOW);
      delay(2000);
      digitalWrite(LIN2, LOW);                          //stops
      digitalWrite(RIN4, LOW);
    }  
    
    if(left_light < 350 || middle_light< 350 || right_light < 350){    //if bright enough light
      if(middle_light < left_light && middle_light < right_light){     //light forwards brightest, drive forwards
        digitalWrite(LIN1, HIGH);
        digitalWrite(RIN3, HIGH);
        digitalWrite(LIN2, LOW);
        digitalWrite(RIN4, LOW);
      }
      else if(left_light < middle_light && left_light < right_light){   //light left brightest, turn left
        digitalWrite(LIN1, LOW);
        digitalWrite(LIN2, HIGH);
        digitalWrite(RIN3, HIGH);
        digitalWrite(RIN4, LOW);
      
      }
      else if(right_light < middle_light && right_light < left_light){   //light left brightest, turn left
        digitalWrite(LIN2, LOW);
        digitalWrite(LIN1, HIGH);
        digitalWrite(RIN4, HIGH);
        digitalWrite(RIN3, LOW);

      } 
    }
    else {                              //search for light
      digitalWrite(LIN2, LOW);
      digitalWrite(LIN1, HIGH);
      digitalWrite(RIN4, HIGH);
      digitalWrite(RIN3, LOW);
    }

}


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
  analogWrite(ROn, RS);                        
  digitalWrite(LIN1, HIGH);  //moves forwards
  digitalWrite(RIN3, HIGH);
  digitalWrite(LIN2, LOW);   //doesn't move backwards
  digitalWrite(RIN4, LOW);

  Serial.println(millis());

  if(millis() > 8500)         //stop and exit when 2 meters (8.5 seconds) are over
  {
   digitalWrite(LIN1, LOW);
   digitalWrite(RIN3, LOW);
   digitalWrite(LIN2, LOW);
   digitalWrite(RIN4, LOW);
   analogWrite(LOn, 0);                          
   analogWrite(ROn, 0);
   state = 1;
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
