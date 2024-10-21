# ESP8266-MQTT with SSL ✨

### Description 🌸

This little sketch is here to help you connect your adorable ESP8266 microcontroller to an SSL-secured, user-and-password protected MQTT broker. 🌐🔒

Before you dive in, make sure to customize all the variables in the sketch to fit your own setup—make it uniquely yours! 💻✨

To fetch the SSL fingerprint of your broker, simply run the command below in a Linux shell (and don’t forget to replace `<MQTTBroker>` with your actual hostname! 😉):

```bash
echo | openssl s_client -connect <MQTTBroker>:8883 | openssl x509 -fingerprint -noout
SHA1 Fingerprint=00:11:22:33:44:55:66:77:88:99:00:AA:BB:CC:DD:EE:FF:00:11:22
```

#### Tested Device:  
ESP8266 D1 Mini 🛠️✨

---

## License 🌸:
**Do Whatever You’d Like Public License** 💖  
Feel free to copy, modify, and share as you please—just have fun with it! 🎉💫
