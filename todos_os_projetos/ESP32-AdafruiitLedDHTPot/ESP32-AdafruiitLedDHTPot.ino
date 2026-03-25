/*******************************************************************************
* Hello Adafruit (LED, POTENCIOMETRO, TEMPERATURA E UMIDADE)
* Projeto IoT com o Dashboard Adafruit.
*******************************************************************************/

//Declaracao dos parametros de conexao do aplicativo
//Alterar os codigos abaixo de acordo com o que foi gerado na plataforma
#define AIO_USERNAME  "CrisleiKeli"
#define AIO_KEY       "aio_atxB17ZkfVPoqjo75yCBm1Lg73X3"
#define AIO_SERVER  "io.adafruit.com" //Comentar essa linha para broker local
//#define AIO_SERVER  "10.67.22.205" //Descomentar essa linha para broker local
#define AIO_SERVERPORT 1883
/************************* WiFi Access Point *********************************/
#define WLAN_SSID       "R124"
#define WLAN_PASS       "R124@redes"

//Adicao das bibliotecas
#include <DHT.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <WiFi.h>
#include <WiFiClient.h>

//Definindo variáveis
#define DHTPIN 4         //GPIO do Sensor de Temperatura/Umnidade (DHT11)
#define DHTTYPE DHT11    // Definindo o modelo do DHT
DHT dht(DHTPIN, DHTTYPE);
const int _led = 2;
int _potenciometro = 34;

WiFiClient client; // Instanciando o objeto client, responsável pela conexão de rede

//Inicializacao da comunicacao e conexao do modulo MQTT ao broker
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
#define halt(s) { Serial.println(F( s )); while(1);} 

Adafruit_MQTT_Subscribe led = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/led");
Adafruit_MQTT_Publish temperature = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/temperatura"); 
Adafruit_MQTT_Publish humidity = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/umidade"); 
Adafruit_MQTT_Publish potenciometro = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/potenciometro"); 

void MQTT_connect();

void setup(){
  dht.begin(); // inicializa o sensor DHT
  pinMode(_led, OUTPUT);
  pinMode(_potenciometro, INPUT);
 
  Serial.begin(115200);

  Serial.println(F("Adafruit - Inicializando o cliente..."));
  // Conectando ao AP WiFi.
  Serial.println(); Serial.println();
  Serial.print("Conectando em ");
  Serial.print(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println(" WiFi conectado!");
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
  delay(1000);

  mqtt.subscribe(&led); //definindo assinatura do topico com o estado do led
}

uint32_t x=0;

void loop(){
  MQTT_connect();                           
  float umid = (float)dht.readHumidity();       
  float tempe = (float)dht.readTemperature();
  float pot = analogRead(_potenciometro);   

  if (! temperature.publish(tempe))        
    Serial.println(F("Falha na publicação da temperatura")); 
  else                                        
   Serial.print(F("Temperatura publicada: ")); 
   Serial.println(tempe); 

  if (! humidity.publish(umid))  
    Serial.println(F("Falha na publicação da umidade")); 
  else                                                   
    Serial.print(F("Umidade publicada:     "));
    Serial.println(umid);            
  
  if (! potenciometro.publish(pot))  
    Serial.println(F("Falha na publicação do potenciometro")); 
  else                                                   
    Serial.print(F("Potenc publicado:      "));
    Serial.println(pot); 

  Adafruit_MQTT_Subscribe *subscription;                
  while ((subscription = mqtt.readSubscription(1000))) { 

    
    if (subscription == &led) {      
      Serial.print(F("Leitura - LED:         "));
      Serial.println((char *)led.lastread);

      if (!strcmp((char *)led.lastread, "0")) { 
         digitalWrite(_led, LOW);                        
                                                       }
      if (!strcmp((char *)led.lastread, "1")) { 
        digitalWrite(_led, HIGH);                           
                                                          }
                               }
  if(! mqtt.ping()) {      
    mqtt.disconnect();    
                    }
  }
  Serial.println(F("------------------------------------------"));
  delay(10000); //Definindo o tempo de atualização: Adafruit 10 seg (10000) - Local 1 seg (1000)
}

void MQTT_connect() {        
  
  int8_t ret;             


  if (mqtt.connected()) {   
    return;                 
  }

  Serial.print("Conectando MQTT... ");   

  uint8_t retries = 3;      
  while ((ret = mqtt.connect()) != 0) { 
       Serial.println(mqtt.connectErrorString(ret)); 
       Serial.println("Reconectando MQTT em 5s..."); 
       mqtt.disconnect();   
       delay(5000);  
       retries--;     
       if (retries == 0) {
         while (1);
       }
  }
  Serial.print("MQTT Conectado! ");  Serial.println(AIO_SERVER);  
}