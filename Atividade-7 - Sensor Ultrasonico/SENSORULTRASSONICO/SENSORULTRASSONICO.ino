// Usando um sensor de distancia

float distancia;
int trig = 11;
int echo = 10;

void setup() {
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trig, LOW);
delay(5);
digitalWrite(trig, HIGH);
delay(10);
digitalWrite(trig, LOW);

distancia = pulseIn(echo, HIGH);
float dist = distancia / 58;
// float dist = distancia;

Serial.print("Distância: ");
Serial.println(dist);

delay(1000);
}
