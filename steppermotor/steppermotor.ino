#include <Stepper.h>

const int stepsPerRevolution = 2048;

// Beispiel für Reihenfolge: IN1=8, IN2=10, IN3=9, IN4=11
Stepper stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  stepper.setSpeed(5); // langsam anfangen, maximum 18
}

void loop() {
  stepper.step(stepsPerRevolution); // eine Umdrehung vorwärts
  delay(1000);
  stepper.step(-stepsPerRevolution); // eine Umdrehung rückwärts
  delay(1000);
}