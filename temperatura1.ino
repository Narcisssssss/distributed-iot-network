#include <Wire.h>
#include <Adafruit_SHT31.h>

Adafruit_SHT31 sht30 = Adafruit_SHT31();

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // SDA, SCL
  if (!sht30.begin(0x44)) {
    Serial.println("SHT30 nu a fost gasit!");
    while (1);
  }
}

void loop() {
  float t = sht30.readTemperature();
  float h = sht30.readHumidity();
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" C");
  Serial.print("Umiditate: ");
  Serial.print(h);
  Serial.println(" %");
  delay(2000);
}