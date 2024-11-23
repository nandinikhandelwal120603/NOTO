#include <Servo.h>

// Create servo objects
Servo servo9;  // Servo on GPIO 9
Servo servo10; // Servo on GPIO 10

// Define GPIO pins
const int servoPin9 = 9;
const int servoPin10 = 10;

// Movement ranges and delays
const int delayTime = 50; // Delay time for slower movement (ms)

void setup() {
  // Attach servos to respective GPIO pins
  servo9.attach(servoPin9);
  servo10.attach(servoPin10);

  // Initialize servos to their starting positions
  servo9.write(0);    // GPIO 9 starts at 0 degrees
  servo10.write(0);   // GPIO 10 starts at 0 degrees
  delay(1000);        // Allow servos to reach initial positions
}

void loop() {
  // Step 1: Move GPIO 9 and GPIO 10 from 0 to 45
  for (int angle = 0; angle <= 45; angle++) {
    servo9.write(angle);  // Move GPIO 9 up
    servo10.write(angle); // Move GPIO 10 up
    delay(delayTime);
  }

  // Step 2: Move GPIO 9 and GPIO 10 from 45 back to 0
  for (int angle = 45; angle >= 0; angle--) {
    servo9.write(angle);  // Move GPIO 9 down
    servo10.write(angle); // Move GPIO 10 down
    delay(delayTime);
  }

  delay(500); // Short pause before repeating
}
