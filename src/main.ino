
#include <Bounce2.h>

//D2
int LightPin = 4;
bool LightStatus = LOW;

int LedWifiPin = 2;

//D5
#define SWITCH_PIN 14
Bounce debouncer = Bounce();

void setup() {
  delay(100);
  pinMode(LightPin, OUTPUT);
  pinMode(LedWifiPin, OUTPUT);

  pinMode(SWITCH_PIN,INPUT);
  debouncer.attach(SWITCH_PIN);
  debouncer.interval(50); // interval in ms
  setupWifi();
  //setupWebServer();
  setupBlynk();
}

void loop() {
  debouncer.update();
  //loopWebServer();
  loopWifi();
  loopBlynk();

  if(debouncer.rose() || debouncer.fell()){
    LightStatus = !LightStatus;
  }
  digitalWrite(LightPin, LightStatus);
}
