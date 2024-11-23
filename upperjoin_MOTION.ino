#include <Servo.h>

// Create servo objects
Servo servo5;  // Servo on GPIO 5
Servo servo6;  // Servo on GPIO 6

// Define GPIO pins
const int servoPin5 = 6;
const int servoPin6 = 5;

// Movement ranges and delays
const int delayTime = 50; // Delay time for slower movement (ms)

void setup() {
  // Attach servos to respective GPIO pins
  servo5.attach(servoPin5);
  servo6.attach(servoPin6);

  // Initialize servos to their starting positions
  servo5.write(0);   // GPIO 5 starts at 0 degrees
  servo6.write(90);  // GPIO 6 starts at 90 degrees
  delay(1000);       // Allow servos to reach initial positions
}

void loop() {
  // Step 1: Move GPIO 5 from 0 to 90 and back
  for (int angle = 0; angle <= 90; angle++) {
    servo5.write(angle); // Move GPIO 5 up
    delay(delayTime);
  }
  for (int angle = 90; angle >= 0; angle--) {
    servo6.write(angle); // Move GPIO 5 down
    delay(delayTime);
  }

  delay(500); // Short pause

  // Step 2: Move GPIO 6 from 90 to 0 and back
  for (int angle = 0; angle <= 90; angle++) {
    servo6.write(angle); // Move GPIO 5 up
    delay(delayTime);
  }
  for (int angle = 90; angle >= 0; angle--) {
    servo5.write(angle); // Move GPIO 5 down
    delay(delayTime);
  }

  delay(500); // Short pause before repeating
}
