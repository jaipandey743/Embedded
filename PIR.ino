int pirPin = 13;   // PIR sensor on GPIO 13
int ledPin = 14;   // LED on GPIO 14

void setup() {
  Serial.begin(9600);       
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("PIR Sensor Test Started");
}

void loop() {
  int motion = digitalRead(pirPin);
  
  if (motion == HIGH) {      
    Serial.println("Motion detected!");
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No motion detected");
  }
  
  delay(100);
}