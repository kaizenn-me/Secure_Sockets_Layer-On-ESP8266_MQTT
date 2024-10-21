#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <PubSubClient.h>

// WiFi and MQTT Configuration
const char* wifi_ssid = "<SSID>";
const char* wifi_password = "<PASSWORD>";
const char* mqtt_server = "<example.org>";
const unsigned int mqtt_port = 8883;
const char* mqtt_user = "<USER>";
const char* mqtt_password = "<PASSWORD>";
const char* mqtt_topic = "/ESP8266/topic";
const char* mqtt_fprint = "AA:BB:CC:DD:EE:FF:00:11:22:33:44:55:66:77:88:99:AA:BB:CC:DD";

WiFiClientSecure espClient;
PubSubClient client(espClient);

// To handle uptime message intervals without blocking the loop
unsigned long previousMillis = 0;
const long interval = 10000;  // 10 seconds

void setup() {
  Serial.begin(115200);
  Serial.println();

  // Connect to WiFi
  wifi_connect();

  // Connect to MQTT broker
  mqtt_connect();

  Serial.println("========================== Start Loop ==========================");
  Serial.println();
}

void loop() {
  // Reconnect if necessary
  wifi_reconnect();
  mqtt_check_connection();
  
  // Handle MQTT client
  client.loop();

  // Send uptime message every 10 seconds without blocking the loop
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    sendUptimeMessage();
  }
}

// Send Uptime Message to MQTT Broker
void sendUptimeMessage() {
  unsigned long runningTime = millis();
  char message[100]; // Allocate buffer for message
  snprintf(message, sizeof(message), "{\"Reason\": \"Test\", \"Uptime\": \"%lu\"}", runningTime);

  client.publish(mqtt_topic, message, true);
  Serial.println(message);
}
