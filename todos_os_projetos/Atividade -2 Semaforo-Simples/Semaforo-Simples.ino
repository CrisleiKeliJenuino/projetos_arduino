int ledVd = 10;
int ledAm = 11;
int ledVm = 12;
void setup() {
  pinMode(ledVd, OUTPUT);
  pinMode(ledAm, OUTPUT);
  pinMode(ledVm, OUTPUT);
}

void loop() {
  digitalWrite(ledVd, HIGH);
  digitalWrite(ledVm, LOW);
  delay(1000);

  digitalWrite(ledVd, LOW);
  digitalWrite(ledAm, HIGH);
  delay(1000);

  digitalWrite(ledAm, LOW);
  digitalWrite(ledVm, HIGH);
  delay(1000);
}
