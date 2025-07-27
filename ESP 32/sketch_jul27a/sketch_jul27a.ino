#define LED_PIN 2  // Auf vielen ESP32-Boards ist GPIO 2 mit einer internen LED verbunden

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED an
  delay(500);
  digitalWrite(LED_PIN, LOW);   // LED aus
  delay(500);
}
