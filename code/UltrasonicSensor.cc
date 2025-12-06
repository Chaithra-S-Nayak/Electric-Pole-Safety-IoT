float cm = 0;  // Store the distance in centimeters

// Function to measure distance using the ultrasonic sensor
long readUltraSonicDistance(int triggerPin, int echoPin) {
  // Set the trigger pin as OUTPUT and send a trigger pulse
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);  // Ensure it's low for 2 microseconds
  digitalWrite(triggerPin, HIGH);  // Trigger the ultrasonic burst
  delayMicroseconds(10);  // 10 microseconds pulse duration
  digitalWrite(triggerPin, LOW);

  // Set the echo pin as INPUT to receive the reflected signal
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);  // Measure the duration of the echo pulse
}

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  // Calculate distance in centimeters
  long duration = readUltraSonicDistance(8, 9);
  cm = duration * 0.034 / 2;  // Speed of sound is 0.034 cm/us, divided by 2 for the round trip

  // Print the distance to the serial monitor
  Serial.print(cm);
  Serial.println(" cm");

  // Delay before the next reading
  delay(100);
}
