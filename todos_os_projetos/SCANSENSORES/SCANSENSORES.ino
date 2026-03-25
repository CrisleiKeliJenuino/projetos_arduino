#include <Wire.h>

TwoWire I2C_1 = TwoWire(1);  // pinos 19 (SDA), 18 (SCL)
TwoWire I2C_2 = TwoWire(2);  // pinos 4 (SDA), 5 (SCL)

void scanBus(TwoWire &bus, const char* nome, int sda, int scl) {
  Serial.printf("\nEscaneando %s (pinos SDA %d / SCL %d)...\n", nome, sda, scl);
  bus.begin(sda, scl);
  byte count = 0;

  for (byte address = 1; address < 127; address++) {
    bus.beginTransmission(address);
    if (bus.endTransmission() == 0) {
      Serial.printf("Dispositivo I2C encontrado no endereco 0x%02X\n", address);
      count++;
    }
    delay(2);
  }

  if (count == 0) {
    Serial.println("Nenhum dispositivo encontrado.");
  } else {
    Serial.printf("Total encontrado: %d\n", count);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Scan barramento padrão (Wire) - OLED
  scanBus(Wire, "Wire", 21, 22);

  // Scan I2C_1 - MLX90614 ou outro
  scanBus(I2C_1, "I2C_1", 19, 18);

  // Scan I2C_2 - MAX30102 ou outro
  scanBus(I2C_2, "I2C_2", 4, 5);
}

void loop() {
  // Nada no loop
}
