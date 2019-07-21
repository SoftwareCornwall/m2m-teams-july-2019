int forwardL = 8;
int reverseL = 7;
int enableL = 9;

int forwardR = 12;
int reverseR = 11;
int enableR = 10;
int motorL = 200;
int motorR = 255;
                                                     
const int feedbackL = 2;
const int feedbackR = 3;

volatile int counterL = 0;
volatile int counterR = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(forwardL, OUTPUT);
  pinMode(forwardR, OUTPUT);
  pinMode(reverseL, OUTPUT);
  pinMode(reverseR, OUTPUT);
  pinMode(enableL, OUTPUT);
  pinMode(enableR, OUTPUT);
  
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(feedbackL),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(feedbackR),RightMotorISR,RISING);  
}

// the loop function runs over aint reverseL = 7;int reverseL = 7;nd over again forever
void loop() {
  forward(10000);
     // turn the LED off by making the voltage LOW
                  // wait for a second
  digitalWrite(forwardL, LOW);
  digitalWrite(forwardR, LOW);

  delay(1000);
 
  digitalWrite(reverseL, HIGH);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(reverseR, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(reverseL, LOW);
  digitalWrite(reverseR, LOW);

  delay(1000);

  
  Serial.println(counterL);
  Serial.print(counterL);

  Serial.println(counterR);
  Serial.print(counterR);
}

void forward(int delaytime)
{
    analogWrite(enableL, motorL);
  analogWrite(enableR, motorR);
  
  digitalWrite(forwardL, HIGH);   // turn the LED on (HIGH is the voltage level)                     // wait for a second
  digitalWrite(forwardR, HIGH);    // turn the LED off by making the voltage LOW
  delay(delaytime);
}

void LeftMotorISR(){
  counterL++;
  
  
}
void RightMotorISR(){
  counterR++;
}





























                                                                
