#include <Servo.h> // Biblioteca para controle do servo motor

// Declarando o servo motor
Servo cancela;

// Definição dos pinos
int triggerPin = 9;  // Pino digital para o Trigger do sensor ultrassônico
int echoPin = 10;    // Pino digital para o Echo do sensor ultrassônico
int ledRed = 6;      // Pino digital para o LED vermelho do semáforo
int ledYellow = 5;   // Pino digital para o LED amarelo do semáforo
int ledGreen = 4;    // Pino digital para o LED verde do semáforo
int buzzer = 3;      // Pino digital para o buzzer

void setup() {
  // Configuração dos pinos do sensor ultrassônico
  pinMode(triggerPin, OUTPUT); // Trigger como saída (envia sinal)
  pinMode(echoPin, INPUT);     // Echo como entrada (recebe sinal)

  // Configuração dos pinos dos LEDs
  pinMode(ledRed, OUTPUT);     // LED vermelho como saída
  pinMode(ledYellow, OUTPUT);  // LED amarelo como saída
  pinMode(ledGreen, OUTPUT);   // LED verde como saída

  // Configuração do pino do buzzer
  pinMode(buzzer, OUTPUT);     // Buzzer como saída

  // Configuração do servo motor
  cancela.attach(11);          // Servo conectado ao pino digital 11
  cancela.write(0);            // Cancela inicialmente fechada (posição 0º)

  // Inicia o semáforo com o LED vermelho ligado
  digitalWrite(ledRed, HIGH);  // Semáforo indica "parado"
}

void loop() {
  long duration, distance; // Variáveis para armazenar a duração do sinal e a distância

  // Mede a distância
  distance = medirDistancia();

  // Verifica se um objeto está próximo (dentro de 20 cm)
  if (distance > 0 && distance < 20) { 
    // Troca de semáforo para permitir a passagem
    digitalWrite(ledRed, LOW);      // Apaga o LED vermelho
    digitalWrite(ledYellow, HIGH); // Acende o LED amarelo
    delay(2000);                   // Mantém o amarelo por 2 segundos
    digitalWrite(ledYellow, LOW);  // Apaga o LED amarelo
    digitalWrite(ledGreen, HIGH);  // Acende o LED verde

    // Som do buzzer antes de abrir a cancela
    buzzerAlerta();

    // Abre a cancela (gira o servo para 90º)
    cancela.write(90); 
    delay(5000); // Aguarda 5 segundos para o veículo passar

    // Verifica se ainda há um carro na frente antes de fechar a cancela
    while (medirDistancia() > 0 && medirDistancia() < 20) {
      Serial.println("Carro ainda presente. Aguardando saída...");
      delay(500); // Reavalia a cada 500ms
    }

    // Som do buzzer antes de fechar a cancela
    buzzerAlerta();

    // Fecha a cancela (retorna o servo para 0º)
    cancela.write(0);

    // Reseta o semáforo para vermelho
    digitalWrite(ledGreen, LOW);  // Apaga o LED verde
    digitalWrite(ledRed, HIGH);  // Acende o LED vermelho
  }

  // Pequena pausa no loop
  delay(500);
}

// Função para medir a distância usando o sensor ultrassônico
long medirDistancia() {
  long duration, distance;

  // Envia um pulso de 10 microsegundos pelo Trigger para iniciar a medição
  digitalWrite(triggerPin, LOW);  // Garante que o Trigger esteja em LOW
  delayMicroseconds(2);           // Aguarda 2 microssegundos
  digitalWrite(triggerPin, HIGH); // Envia pulso HIGH para o Trigger
  delayMicroseconds(10);          // Mantém o pulso por 10 microssegundos
  digitalWrite(triggerPin, LOW);  // Retorna o Trigger para LOW

  // Mede a duração do pulso refletido (Echo)
  duration = pulseIn(echoPin, HIGH);

  // Calcula a distância com base na duração do pulso
  distance = (duration * 0.034) / 2;

  return distance; // Retorna a distância em cm
}

// Função para controlar o buzzer
// Emite 3 bipes curtos como alerta
void buzzerAlerta() {
  for (int i = 0; i < 3; i++) {     // Laço para repetir 3 vezes
    tone(buzzer, 1000);            // Toca uma frequência de 1000 Hz no buzzer
    delay(200);                    // Dura 200 ms
    noTone(buzzer);                // Para o som
    delay(200);                    // Pausa de 200 ms entre os bipes
  }
}
