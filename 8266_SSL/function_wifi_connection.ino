// General WiFi connection logic
void connectToWiFi()
{
  // Counter for max. retries
  int counter = 0;

  // Disconnect from WiFi and set WiFi Mode to STA
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);

  // Start connecting to the WiFi
  WiFi.begin(wifi_ssid, wifi_password);
  delay(100);

  // While client is not connected to the WiFi
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
    counter++;
    
    // Restart if no connection after 30 seconds
    if (counter >= 60) {
      ESP.restart();
    }
  }

  String wifi_ip = WiFi.localIP().toString();
  Serial.println();
  Serial.println("Connected");
  Serial.println("IP Address: " + wifi_ip);
}

// Connect ESP with the WiFi Network
void wifi_connect()
{
  Serial.print("Connecting to WiFi: ");
  Serial.println(wifi_ssid);
  
  // Call common WiFi connection logic
  connectToWiFi();
}

// Check and reconnect WiFi if needed
void wifi_reconnect()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println();
    Serial.println("Lost WiFi Connection");
    Serial.println("Reconnecting to SSID: " + (String)wifi_ssid);
    
    // Call common WiFi connection logic
    connectToWiFi();
  }
}
