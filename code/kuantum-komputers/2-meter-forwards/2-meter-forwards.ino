
int right_motor_feedback = 3;
int left_motor_feedback = 2;
int ultrasonic_fwd_trigger = 4;
int ultrasonic_fwd_echo = 5;
int reserved_for_servo = 6;
int left_motor_reverse = 7;
int left_motor_forwards = 8;
int left_motor_enabler = 9;
int right_motor_enabler = 10;
int right_motor_reverse = 11;
int right_motor_forwards = 12;
int motorspeedR = 175;
int motorspeedL = 175;
int thresholdL = 5;
int thresholdR = 10;
volatile int rightcounter = 0; //counter starts at 0 revolutions per second
volatile int leftcounter = 0;
int timedelay = 0;
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(left_motor_reverse, OUTPUT);
  pinMode(left_motor_forwards, OUTPUT);
  pinMode(left_motor_enabler, OUTPUT);
  pinMode(right_motor_enabler, OUTPUT);
  pinMode(right_motor_reverse, OUTPUT);
  pinMode(right_motor_forwards, OUTPUT);
  countersLR();
  
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);                       // wait for a second
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);
  // wait for a second  
  //blue=reverse, red=forward
  //test 
  //roverforward(500);
    analogWrite(left_motor_enabler, motorspeedL);
    analogWrite(right_motor_enabler,motorspeedR);
    digitalWrite(left_motor_forwards, LOW);
    digitalWrite(right_motor_forwards, LOW);
    delay(500);
    digitalWrite(left_motor_forwards, HIGH);
    digitalWrite(right_motor_forwards, HIGH);
    while (timedelay < 100) {
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
        delay(100);
        timedelay = timedelay + 1;
   if (millis() > 10000) {
     analogWrite(left_motor_enabler, LOW);
     analogWrite(right_motor_enabler,LOW);
        }
      }
    /*digitalWrite(left_motor_forwards, LOW);
    digitalWrite(right_motor_forwards, LOW);
    delay(1000);
    digitalWrite(left_motor_reverse, HIGH);
    digitalWrite(right_motor_reverse, HIGH);
    delay(1000);*/
}
  
void countersLR()
{
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
void roverforward(int delaytime)
{ 
    digitalWrite(left_motor_forwards, LOW);
    digitalWrite(right_motor_forwards, LOW);
    analogWrite(left_motor_enabler, motorspeedL);
    analogWrite(right_motor_enabler,motorspeedR);
    delay(delaytime);
}




