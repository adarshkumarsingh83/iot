/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshmodeltrains@gmail.com
*/

#ifndef Config_h
#define Config_h
#include "Arduino.h"

/************************************************************************************************/
#define BROAD_RATE 115200
#define DELAY_TIME 5000
#define WIFI_RECONNECT_DELAY_TIME 500
#define MQTT_TOPIC  "/espark/adarsh/data"


// WiFi
// ESP8266 do not support 5G wifi connection
#define WIFI_SSID "adarsh-model-trains"
#define WIFI_PASSWROD "adarsh@model@trains"

// MQTT
// find this ip using ipconfig or check in router
#define MQTT_SERVER "192.168.0.188"
#define MQTT_USERNAME "adarsh"
#define MQTT_PASSORD "password"

// change the node "number/name"  based on the node
#define CLIENT_ID  "ESPARK_NODE_ESP8266_PUBLISHING_1"

#endif
