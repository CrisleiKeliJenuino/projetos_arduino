// Usando um sensor de distância

float distancia;
int trig = 11;
int echo = 10;
int som =6;
int freq = 200;

// LED RGB
const byte R = 4;
const byte G = 2;
const byte B = 3;

void setup()
{
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(som, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delay(5); 
  digitalWrite(trig, HIGH);
  delay(10); 
  digitalWrite(trig, LOW);
  
  distancia = pulseIn(echo, HIGH);
  float dist = distancia / 58;
  
  if (dist > 20) {
    verde();
    tone(som, freq);
    delay(1000);
    noTone(som);
    delay(1000);
  }
  else if (dist > 10 && dist <= 20){
    amarelo();
    tone(som, freq);
    delay(500);
    noTone(som);
    delay(500);
  }
  else if (dist <= 10){
    vermelho();
    tone (som, freq);
  }
  else {
  	apaga();
  }
  
  Serial.print("Distancia: ");
  Serial.println(dist);
 }

// funções de cores do led
void vermelho(){
	  analogWrite(R, 255);
  	analogWrite(G, 0);
  	analogWrite(B, 0);
}
// funções de cores do led
void verde(){
	  analogWrite(R, 0);
  	analogWrite(G, 255);
  	analogWrite(B, 0);
}
void amarelo(){
	  analogWrite(R, 255);
  	analogWrite(G, 255);
  	analogWrite(B, 0);
}
void apaga(){
	  analogWrite(R, 0);
  	analogWrite(G, 0);
  	analogWrite(B, 0);
}
