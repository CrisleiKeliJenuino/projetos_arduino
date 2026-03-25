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

//Declaração de váriavel que armazena o código de autenticação para conexão
char auth[] = BLYNK_AUTH_TOKEN;

//Declaração do nome e senha da rede wi-fi. Altere as variaveis abaixo com o nome e senha da sua rede wi-fi
char ssid[] = "R124";
char pass[] = "R124@redes";

int led = 2;

BLYNK_WRITE(V0){
  int pinValue = param.asInt(); //Lê o valor do pino virtual
  digitalWrite(led, pinValue); // Aciona o LED da placa de acordo com o valor lido pelo pino virtual
}

void setup() {
  Serial.begin(115200); // Inicialização do montor serial
  pinMode(led, OUTPUT); // Initialize digitl pin LED da placa de acordo com o valor lido pelo pino virtual
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 8080); //Incicilização da comunicação e conexão do módulo ao aplicativo
}

void loop() {
  delay(1000); //wait for a second
  Blynk.run(); //Mantém a conexão ativa com o aplicativo e processa comandos recebidos ou enviados
}
