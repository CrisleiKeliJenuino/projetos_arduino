/*********************************************
* LED blynk.io
*Primeiros Passos com o aplicativo Blynk Iot.
**********************************************/

//Declaração dos parâmetros de conexão do aplicativo
//Alterar os códigos abaixo de acordo com o que foi gerado na platforma
#define BLYNK_TEMPLATE_ID "TMPL2BvCrKaAr"
#define BLYNK_TEMPLATE_NAME "R124A"
#define BLYNK_AUTH_TOKEN "0miq1ANRngW63dp-t-NRVVQKv9EMHrfv"
//Definição do monitoramento de conexão da placa serial
#define BLYNK_PRINT Serial

//Adição das Bibliotecas
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

//Declaração de váriavel que armazena o código de autenticação para conexão
char auth[] = BLYNK_AUTH_TOKEN;

//Declaração do nome e senha da rede wi-fi. Altere as variaveis abaixo com o nome e senha da sua rede wi-fi
char ssid[] = "R124";
char pass[] = "R124@redes";

int led = 2;
const int pino_dht = 4; // pino onde o sensor DHT está conectado
float temperatura; // variável para armazenar o valor de temperatura
float umidade; // variável para armazenar o valor de umidade
DHT dht(pino_dht, DHT11); // define o pino e o tipo de DHT

BLYNK_WRITE(V0){
  int pinValue = param.asInt(); //Lê o valor do pino virtual
  digitalWrite(led, pinValue); // Aciona o LED da placa de acordo com o valor lido pelo pino virtual
}

void setup() {
  Serial.begin(115200); // Inicialização do montor serial
  pinMode(led, OUTPUT); // Initialize digitl pin LED da placa de acordo com o valor lido pelo pino virtual
  dht.begin(); // inicializa o sensor DHT
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 8080); //Incicilização da comunicação e conexão do módulo ao aplicativo
}

void loop() {
  delay(2000); //wait for a second
  temperatura = dht.readTemperature(); // lê a temperatura em Celsius
  umidade = dht.readHumidity(); // lê a umidade
  Blynk.virtualWrite(V1, temperatura);
  Blynk.virtualWrite(V2, umidade);
  Blynk.run(); //Mantém a conexão ativa com o aplicativo e processa comandos recebidos ou enviados
}
