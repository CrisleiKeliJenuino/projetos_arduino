// Testando o sensor LDR COM LED
#define pinoLDR A0 // Pino de conexõ do LDR
#define pinoLED 7 // Pino onde o LED está conectado
int leitura = 0;  // váriavel para armazenar o valor lido pedo ADC


void setup() {
  // Inicia e configura a saída seral
  Serial.begin(9600); // 9600 bps

  // Configura o pino com LDR entrada
  pinMode(pinoLDR, INPUT); // Pino A0-+
}

void loop() {
  // Lê o valor de tensão no pino do LDR
  leitura = analogRead(pinoLDR);

  //Imprime valor lideo pelo arduino (0 a 1023)
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.println();

// Verifica Luminosidade do ambiente
if(leitura < 400){
  digitalWrite(pinoLED, HIGH); // Acende o LED
}
else{
  digitalWrite(pinoLED, LOW); // Apaga o LED
}
  delay(1000); // Aguarda 1 segundo para a próxima Leitura

}
