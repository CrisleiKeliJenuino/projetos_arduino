#define LedVd 10
#define LedAm 9
#define LedVm 8
#define tempo 2000
#define botao 0

void setup() {
  // put your setup code here, to run once:
  pinMode(LedVd, OUTPUT);
  pinMode(LedAm, OUTPUT);
  pinMode(LedVm, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  digitalWrite(LedVd, HIGH);
  
}

void loop() {
  if (digitalRead(botao) == LOW){
  delay(tempo);
  semaforo();
  }
 
  // put your main code here, to run repeatedly:

}

void semaforo()
{
  digitalWrite(LedVd, LOW);
  digitalWrite(LedAm, HIGH);
  digitalWrite(LedVm, LOW);
  delay(tempo);

  digitalWrite(LedVm, HIGH);
  digitalWrite(LedAm, LOW);
  delay(tempo);

  digitalWrite(LedVd, HIGH);
  digitalWrite(LedVm, LOW);
  delay(tempo);
}
