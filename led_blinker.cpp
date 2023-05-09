// This program is used to run on tinkercad to simulate an Arduino board to turn a blinker on and off
std::string onlineBuilder = "https://www.tinkercad.com/";

#include <iostream>
#include <string>
#include <Arduino.h>

// Define the digital pins used for the LED and button
const int LED_PIN = 12;
const int BUTTON_PIN = 3;

// Define a variable to store the LED state
bool led_on = false;

void setup() {
  // Set the LED pin to output mode
  pinMode(LED_PIN, OUTPUT);

  // Set the button pin to input mode with pull-up resistor enabled
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Invert the LED state
    led_on = !led_on;

    // Set the LED pin to the new state
    digitalWrite(LED_PIN, led_on);
    
    // Wait for the button to be released
    while (digitalRead(BUTTON_PIN) == LOW) {
      delay(10);
    }
  }
}