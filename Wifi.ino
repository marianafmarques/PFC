#include <ESP8266WiFi.h>

const char* ssid =  "Casa";   // cannot be longer than 32 characters!
const char* pass =  "74747474";   //

WiFiClient wclient;
WiFiServer server(80);//Service Port

long lastReconnectAttemptWIFI = 0;
long timerWIFI = 10000;

void WifiSetup() {
    WiFi.hostname("PFC");
    //Serial.begin(9600);
    WiFi.begin(ssid, pass);
    server.begin();
}

//Funcao que reconecta o Wifi se ele estiver desconectado
//  Retorna falso se desconectado e verdadeiro se conectado
boolean reconnectWIFI(){
  //Serial.print("Reconectando wifi ");
  if (WiFi.status() != WL_CONNECTED) {
    //Serial.println("WiFi OFF");
    WiFi.disconnect();
    WiFi.begin(ssid, pass);
    return false;
  }
  else {
    //Serial.println("WiFi ON");
    return true;
  }
}

//
void WifiLoop(){
    if (WiFi.status() != WL_CONNECTED) {
        //Serial.println("Reconectando wifi ");
        long nowWIFI = millis();
        if (nowWIFI - lastReconnectAttemptWIFI > timerWIFI) {
            lastReconnectAttemptWIFI = nowWIFI;
            // Attempt to reconnect
            if (reconnectWIFI()) {
                lastReconnectAttemptWIFI = 0;
            }
        }
    }

    WiFiClient client = server.available();

    // Read the first line of the request
    String request = client.readStringUntil('\r');
    //Serial.println(request);
    client.flush();

    // Match the request
    // if (request.indexOf("/LED=ON") != -1 || digitalRead(switch_pin) == HIGH) {
    //     light_state = LOW;
    // }
    // if (request.indexOf("/LED=OFF") != -1 || digitalRead(switch_pin) == LOW){
    //     light_state = HIGH;
    // }

    if (request.indexOf("/LED=ON") != -1) {
        light_state = LOW;
    }
    if (request.indexOf("/LED=OFF") != -1){
        light_state = HIGH;
    }

    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println(""); //  do not forget this one
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");

    client.print("Light pin is now: ");

    if(light_state == LOW) {
        client.print("On");
    } else {
        client.print("Off");
    }

    digitalWrite(light_pin, light_state);
    digitalWrite(switch_pin, light_state);
    client.println("<br><br>");
    client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 ON<br>");
    client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 OFF<br>");
    client.println("</html>");
}
