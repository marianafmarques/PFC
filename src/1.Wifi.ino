#include <ESP8266WiFi.h>

/*Put your SSID & Password*/
const char* ssid = "Casa_Nana";  // Enter SSID here
const char* password = "74747474";  //Enter Password here

// const char* ssid = "OnePlus 6";  // Enter SSID here
// const char* password = "123467890";  //Enter Password here


void setupWifi(){
    WiFi.hostname("PFC");
    WiFi.begin(ssid, password);
}

void loopWifi(){
    if(WiFi.status() != WL_CONNECTED){
        digitalWrite(LedWifiPin, HIGH);
    } else {
        digitalWrite(LedWifiPin, LOW);
    }
}
