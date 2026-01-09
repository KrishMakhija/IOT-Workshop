#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define RELAY_PIN D1
#define LED_PIN   D2

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

ESP8266WebServer server(80);

// HTML + CSS Page
String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>NodeMCU Relay Control</title>
  <style>
    body {
      font-family: Arial;
      text-align: center;
      background-color: #121212;
      color: white;
    }
    h1 {
      margin-top: 50px;
    }
    .btn {
      padding: 20px 40px;
      font-size: 20px;
      margin: 20px;
      border: none;
      border-radius: 10px;
      cursor: pointer;
    }
    .on {
      background-color: #00c853;
      color: white;
    }
    .off {
      background-color: #d50000;
      color: white;
    }
  </style>
</head>
<body>

  <h1>NodeMCU Light Control</h1>

  <a href="/on">
    <button class="btn on">TURN ON</button>
  </a>

  <a href="/off">
    <button class="btn off">TURN OFF</button>
  </a>

</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // OFF
  digitalWrite(LED_PIN, LOW);    // OFF

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Web routes
  server.on("/", []() {
    server.send(200, "text/html", webpage);
  });

  server.on("/on", []() {
    digitalWrite(RELAY_PIN, LOW);   // Relay ON
    digitalWrite(LED_PIN, HIGH);    // LED ON
    server.send(200, "text/html", webpage);
  });

  server.on("/off", []() {
    digitalWrite(RELAY_PIN, HIGH);  // Relay OFF
    digitalWrite(LED_PIN, LOW);     // LED OFF
    server.send(200, "text/html", webpage);
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
