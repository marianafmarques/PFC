#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

void setupWebServer(){
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.on("/led1toggle", handle_led1toggle);
  server.onNotFound(handle_NotFound);
  server.begin();
}

void loopWebServer(){
  server.handleClient();
}



void handle_OnConnect() {
  server.send(200, "text/html", SendHTML(LED1status));
}

void handle_led1on() {
  LED1status = HIGH;
  server.send(200, "text/html", SendHTML(LED1status));
}

void handle_led1off() {
  LED1status = LOW;
  server.send(200, "text/html", SendHTML(LED1status));
}

void handle_led1toggle() {
  LED1status = !LED1status;
  server.send(200, "text/html", SendHTML(LED1status));
}


void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

// String SendHTML(uint8_t led1stat){
//   String ptr = "<!DOCTYPE html> <html>\n";
//   ptr += "ledpin is now: ";
//   if (led1stat){
//     ptr +="ON\n";
//   } else {
//     ptr += "OFF\n";
//   }
//   ptr += "<br><br>\n";
//   ptr += "Click <a href=\"/led1on\">here</a> turn the LED on pin 2 ON<br>\n";
//   ptr += "Click <a href=\"/led1off\">here</a> turn the LED on pin 2 OFF<br>\n";
//   ptr += "Click <a href=\"/led1toggle\">here</a> to toggle LED on pin 2 OFF<br>\n";
//   return ptr;
// }



String SendHTML(uint8_t led1stat){
 String ptr = "<!DOCTYPE html> <html>\n";
 ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
 ptr +="<title>LED Control</title>\n";
 ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
 ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
 ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
 ptr +=".button-on {background-color: #1abc9c;}\n";
 ptr +=".button-on:active {background-color: #16a085;}\n";
 ptr +=".button-off {background-color: #34495e;}\n";
 ptr +=".button-off:active {background-color: #2c3e50;}\n";
 ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
 ptr +="</style>\n";
 ptr +="</head>\n";
 ptr +="<body>\n";
 ptr +="<h1>ESP8266 Web Server</h1>\n";
   ptr +="<h3>Using Station(STA) Mode</h3>\n";

  if(led1stat)
 {ptr +="<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";}
 else
 {ptr +="<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";}


 ptr +="</body>\n";
 ptr +="</html>\n";
 return ptr;
}
