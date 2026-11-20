
#include <WiFi.h>
#include <WebServer.h>

// Wi-Fi credentials
const char* ssid = "Omkar";
const char* password = "omkar070908";

WebServer server(80);

// L298N connections
#define ENA 25
#define IN1 26
#define IN2 27
#define IN3 18
#define IN4 19
#define ENB 33

String currentCommand = "STOP";

unsigned long lastCommandTime = 0;
const unsigned long COMMAND_TIMEOUT = 1000;

// -------------------------
// MOTOR STOP
// -------------------------
void stopMotors() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  currentCommand = "STOP";
}

// -------------------------
// FORWARD
// -------------------------
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

// -------------------------
// BACKWARD
// -------------------------
void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

// -------------------------
// LEFT
// -------------------------
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

// -------------------------
// RIGHT
// -------------------------
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

// -------------------------
// COMMAND HANDLER
// -------------------------
void handleCommand() {

  if (!server.hasArg("value")) {
    server.send(400, "text/plain", "Missing command");
    return;
  }

  String cmd = server.arg("value");
  cmd.toUpperCase();

  if (cmd == "FORWARD") {
    forward();
  }
  else if (cmd == "BACKWARD") {
    backward();
  }
  else if (cmd == "LEFT") {
    turnLeft();
  }
  else if (cmd == "RIGHT") {
    turnRight();
  }
  else if (cmd == "STOP") {
    stopMotors();
  }
  else {
    server.send(400, "text/plain", "Invalid command");
    return;
  }

  currentCommand = cmd;
  lastCommandTime = millis();

  Serial.println("MOVEMENT: " + cmd);

  server.send(200, "text/plain", "MOVEMENT: " + cmd);
}

// -------------------------
// SETUP
// -------------------------
void setup() {

  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWIFI CONNECTED");
  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.localIP());

  server.on("/command", handleCommand);
  server.begin();

  lastCommandTime = millis();

  Serial.println("AGROBOT READY");
}

// -------------------------
// MAIN LOOP
// -------------------------
void loop() {

  server.handleClient();

  // Automatic STOP if laptop communication is lost
  if (currentCommand != "STOP" &&
      millis() - lastCommandTime > COMMAND_TIMEOUT) {

    stopMotors();

    Serial.println("TIMEOUT - MOTOR STOPPED");
  }
}
