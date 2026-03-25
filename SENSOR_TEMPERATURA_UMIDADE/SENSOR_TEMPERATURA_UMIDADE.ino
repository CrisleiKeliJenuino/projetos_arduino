/**********************************************************************
* ESP32 - Utilizando o DHT11
* Mostrar os valores de Temperatura e Umidade no MOnitor Serial.
***********************************************************************/

// Inclui a biblioteca DHT que possui as funções dos sensores do tipo DHT
// (Adafruit sensor library)
#include "DHT.h"

const int pino_dht = 4; // pino onde o sensor DHT está conectado
float temperatura; // variável para armazenar o valor de temperatura
float umidade; // variável para armazenar o valor de umidade
DHT dht(pino_dht, DHT11); // define o pino e o tipo de DHT

void setup() {
  // Inicia e configura a Serial
  Serial.begin(115200);
  dht.begin(); // inicializa o sensor DHT
}

void loop() {
  // aguarda algunssegundos entre uma leitura e outra
  delay(2000); // 2 segundos (Datasheet)
  // A leitura da temperatura ou umidade pode levar 250ms
  // O atraso do sensor pode chegar a 2 segundos
  temperatura = dht.readTemperature(); // lê a temperatura em Celsius
  umidade = dht.readHumidity(); // lê a umidade

  // Se ocorreu alguma falha durante a leitura
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha na leitura do Sensor DHT!");
  }
  // Se não 
  //Imprime o valor de temperatura
  else {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" *C");

    Serial.print("\t"); // tabulação

    // Imprime o valor de umidade
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print("%\t");

    Serial.println(); // nova lista
  }
}
