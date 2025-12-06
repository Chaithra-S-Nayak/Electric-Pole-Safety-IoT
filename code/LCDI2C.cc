#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Use the correct I2C address for your LCD (e.g., 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address, columns, and rows

void setup() {
  lcd.begin(16, 2);   // Initialize the LCD with 16 columns and 2 rows
  lcd.backlight();     // Turn on the backlight
  lcd.setCursor(0, 0); // Set cursor to the first row, first column
  lcd.print("Hello, World!");
}

void loop() {
  // No code needed here for this basic example
}
