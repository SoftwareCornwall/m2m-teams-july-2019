const int feedbackL = 2;
const int feedbackR = 3;

int motorLfwd = 8;
int motorLbck = 7;
int motorLenb = 9;
int motorLspd = 200;

int motorRfwd = 12;
int motorRbck = 11;
int motorRenb = 10;
int motorRspd = 200;

volatile int counterL = 0;
volatile int counterR = 0;

void setup() 
{
  pinMode(motorLfwd, OUTPUT);
  pinMode(motorLbck, OUTPUT);
  pinMode(motorLenb, OUTPUT);
  pinMode(motorRfwd, OUTPUT);
  pinMode(motorRbck, OUTPUT);
  pinMode(motorRenb, OUTPUT);
  
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(feedbackL),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(feedbackR),RightMotorISR,RISING);
}

void loop() {
  fwd10();
  Serial.println(counterL);
  Serial.print(counterL);

  Serial.println(counterR);
  Serial.print(counterR);
  if (counterL < counterR) {
    motorLspd = motorLspd + 1;
    motorRspd = motorRspd - 1;
  }
  if (counterL > counterR) {
    motorLspd = motorLspd - 1;
    motorRspd = motorRspd + 1;
  }
    

}

void LeftMotorISR(){
  counterL++;
  
  
}
void RightMotorISR(){
  counterR++;
}

void fwd10(){
  analogWrite(motorLenb, motorLspd);
  analogWrite(motorRenb, motorRspd);
  
  digitalWrite(motorLfwd, HIGH);
  digitalWrite(motorRfwd, HIGH);
  if (millis() > 10000){
    analogWrite(motorLfwd, 0);
    analogWrite(motorRfwd, 0);
    
  }
  
}

