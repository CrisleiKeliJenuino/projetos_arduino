#define sensorPin A0 // Entrada analogica do potenciometro
#define analogOutPin 6 // Saída PWM onde o LED está conectado
int sensorValue = 0; // Variável inteiro igua a zero
float voltage; // Variável Número Fracionário
int outputValue = 0; // Leira da Saída PWm

void setup() {
 Serial.begin(9600); // Monitor Serial - Velocidade 9600 Bps
 delay(100); // Atraso de 100 Milisegundos
}

void loop() {
sensorValue = analogRead(sensorPin); // Leitura da Entrada Analógica A0
// Mapeia o Resultado da Entrada Analógica Dentro do Intervalo de 0 a 255
outputValue = map(sensorValue, 0, 1023, 0, 255);
analogWrite(analogOutPin, outputValue);
voltage = sensorValue * (5.0 / 1024); // Cálculo da Tensão
Serial.print("Tensão do Potenciometro: "); // Imprime no Monitor Serial
Serial.print(voltage); // Imprime a Tensão
Serial.print(" Valor: ");
Serial.println(sensorValue); // Imprime o Valor
delay(500); // Atraso de 500 Milisegundos
}
