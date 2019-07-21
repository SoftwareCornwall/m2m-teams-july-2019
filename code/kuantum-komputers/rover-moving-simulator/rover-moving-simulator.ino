
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
    digitalWrite(left_motor_reverse, LOW);
    digitalWrite(right_motor_reverse, LOW);
    digitalWrite(left_motor_enabler, HIGH);
    digitalWrite(right_motor_enabler, HIGH);
    delay(1000);
    digitalWrite(left_motor_forwards, HIGH);
    digitalWrite(right_motor_forwards, HIGH);
    delay(1000);
    digitalWrite(left_motor_forwards, LOW);
    digitalWrite(right_motor_forwards, LOW);
    delay(1000);
    digitalWrite(left_motor_reverse, HIGH);
    digitalWrite(right_motor_reverse, HIGH);
    delay(1000);

} 

