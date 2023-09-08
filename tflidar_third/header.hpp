#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

bool addUUID = true;
int counter =0;
const char* ssid = "Detector-Vibration";
const char* password = "@DV2023_";
const char* ServerName = "https://cisea.bukitasam.co.id/api-iot/api/v1/iot/rain-detector/post"; // Replace with your server URL

#define RXD2 16
#define TXD2 17

int dist; /*----actual distance measurements of LiDAR---*/
int strength; /*----signal strength of LiDAR----------------*/
float temprature;
unsigned char check;        /*----save check value------------------------*/
int i;
unsigned char uart[9];  /*----save data measured by LiDAR-------------*/
const int HEADER = 0x59; /*----frame header of data package------------*/
int rec_debug_state = 0x01;//receive state for frame
String Output;
unsigned long prevMillis;
