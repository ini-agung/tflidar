#include "header.hpp"

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
  delay(2000);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    counter ++;
    if (counter >= 10) {
      ESP.restart();
    }
  }
  Serial.println("Connected to WiFi");
  Serial.println("\nLidar TFMini Plus for detection anomaly on belt convayer");
  prevMillis = millis();
}

void loop() {
  unsigned long ms = millis();
  if (addUUID) {
    Output = "{\"value\" : [{\"UUID\" : \"FF-0001-2023\", \"temp\" : ";
    Output += temprature;
    Output += "}";
  }
  addUUID = false;
  int distance = Get_Lidar_data();
  if (distance != 0) {
    Output += ",";
    Output += String(distance);
  }

  if (ms  - prevMillis >= 10000) {
    Output += "]}";
    Serial.println(Output);
    SENDING(Output);
    Output = "";
    prevMillis = ms;
    addUUID = true;
  }
}

void SENDING(String data) {
  HTTPClient http;
  http.begin(ServerName);
  delay(150);
  http.addHeader("Content-Type", "application/json");
  delay(150);
  String httpRequestData = data;
  int httpResponseCode = http.POST(httpRequestData);
  delay(200);
  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
    http.end();
  }
}
