#include <Wire.h>

void setup() {
  Wire.begin(); // Inicia a comunicação I2C como mestre

  Serial.begin(9600); // Inicia a comunicação serial para exibir resultados

  delay(1000); // Espera um segundo antes de iniciar a busca

  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) { 
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println(" !");

      nDevices++;
    }
    else if (error==4) {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(5000); // Aguarda 5 segundos antes de reiniciar a busca
}

void loop() {
  // Nenhum código necessário aqui, pois estamos apenas verificando o endereço no setup()
}


