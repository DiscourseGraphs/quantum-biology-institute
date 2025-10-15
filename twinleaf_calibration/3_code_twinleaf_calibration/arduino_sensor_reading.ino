#include <Wire.h>
#include "Adafruit_VEML7700.h"
#include "Adafruit_HTU21DF.h"

#define TCAADDR 0x70  // I2C address of PCA9548A

Adafruit_VEML7700 veml = Adafruit_VEML7700();
Adafruit_HTU21DF htu = Adafruit_HTU21DF();

void tcaSelect(uint8_t channel) {
  if (channel > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << channel);  // Select channel
  Wire.endTransmission();
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  delay(2000);  // Let Serial initialize
  Serial.println("Setup complete. Starting loop...");
}

void loop() {
  Serial.println("---------- New Reading Loop ----------");

  for (uint8_t channel = 1; channel <= 2; channel++) {
    Serial.print("Selecting multiplexer channel "); Serial.println(channel);
    tcaSelect(channel);
    delay(50); // Pause after switching channels

    Serial.println("Initializing VEML7700...");
    if (!veml.begin()) {
      Serial.print("⚠️  VEML7700 NOT FOUND on channel "); Serial.println(channel);
      continue;
    }

    Serial.println("Initializing HTU21DF...");
    if (!htu.begin()) {
      Serial.print("⚠️  HTU21DF NOT FOUND on channel "); Serial.println(channel);
      continue;
    }

    float lux = veml.readLux();
    float temp = htu.readTemperature();
    float humidity = htu.readHumidity();

    Serial.print("✅ Data from channel "); Serial.println(channel);
    Serial.print("Temp (°C): "); Serial.println(temp);
    Serial.print("Humidity (%): "); Serial.println(humidity);
    Serial.print("Lux: "); Serial.println(lux);

    // CSV-style output
    Serial.print(channel); Serial.print(",");
    Serial.print(temp); Serial.print(",");
    Serial.print(humidity); Serial.print(",");
    Serial.println(lux);
  }

  delay(10000); // Wait 10 seconds before next read
}

