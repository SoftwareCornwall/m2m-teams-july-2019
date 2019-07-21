int LOn = 9;
int LIN2 = 7;
int LIN1 = 8;
int ROn = 10;
int RIN4 = 11;
int RIN3 = 12;
int LS = 200;
int RS = 190;
int threshhold = 10;


#include <NewPing.h>

#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define light_sensor_right 2
#define light_sensor_middle 6
#define light_sensor_left 7

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
 // Serial.print(sonar.ping_cm());
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

 
  pinMode(LOn,OUTPUT);
  pinMode(LIN2,OUTPUT);
  pinMode(LIN1,OUTPUT);
  pinMode(ROn,OUTPUT);
  pinMode(RIN4,OUTPUT);
  pinMode(RIN3,OUTPUT);
  pinMode(light_sensor_right, INPUT);
  pinMode(light_sensor_middle, INPUT);
  pinMode(light_sensor_left, INPUT);

  Serial.print(light_sensor_left);
  Serial.print(light_sensor_middle);
  Serial.print(light_sensor_right);
}

void loop() {
  int left_light = analogRead(light_sensor_left);
  int middle_light = analogRead(light_sensor_middle);
  int right_light = analogRead(light_sensor_right);
  
    analogWrite(LOn, LS);   // turn the left Motor on (HIGH is the voltage level)                         
    analogWrite(ROn, RS);
    if(left_light < 350 || middle_light< 350 || right_light < 350){
      if(middle_light < left_light && middle_light < right_light){
        digitalWrite(LIN1, HIGH);
        digitalWrite(RIN3, HIGH);
        digitalWrite(LIN2, LOW);
        digitalWrite(RIN4, LOW);
      }
      else if(left_light < middle_light && left_light < right_light){
        digitalWrite(LIN1, LOW);
        digitalWrite(LIN2, HIGH);
        digitalWrite(RIN3, HIGH);
        digitalWrite(RIN4, LOW);
      
      }
      else if(right_light < middle_light && right_light < left_light){
        digitalWrite(LIN2, LOW);
        digitalWrite(LIN1, HIGH);
        digitalWrite(RIN4, HIGH);
        digitalWrite(RIN3, LOW);

      } 
    }
    else {
      digitalWrite(LIN2, LOW);
      digitalWrite(LIN1, HIGH);
      digitalWrite(RIN4, HIGH);
      digitalWrite(RIN3, LOW);
    }
}

void stop_before_obstcale(){
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  
  analogWrite(LOn, LS);   // turn the left Motor on (HIGH is the voltage level)                         
  analogWrite(ROn, RS);    // turn the right Motor off by making the voltage LOW                     
  digitalWrite(LIN1, HIGH);  //moves forwards
  digitalWrite(RIN3, HIGH);
  digitalWrite(LIN2, LOW);   //doesn't move backwards
  digitalWrite(RIN4, LOW);

 if(sonar.ping_cm()<15 && sonar.ping_cm() > 0){
    digitalWrite(LIN1, LOW);
    digitalWrite(LIN2, HIGH);
    delay(1000);
    digitalWrite(LIN2, LOW);
    digitalWrite(RIN3,LOW);
    exit(0);
  }
}

