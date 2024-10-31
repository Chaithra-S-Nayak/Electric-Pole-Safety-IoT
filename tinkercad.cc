const int voltagePin = A0; // Potentiometer connected to A0
const int trigPin = 2;
const int echoPin = 3;
const int ledPin = 4;
const int buzzerPin = 5;

float voltageThreshold = 2.5; // Set threshold voltage (adjust as needed)
float distanceThreshold = 200.0; // Safe distance in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float voltage = analogRead(voltagePin) * (5.0 / 1023.0); // Read voltage from potentiometer
  Serial.println(voltage);
  float distance = getDistance();

  if (voltage > voltageThreshold && distance < distanceThreshold) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Warning: High Voltage Detected!");
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.034) / 2;
  return distance;
}
