#include <Wire.h>
#include <MPU9250.h>

// Pinos I2C
#define SCL_PIN 22
#define SDA_PIN 21

// Objeto MPU6050
MPU9250 mpu;

void setup() {
  // Inicializa o sensor MPU6050
  Serial.begin(115200);
  // Inicializa a comunicação I2C
  Wire.begin(SDA_PIN, SCL_PIN);
  delay(2000);

  mpu.setup(0x68);  // change to your own address
  delay(3000);

  // calibrate 
  mpu.calibrateAccelGyro();
}

void loop() {
  // Lê os valores dos acelerômetros
  float accX = mpu.getAccX();
  float accY = mpu.getAccY();
  float accZ = mpu.getAccZ();

  // Lê os valores do giroscópio
  float gyroX = mpu.getGyroX();
  float gyroY = mpu.getGyroY();
  float gyroZ = mpu.getGyroZ();

  // Lê os valores da aceleração linear
  float linearAccX = mpu.getLinearAccX();
  float linearAccY = mpu.getLinearAccY();
  float linearAccZ = mpu.getLinearAccZ();

  // Exibe os valores lidos
  Serial.print("Acelerometro X: "); Serial.println(accX);
  Serial.print("Acelerometro Y: "); Serial.println(accY);
  Serial.print("Acelerometro Z: "); Serial.println(accZ);
  Serial.print("Giroscopio X: "); Serial.println(gyroX);
  Serial.print("Giroscopio Y: "); Serial.println(gyroY);
  Serial.print("Giroscopio Z: "); Serial.println(gyroZ);
  Serial.print("Aceleracao Linear X: "); Serial.println(linearAccX);
  Serial.print("Aceleracao Linear Y: "); Serial.println(linearAccY);
  Serial.print("Aceleracao Linear Z: "); Serial.println(linearAccZ);

  delay(1000); // Aguarda 1 segundo antes de fazer a próxima leitura
}
