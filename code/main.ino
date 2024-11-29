#include <Servo.h>

// Define the pins for flex sensors
const int flexPin1 = A0;
const int flexPin2 = A1;
const int flexPin3 = A2;

// Define the pins for the servo motors
const int servoPin1 = 9;
const int servoPin2 = 10;
const int servoPin3 = 11;

// Create Servo objects
Servo servo1;
Servo servo2;
Servo servo3;

// Define threshold for flex sensor activation (sensor value threshold)
const int flexThreshold2 = 10;
const int flexThreshold1 = 300;
const int flexThreshold3 = 200;
void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);

  // Attach the servo motors to the corresponding pins
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void loop() {
  // Read the flex sensor values
  int flexValue1 = analogRead(flexPin1);
  int flexValue2 = analogRead(flexPin2);
  int flexValue3 = analogRead(flexPin3);

  // Debugging: Print the flex sensor values
  Serial.print("Flex Sensor 1: ");
  Serial.print(flexValue1);
  Serial.print("\tFlex Sensor 2: ");
  Serial.print(flexValue2);
  Serial.print("\tFlex Sensor 3: ");
  Serial.println(flexValue3);

  // Case 1: Flex Sensor 1 controls Servo 1 HIGH
  if (flexValue1 < flexThreshold1) {
    // Move Servo 1 to 90 degrees if flex sensor value exceeds threshold
    servo1.write(90);
  } else {
    // Otherwise, keep Servo 1 at 0 degrees (or another desired position)
    servo1.write(0);
  }

  // Case 2: Flex Sensor 2 controls Servo 2 MID
  if (flexValue2 < flexThreshold2) {
    // Move Servo 2 to 90 degrees if flex sensor value exceeds threshold
    servo2.write(90);
  } else {
    // Otherwise, keep Servo 2 at 0 degrees
    servo2.write(0);
  }

  // Case 3: Flex Sensor 3 controls Servo 3 LOW
  if (flexValue3 > flexThreshold3) {
    // Move Servo 3 to 90 degrees if flex sensor value exceeds threshold
    servo3.write(90);
  } else {
    // Otherwise, keep Servo 3 at 0 degrees
    servo3.write(0);
  }

  // Small delay to allow the servos to move smoothly
  delay(200); // Delay for 200 milliseconds
}
