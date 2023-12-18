#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI_SSID"; 
const char* password = "YOUR_WIFI_PASSWORD"; 

const char* serverUrl = "http://example.com"; 


void setup() {

}

void loop() {
  Serial.begin(115200); 
WiFi.begin(ssid, password); 
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.print("Connected to WiFi network with IP Address: ");
Serial.println(WiFi.localIP()); 


HTTPClient http;
http.begin(serverUrl);

// Example of GET request
int httpResponseCode = http.GET(); 

// Example of POST request
http.addHeader("Content-Type", "application/json"); 
String requestBody = "{\"name\":\"ESP32\",\"value\":100}";
httpResponseCode = http.POST(requestBody); 

String payload = http.getString(); 

Serial.print("HTTP Response code: ");
Serial.println(httpResponseCode);
Serial.println(payload); 

http.end(); 

delay(10000); 
}