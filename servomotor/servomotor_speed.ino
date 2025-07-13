#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9); // Signalpin an D9
}

void loop() {
  for (int pos = 0; pos <= 90; pos++) {
    myServo.write(pos);       // Position in Grad
    delay(20);                // Je höher der Delay, desto langsamer
  }
  delay(1000);
}