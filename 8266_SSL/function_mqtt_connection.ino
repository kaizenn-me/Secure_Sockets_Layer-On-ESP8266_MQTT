// General MQTT connection logic
void connectToBroker()
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");

    // MQTT verify Fingerprint Function
    verifyFingerprint();

    if (client.connect(WiFi.macAddress().c_str(), mqtt_user, mqtt_password))
    {
      Serial.println("connected");
    } 
    else 
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");

      // Wait 5 seconds before retrying (consider using millis() for non-blocking delay)
      delay(5000);
    }
  }
}

// Connect ESP with the MQTT Broker
void mqtt_connect()
{
  // Set SSL Fingerprint
  espClient.setFingerprint(mqtt_fprint);

  // Set MQTT Server
  client.setServer(mqtt_server, mqtt_port);

  // Try to connect to the broker
  connectToBroker();
}

// Check MQTT Connection
void mqtt_check_connection()
{
  // Ensure the client stays connected to the broker
  connectToBroker();
}
