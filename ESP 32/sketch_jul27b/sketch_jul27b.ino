#include <WiFi.h>

const char* ssid = "Vodafone-AA4C";
const char* password = "eAPYXghAtc3mE6Hp";

WiFiServer server(80);
const int ledPin = 2;

bool ledState = false;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // Kurzes Blinken beim Start (2x 200ms)
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  Serial.println("Starte WLAN-Verbindung...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Verbunden mit: ");
  Serial.println(ssid);
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Server gestartet");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Neuer Client verbunden");
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    // Suche nach "/led=on" oder "/led=off" im Request
    if (request.indexOf("/led=on") != -1) {
      ledState = true;
      digitalWrite(ledPin, HIGH);
    } else if (request.indexOf("/led=off") != -1) {
      ledState = false;
      digitalWrite(ledPin, LOW);
    }

    // Antwort an Browser
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.print("<h1>Hallo vom ESP32!</h1>");
    client.print("<p>LED ist ");
    client.print(ledState ? "AN" : "AUS");
    client.println("</p>");
    client.print("<p>Steuere die LED via URL:</p>");
    client.print("<p>/led=on  --> LED einschalten</p>");
    client.print("<p>/led=off --> LED ausschalten</p>");
    client.println();
    client.stop();
    Serial.println("Client getrennt");
  }
}