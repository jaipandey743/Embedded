const int mq2Pin = 34;
const int ledPin = 2;

void setup() {
  Serial.begin(9600);
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int rawValue = analogRead(mq2Pin);
  float voltage = rawValue * (3.3 / 4095.0);
  
  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V | Status: ");
  
  if (rawValue < 200) {
    Serial.println("Normal");
    digitalWrite(ledPin, LOW);
  }
  else if (rawValue >= 200 && rawValue < 800) {
    Serial.println("LOW GAS LEAK");
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
  }
  else if (rawValue >= 800 && rawValue < 2000) {
    Serial.println("MEDIUM GAS LEAK");
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPin, HIGH);
delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
  }
  else if (rawValue >= 2000) {
    Serial.println("HIGH GAS LEAK");
    for (int i = 0; i < 20; i++) {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
  }
  
  delay(1000);
}