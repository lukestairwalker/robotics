#include <Servo.h>

Servo myServo;  // create servo object

void setup() {
  myServo.attach(9);  // Servo an Pin 9
}

void loop() {
  myServo.write(0);    // Servo auf 0°
  delay(1000);
  myServo.write(90);   // Servo auf 90°
  delay(1000);
  myServo.write(180);  // Servo auf 180°
  delay(1000);
}