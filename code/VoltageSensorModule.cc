// Define the analog pin connected to the voltage sensor's signal pin
const int sensorPin = A0;

// Define the scaling factor (depends on the sensor used)
// For a 0-25V voltage sensor, the typical scaling factor is 5 (check the module specifications)
const float scalingFactor = 5.0; //make it as 1.0 and check

// Define the reference voltage of the Arduino (e.g., 5V for Uno)
const float referenceVoltage = 5.0;

void setup() {
  // Initialize serial communication for output
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the sensor pin
  int sensorValue = analogRead(sensorPin);
 
  // Convert the analog value (0 to 1023) to a voltage (0 to referenceVoltage)
  float voltage = (sensorValue * referenceVoltage) / 1023.0;
 
  // Multiply by the scaling factor to get the actual measured voltage
  float actualVoltage = voltage * scalingFactor;
 
  // Print the measured voltage to the Serial Monitor
  Serial.print("Measured Voltage: ");
  Serial.print(actualVoltage);
  Serial.println(" V");

  // Delay for a short period before the next reading
  delay(1000);
}
