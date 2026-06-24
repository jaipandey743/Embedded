#include <DHT.h>
#include <Arduino.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  Serial.print("Temp: ");
  Serial.print(dht.readTemperature());
  Serial.print(" C  Humidity: ");
  Serial.println(dht.readHumidity());
}

// DHT11 by adafruit
// baud: 9600