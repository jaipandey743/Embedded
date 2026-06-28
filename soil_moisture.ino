#define SOIL_PIN 34 
#define LED_PIN 2
int sensorValue=0;
void setup(){
  Serial.begin(115200);
  pinMode(SOIL_PIN, INPUT);
  pinMode(LED_PIN,OUTPUT);
}
void loop(){
  sensorValue = analogRead(SOIL_PIN);
  Serial.print("Sensor:");
  Serial.println(sensorValue);
  if(sensorValue > 3000){
    Serial.println("Dry");
    digitalWrite(LED_PIN,HIGH);
  } else if(sensorValue  > 2000){
    Serial.println("Moist");
    digitalWrite(LED_PIN, LOW);
  }
  else {
    Serial.println("Wet");
    digitalWrite(LED_PIN, LOW); 
  }

  delay(500);  
}