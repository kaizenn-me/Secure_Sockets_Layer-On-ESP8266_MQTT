void verifyFingerprint()
{
  // If client is already connected, skip fingerprint check
  if (client.connected() || espClient.connected()) return;

  Serial.print("Checking TLS connection to ");
  Serial.print(mqtt_server);
  Serial.println("...");

  // Attempt to connect to the broker
  if (!espClient.connect(mqtt_server, mqtt_port)) {
    Serial.println("Connection failed. Rebooting...");
    ESP.restart(); // Restart if connection fails
  }

  // Verify SSL Fingerprint of the broker
  if (espClient.verify(mqtt_fprint, mqtt_server)) {
    Serial.println("Connection secure.");
  } else {
    Serial.println("Connection insecure! Rebooting...");
    ESP.restart(); // Restart if the SSL verification fails
  }

  // Stop the client after verification
  espClient.stop();
}

