
#include <Bounce2.h>

int LightPin = 4;
bool LightStatus = LOW;

int LedWifiPin = 2;

#define BUTTON_PIN 5
Bounce debouncer = Bounce();

void setup() {
  delay(100);
  pinMode(LightPin, OUTPUT);
  pinMode(LedWifiPin, OUTPUT);

  pinMode(BUTTON_PIN,INPUT);
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(50); // interval in ms
  setupWifi();
  setupWebServer();
  setupBlynk();
}

void loop() {
  debouncer.update();
  loopWebServer();
  loopWifi();
  loopBlynk();

  if(debouncer.rose() || debouncer.fell()){
    LightStatus = !LightStatus;
  }
  digitalWrite(LightPin, LightStatus);
}
