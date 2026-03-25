// SERVO MOTOR - POTENCIOMETRO
//Comanda o eixo do servo para a posição 0(referencia)

#include <Servo.h> // Inclui a Biblioteca para servo motor
#define pot A0
int leitura;

Servo servo_motor; // Cria um objeto para o controle do servo

void setup() {
  pinMode(pot, INPUT);
  servo_motor.attach(9); // Informa qual o pino será usado para o servo declarado anteriormente
}

void loop() {
  leitura = analogRead(pot); // Faz a leitura do potenciometro
  leitura = map(leitura,0,1023,10,170); // Ajusta a posição do servo de acordo com o potenciometro
  delay(100);
}
