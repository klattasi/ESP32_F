#include <Arduino.h>

// ========================================
// LED Status Blinking Configuration
// ========================================
#define LED_PIN 2                    // GPIO2 - LED Status (Active HIGH)
#define LED_BLINK_INTERVAL 500       // Interval in milliseconds (500ms = 0.5s on, 0.5s off)

// ========================================
// Global Variables
// ========================================
unsigned long lastBlinkTime = 0;     // Last time LED state changed
bool ledState = false;               // Current LED state (false = OFF, true = ON)

// ========================================
// Function Declarations
// ========================================
void initLED();
void updateLED();

// ========================================
// Setup Function
// ========================================
void setup() {
  // Initialize Serial for debugging
  Serial.begin(9600);
  delay(1000);  // Wait for Serial to stabilize
  
  Serial.println("\n\n========================================");
  Serial.println("ESP32 LED Blinking Project");
  Serial.println("========================================");
  Serial.println("LED Pin: GPIO2");
  Serial.println("Blink Interval: " + String(LED_BLINK_INTERVAL) + " ms");
  Serial.println("========================================\n");
  
  // Initialize LED
  initLED();
}

// ========================================
// Main Loop
// ========================================
void loop() {
  // Update LED state (non-blocking)
  updateLED();
  
  // Your other code can go here without being blocked by delay()
  // This allows other operations to run while LED is blinking
}

// ========================================
// Function Definitions
// ========================================

/**
 * initLED()
 * Initialize LED pin as output and set initial state
 */
void initLED() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // Start with LED off (Active HIGH)
  ledState = false;
  lastBlinkTime = millis();
  Serial.println("LED initialized on GPIO2");
}

/**
 * updateLED()
 * Non-blocking LED blinking using millis()
 * No delay() used - allows other code to run simultaneously
 */
void updateLED() {
  unsigned long currentTime = millis();
  
  // Check if it's time to toggle LED
  if (currentTime - lastBlinkTime >= LED_BLINK_INTERVAL) {
    // Toggle LED state
    ledState = !ledState;
    
    // Write to pin (Active HIGH - HIGH = ON, LOW = OFF)
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    
    // Update last toggle time
    lastBlinkTime = currentTime;
    
    // Debug output
    Serial.println("LED State: " + String(ledState ? "ON" : "OFF") + 
                   " | Time: " + String(currentTime) + "ms");
  }
}

// ========================================
// Additional Function: Change Blink Speed
// ========================================
/**
 * setBlinkSpeed(unsigned long interval)
 * Change the blink interval dynamically
 * @param interval - new interval in milliseconds
 */
void setBlinkSpeed(unsigned long interval) {
  // Update the interval dynamically
  #define LED_BLINK_INTERVAL interval
  Serial.println("Blink interval changed to: " + String(interval) + " ms");
}