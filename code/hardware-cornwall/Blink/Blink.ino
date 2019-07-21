int process[] = {2, 5, 3, 6, 4, 7};

void setup() {
  for(int i : process) pinMode(i, OUTPUT);
}

void loop() {
  digitalWrite(process[4], HIGH);
  digitalWrite(process[5], HIGH);
  delay(10000);
  digitalWrite(process[4], LOW);
  digitalWrite(process[5], LOW);
  digitalWrite(process[2], HIGH);
  digitalWrite(process[3], HIGH);
  delay(375);
  digitalWrite(process[2], LOW);
  digitalWrite(process[3], LOW);
  digitalWrite(process[0], HIGH);
  digitalWrite(process[1], HIGH);
  delay(1000);
  digitalWrite(process[0], LOW);
  digitalWrite(process[1], LOW);
  delay(2000);
}
