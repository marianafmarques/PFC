#include <ESP8266WiFi.h>

/*Put your SSID & Password*/
const char* ssid = "Casa";  // Enter SSID here
const char* password = "74747474";  //Enter Password here


void setupWifi(){
  WiFi.hostname("PFC");
  WiFi.begin(ssid, password);
}

void loopWifi(){
  if(WiFi.status() != WL_CONNECTED){
    digitalWrite(LedStatuspin, HIGH);
  } else {
    digitalWrite(LedStatuspin, LOW);
  }
}
