#include <Wire.h>                             // a library that allows communication with devices using the I2C protocol
#include <LiquidCrystal_I2C.h>               // a library to control the LCD display with I2C
#include <DHT.h>                            // a library that has necessary functions to interact with the DHT11 sensor

LiquidCrystal_I2C lcd(0x27, 16, 2);        // creates an LCD object to handle the LCD screen
#define DHTPIN 9                          // the pin where the DHT11 sensor is connected
#define DHTTYPE DHT11                    // specifies the sensor we are using

DHT dht(DHTPIN, DHTTYPE);              // creates a DHT object to handle the communication with the DHT11 sensor using the specified pin and sensor type

void setup() {
  Serial.begin(9600);                 // Start serial communication for debugging
  lcd.init();                        // Initialize the LCD (Prepares the LCD screen to start displaying information)
  lcd.backlight();                  // Turn on the backlight ( Turns on the backlight of the LCD so you can see the display.)
  dht.begin();                     // Initialize the DHT11 sensor (Prepares the DHT11 sensor to start taking readings.)
}

void loop() {
  delay(2000);                                  // Wait for 2 seconds
  float humidity = dht.readHumidity();         // Read humidity from the sensor
  float temperature = dht.readTemperature();   // Read temperature from the sensor in Celsius

  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  lcd.clear();                  // Clear the LCD screen
  lcd.setCursor(0, 0);         // Set the cursor to the first column of the first row
  lcd.print("Temp: ");        // Display "Temp: " on the LCD
  lcd.print(temperature);    // Display the temperature value
  lcd.print("C");           // Display "C" for Celsius

  lcd.setCursor(0, 1);         // Set the cursor to the first column of the second row
  lcd.print("Humidity: ");    // Display "Humidity: " on the LCD
  lcd.print(humidity);       // Display the humidity value
  lcd.print("%");           // Display "%" for percentage
}
