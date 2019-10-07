#include <Arduino.h>
int light_pin = 2;
int switch_pin = 3;
int light_state;

// the setup function runs once when you press reset or power the board
void setup() {

    pinMode(light_pin, OUTPUT);
    //pinMode(switch_pin, FUNCTION_3);
    //pinMode(switch_pin, INPUT);
    //pinMode(switch_pin, INPUT);
    WifiSetup();
    //light_state = LOW;
    ArduinoOTA_setup();

}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(light_pin, HIGH);
    WifiLoop();
    ArduinoOTA_loop();

}
