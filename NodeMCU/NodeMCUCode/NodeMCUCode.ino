#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid = "vivo y56";
const char* password = "02727928";
ESP8266WebServer server(80);
int ledPin = D0;   // GPIO5
void handleRoot() {
  String html = "<html><head><title>NodeMCU LED Control</title></head>";
  html += "<body style='text-align:center; font-family:Sans-serif;'>";
  html += "<h1>LED Control using NodeMCU</h1>";
  html += "<a href='/on'><button style='padding:20px; background-color: lightgreen; border-radius: 20% '>LED ON</button></a><br><br>";
  html += "<a href='/off'><button style='padding:20px; background-color: lightgreen; border-radius: 20% '>LED OFF</button></a>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}
void ledOn() {
  digitalWrite(ledPin, HIGH);   // LED ON (active LOW)
  server.sendHeader("Location", "/");
  server.send(303);
}
void ledOff() {
  digitalWrite(ledPin, LOW);  // LED OFF
  server.sendHeader("Location", "/");
  server.send(303);
}
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", ledOn);
  server.on("/off", ledOff);

  server.begin();
}

void loop() {
  server.handleClient();
}