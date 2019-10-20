
#include <Bounce2.h>

int LED1pin = 1;
bool LED1status = LOW;

int LedStatuspin = 2;
int LedStatusStatus = LOW;

#define BUTTON_PIN 3
Bounce debouncer = Bounce();

void setup() {
  delay(100);
  pinMode(LED1pin, OUTPUT);
  pinMode(LedStatuspin, OUTPUT);

  pinMode(BUTTON_PIN,INPUT_PULLUP);
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
    LED1status = !LED1status;
  }
  digitalWrite(LED1pin, LED1status);
}
