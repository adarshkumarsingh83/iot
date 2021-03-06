#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include"Config.h"


String payload = "";
String serverResponse;
int httpResponseCode;

HTTPClient http;
WiFiClient client;
ESP8266WiFiMulti WiFiMulti;

void setup() {
  Serial.begin(BROAD_RATE);
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(WIFI_SSID, WIFI_PASSWROD);
  while ((WiFiMulti.run() != WL_CONNECTED)) {
    delay(WIFI_RECONNECT_DELAY_TIME);
    Serial.print(".");
  }
  // Debugging - Output the IP Address of the ESP8266
  Serial.println();
  Serial.print("CONNECTED TO WIFI ");
  Serial.print(WiFi.SSID());
  Serial.print(" ");
  Serial.println(WiFi.localIP());
  // Your IP address with path or Domain name with URL path
  http.begin(client, SERVER_URL);

}

void loop() {
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    serverResponse = httpPostRequest(PAYLOAD);
    // todo with the server response
    if (serverResponse != "") {
      pushDataToSlave(serverResponse);
      delay(DELAY_TIME);
      serverResponse = "";
    }
  } else {
    Serial.println("NOT CONNECTED TO WIFI ");
  }
}

String httpPostRequest(String payload) {

  http.addHeader(CONTENT_TYPE, CONTENT_TYPE_VAL);
  // Send HTTP POST request
  httpResponseCode = http.POST(payload);
  payload = "";
  if (httpResponseCode > 0) {
    //Serial.println("HTTP Response code: " + String(httpResponseCode));
    payload = http.getString();
  } else if (httpResponseCode == -1) {
    Serial.println("ERROR SERVER NOT REACHABLE: " + String(httpResponseCode));
  } else {
    Serial.println("ERROR CODE: " + String(httpResponseCode));
  }
  return payload;
}

void pushDataToSlave(String value) {
  value = value + "\n";
  Serial.write(value.c_str());
}
