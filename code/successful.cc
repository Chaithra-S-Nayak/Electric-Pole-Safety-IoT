
#include <Wire.h>
#include <LiquidCrystal_I2C.h>




// Define pins for voltage sensor
const int sensorPin = A0;  // Analog pin connected to the voltage sensor




// Define scaling factor and reference voltage
const float scalingFactor = 5.0;  // Scaling factor for 0-25V sensor
const float referenceVoltage = 5.0; // Arduino reference voltage (e.g., 5V for Uno)
const float voltageThreshold = 0.2; // Threshold voltage to trigger distance check




// Define pins for ultrasonic sensor
const int trigPin = 2;
const int echoPin = 3;
const float distanceThreshold = 200.0; // Threshold distance in cm to trigger alert




// Define pin for buzzer
const int buzzerPin = 4;  // Pin connected to buzzer




// Initialize LCD (change address if necessary)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16 columns and 2 rows




void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);




  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello");
 
  // Set up the ultrasonic sensor pins
  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);
 
  // Set up the buzzer pin
  pinMode(buzzerPin, OUTPUT);
}




void loop() {
  // Read voltage from the sensor
  int sensorValue = analogRead(sensorPin);
  float voltage = (sensorValue * referenceVoltage) / 1023.0;
  float actualVoltage = voltage * scalingFactor;
 
  // Display voltage on the serial monitor
  Serial.print("Voltage: ");
  Serial.print(actualVoltage);
  Serial.println(" V");




  // Check if voltage is above the threshold
  if (actualVoltage > voltageThreshold) {
  // Voltage is high, proceed to check distance
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Alert: Obj. Near!");
  Serial.println("HIGH VOLTAGE");




  float distance = getDistance();




   
  // Display distance on the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
   
  if (distance >0 && distance < distanceThreshold) {
    // Object is near, activate buzzer
    // digitalWrite(buzzerPin, HIGH);
    Serial.println("Warning: High Voltage & Object Detected!");
  } else {
    // No object near, turn on LCD to display voltage
  //  digitalWrite(buzzerPin, LOW);
    Serial.println("Voltage High, No Object Near.");
  }
  } else {
  // Voltage is low, do nothing
// lcd.clear();
  digitalWrite(buzzerPin, LOW);
  Serial.println("Voltage Normal, No Action.");
  }




  // Wait for a short period before next reading
  delay(500);
}




// Function to calculate the distance using the ultrasonic sensor
float getDistance() {
  // Ensure trigger pin is low for 2 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  // Send a 10 microsecond pulse to trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);




  // Read the echo pin, and measure the pulse duration
  long duration = pulseIn(echoPin, HIGH);




  // Convert time into distance (cm)
  float distance = (duration * 0.034) / 2;  // Speed of sound is ~343 m/s or 0.034 cm/us
  return distance;
}
