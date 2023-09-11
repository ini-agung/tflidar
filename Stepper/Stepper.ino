int PUL = 22; //define Pulse pin
int DIR = 19; //define Direction pin
int ENA = 21; //define Enable Pin
void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
}


void loop() {
  for (int i = 0; i < 200; i++) //Forward 5000 steps
  {
    digitalWrite(DIR, LOW);
    digitalWrite(ENA, HIGH);
    digitalWrite(PUL, HIGH);
    delayMicroseconds(150);
    digitalWrite(PUL, LOW);
    delayMicroseconds(150);
  }
  delay(500);
  for (int i = 0; i < 200; i++) //Forward 5000 steps
  {
    digitalWrite(DIR, HIGH);
    digitalWrite(ENA, HIGH);
    digitalWrite(PUL, HIGH);
    delayMicroseconds(150);
    digitalWrite(PUL, LOW);
    delayMicroseconds(150);
  }
  delay(500);
}
