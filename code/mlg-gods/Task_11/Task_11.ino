// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------


int LOn = 9;
int LIN2 = 7;
int LIN1 = 8;
int ROn = 10;
int RIN4 = 11;
int RIN3 = 12;
int LS = 200;
int RS = 190;


#include <NewPing.h>

#define DOWN_TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define DOWN_ECHO_PIN     17  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.


NewPing sonar(DOWN_TRIGGER_PIN, DOWN_ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.print(sonar.ping_cm());
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

  pinMode(LOn,OUTPUT);
  pinMode(LIN2,OUTPUT);
  pinMode(LIN1,OUTPUT);
  pinMode(ROn,OUTPUT);
  pinMode(RIN4,OUTPUT);
  pinMode(RIN3,OUTPUT);
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  
  analogWrite(LOn, LS);   // turn the left Motor on                        
  analogWrite(ROn, RS);    // turn the right Motor on                    
  digitalWrite(LIN1, HIGH);  //moves forwards
  digitalWrite(RIN3, HIGH);
  digitalWrite(LIN2, LOW);   //doesn't move backwards
  digitalWrite(RIN4, LOW);

  if(sonar.ping_cm()>12){         //turns if object too close in front of robot
    digitalWrite(LIN1, LOW);
    digitalWrite(RIN3, LOW);
    digitalWrite(LIN2, HIGH);
    digitalWrite(RIN4, HIGH);
    delay(600);
    digitalWrite(LIN2, LOW);
    digitalWrite(RIN4,LOW);
    exit(0);
  }
}
