#include <ThingerWiFiNINA.h>
#define _DISABLE_TLS_
#define USERNAME "thinger_username"
#define DEVICE_ID "thinger_device_id"
#define DEVICE_CREDENTIAL "thinger_device_credential"

#define SSID "ssid"
#define SSID_PASSWORD "ssid_password"

ThingerWiFiNINA thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  // configure wifi network
  thing.add_wifi(SSID, SSID_PASSWORD);

  pinMode(LED_BUILTIN, OUTPUT);

  // pin control example (i.e. turning on/off a light, a relay, etc)
  thing["led"] << digitalPin(LED_BUILTIN);

  // resource output example (i.e. reading a sensor value, a variable, etc)
  thing["millis"] >> outputValue(millis());

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}
