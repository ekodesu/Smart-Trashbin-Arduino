#include <Servo.h>

// Pin definitions
#define TRIGGER_PIN 9    // Ultrasonic sensor trigger pin
#define Echo_PIN 10      // Ultrasonic sensor echo pin
#define SERVO_PIN 11     // Servo motor signal pin
#define MAX_DISTANCE 10  // Distance in cm to trigger opening

// Servo angle definitions
#define LID_UPWARD 180   // Fully open/upward position
#define LID_DOWN 90      // Closed/down position

Servo servo;
unsigned long openTime = 0;
bool lidIsUp = true;  // Track if lid is in upward position

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
    
    // Attach servo
    servo.attach(SERVO_PIN);
    servo.write(LID_UPWARD);  // Start with lid UPWARD
    lidIsUp = true;
    
    // Initialize ultrasonic sensor pins
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(Echo_PIN, INPUT);
    
    Serial.println("Automatic Trash Bin System Started");
    Serial.println("Lid UPWARD - waiting for detection");
}

void loop() {
    long duration;
    float distance;
    
    // Send ultrasonic pulse
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    
    // Measure echo duration
    duration = pulseIn(Echo_PIN, HIGH, 30000);
    
    // Calculate distance in cm
    distance = duration * 0.0343 / 2;
    
    // Print distance for debugging
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    // If hand detected and lid is up, close it
    if (distance > 0 && distance <= MAX_DISTANCE && lidIsUp) {
        servo.write(LID_DOWN);  // Close lid
        lidIsUp = false;
        openTime = millis();
        Serial.println("Lid CLOSED - Throw trash now");
    }
    
    // After 3 seconds, open lid back up
    if (!lidIsUp && (millis() - openTime >= 3000)) {
        servo.write(LID_UPWARD);  // Open lid upward
        lidIsUp = true;
        Serial.println("Lid OPENED (UPWARD) - System ready");
    }
    
    delay(100);
}
