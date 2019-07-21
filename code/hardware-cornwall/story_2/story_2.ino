int ledgreen = 2, ledred = 3;

void setup() {
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT);
}

void loop() {
  digitalWrite(ledgreen, LOW);
  delay(1000); 
  digitalWrite(ledgreen, HIGH);
  //delay(1000);  
  digitalWrite(ledred, LOW);
  delay(1000); 
  digitalWrite(ledred, HIGH);
  //delay(1000); 
}
