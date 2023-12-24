/*
  Complete details at https://RandomNerdTutorials.com/esp32-useful-wi-fi-functions-arduino/
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <Firebase_ESP_Client.h>

// Replace with your network credentials (STATION)
// Bucharest
// const char* ssid = "DIGI-w5HE-2.4G";
// const char* password = "Nwzw94W4";

//Oarja
const char* ssid = "DIGI-ggc4";
const char* password = "RUAutVwA";

String serverName = "https://api.nasa.gov/planetary/apod?api_key=JclJYCz2wFMdWaOz3F6jPJLkbNpCpmZudYyyHrZv";
String sensiboEndpoint = "https://home.sensibo.com/api/v2/pods/guHKtnvn/historicalMeasurements?apiKey=VCuPCe4p2xajYA4o9AaiL2SswbtgMa";
//String sensiboEndpoint = "https://home.sensibo.com/api/v2/pods/guHKtnvn/acStates?apiKey=VCuPCe4p2xajYA4o9AaiL2SswbtgMa";
unsigned long lastTime = 0;
//one day
//unsigned long timerDelay = 86400000;
unsigned long timerDelay = 10000;

//Firebase Auth
FirebaseAuth auth;
//Firebase config
FirebaseConfig config;

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void createAPODRequest() {
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverName.c_str());
      
      // If you need Node-RED/server authentication, insert user and password below
      //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(http.header("X-Ratelimit-Remaining"));
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}

void createSensiboRequest() {
  if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      
      // Your Domain name with URL path or IP address with path
      http.begin(sensiboEndpoint.c_str());
      
      // If you need Node-RED/server authentication, insert user and password below
      //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        //String payload = http.getString();
        WiFiClient * stream = http.getStreamPtr();
        String payload = "";
        while (stream->available()) {
          char c = stream->read();
          payload += c;
        }
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
}

void setup() {
  Serial.begin(115200);
  initWiFi();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
  //createSensiboRequest();

  auth.user.email = "gabriel.ivan5795@gmail.com";
  auth.user.password = "GabrielResidence";

  config.host = "ivan-s-residence.firebaseapp.com";
  config.api_key = "AIzaSyBsoa37O5JuPzmWEncqvteq4Ze9mxwCnLE";

  Firebase.begin(&config, &auth);
}

void loop() {
  createAPODRequest();
  createSensiboRequest();
}