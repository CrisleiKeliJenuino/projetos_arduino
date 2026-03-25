/***************************************************************
* Display de 7 Segmentos
* Mostra uma contagem de 0 a 9 no display
****************************************************************/

// pinos onde cada segmento está conectado

#define pino_a 12
#define pino_b 11
#define pino_c 10
#define pino_d 9
#define pino_e 8
#define pino_f 6
#define pino_g 7

// configurar cada segmento como saída
void setup() {
digitalWrite(pino_a, OUTPUT);
digitalWrite(pino_b, OUTPUT);
digitalWrite(pino_c, OUTPUT);
digitalWrite(pino_d, OUTPUT);
digitalWrite(pino_e, OUTPUT);
digitalWrite(pino_f, OUTPUT);
digitalWrite(pino_g, OUTPUT);
}

void loop() {
// acende os segmento necessarios para formar o número 0 (zero)
digitalWrite(pino_a, HIGH);
digitalWrite(pino_b, HIGH);
digitalWrite(pino_c, HIGH);
digitalWrite(pino_d, HIGH);
digitalWrite(pino_e, HIGH);
digitalWrite(pino_f, HIGH);
digitalWrite(pino_g, LOW);
delay(1000);

// acende os segmento necessarios para formar o número 1
digitalWrite(pino_a, LOW);
digitalWrite(pino_b, HIGH);
digitalWrite(pino_c, HIGH);
digitalWrite(pino_d, LOW);
digitalWrite(pino_e, LOW);
digitalWrite(pino_f, LOW);
digitalWrite(pino_g, LOW);
delay(1000);

// acende os segmento necessarios para formar o número 2
digitalWrite(pino_a, HIGH);
digitalWrite(pino_b, HIGH);
digitalWrite(pino_c, LOW);
digitalWrite(pino_d, HIGH);
digitalWrite(pino_e, HIGH);
digitalWrite(pino_f, LOW);
digitalWrite(pino_g, HIGH);
delay(1000);

// acende os segmento necessarios para formar o número 3
digitalWrite(pino_a, HIGH);
digitalWrite(pino_b, HIGH);
digitalWrite(pino_c, HIGH);
digitalWrite(pino_d, HIGH);
digitalWrite(pino_e, LOW);
digitalWrite(pino_f, LOW);
digitalWrite(pino_g, HIGH);
delay(1000);

// acende os segmento necessarios para formar o número 4
digitalWrite(pino_a, LOW);
digitalWrite(pino_b, HIGH);
digitalWrite(pino_c, HIGH);
digitalWrite(pino_d, LOW);
digitalWrite(pino_e, LOW);
digitalWrite(pino_f, HIGH);
digitalWrite(pino_g, HIGH);
delay(1000);

// acende os segmento necessarios para formar o número 5
digitalWrite(pino_a, HIGH);
digitalWrite(pino_b, LOW);
digitalWrite(pino_c, HIGH);
digitalWrite(pino_d, HIGH);
digitalWrite(pino_e, LOW);
digitalWrite(pino_f, HIGH);
digitalWrite(pino_g, HIGH);
delay(1000);

// acende os segmento necessarios para formar o número 6
digitalWrite(pino_a, LOW);
digitalWrite(pino_b, LOW);
digitalWrite(pino_c, HIGH);
digitalWrite(pino_d, HIGH);
digitalWrite(pino_e, HIGH);
digitalWrite(pino_f, HIGH);
digitalWrite(pino_g, HIGH);
delay(1000);

// acende os segmento necessarios para formar o número 7
digitalWrite(pino_a, HIGH);
digitalWrite(pino_b, HIGH);
digitalWrite(pino_c, HIGH);
digitalWrite(pino_d, LOW);
digitalWrite(pino_e, LOW);
digitalWrite(pino_f, LOW);
digitalWrite(pino_g, LOW);
delay(1000);

// acende os segmento necessarios para formar o número 8
digitalWrite(pino_a, HIGH);
digitalWrite(pino_b, HIGH);
digitalWrite(pino_c, HIGH);
digitalWrite(pino_d, HIGH);
digitalWrite(pino_e, HIGH);
digitalWrite(pino_f, HIGH);
digitalWrite(pino_g, HIGH);
delay(1000);

// acende os segmento necessarios para formar o número 9
digitalWrite(pino_a, HIGH);
digitalWrite(pino_b, HIGH);
digitalWrite(pino_c, HIGH);
digitalWrite(pino_d, LOW);
digitalWrite(pino_e, LOW);
digitalWrite(pino_f, HIGH);
digitalWrite(pino_g, HIGH);
delay(1000);
}
