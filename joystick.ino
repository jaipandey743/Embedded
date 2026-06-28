const int xPin = 34;
const int yPin = 35;
const int swPin = 15;

int xCenter = 0;
int yCenter = 0;
const int threshold = 400;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT_PULLUP);
  
  delay(1000);
  for (int i = 0; i < 50; i++) {
    xCenter += analogRead(xPin);
    yCenter += analogRead(yPin);
    delay(10);
  }
  xCenter /= 50;
  yCenter /= 50;
  
  Serial.println("QYF-860 Axis Detector");
  Serial.println("Move joystick to see which axis");
}

void loop() {
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);
  int swVal = digitalRead(swPin);
  
  int xDev = xVal - xCenter;
  int yDev = yVal - yCenter;
  
  if (swVal == LOW) {
    Serial.println("Z-AXIS (Button Pressed)");
    delay(200);
    return;
  }
  
  if (abs(xDev) > threshold && abs(yDev) > threshold) {
    Serial.println("X & Y AXES (Diagonal)");
  }
  else if (abs(xDev) > threshold) {
    Serial.print("X-AXIS ");
    if (xDev > 0) {
      Serial.println("RIGHT");
    } else {
      Serial.println("LEFT");
    }
  }
  else if (abs(yDev) > threshold) {
    Serial.print("Y-AXIS ");
    if (yDev > 0) {
      Serial.println("DOWN");
    } else {
      Serial.println("UP");
    }
  }
  else {
    static unsigned long lastPrint = 0;
    if (millis() - lastPrint > 2000) {
      Serial.println("NEUTRAL");
      lastPrint = millis();
    }
  }
  
  delay(100);
}