#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "9-v08woyP24BlG2hmq_fQE5Vutjm5X7K";

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

    if(pinValue == 1 || pinValue == 0)
        LED1status = !LED1status;
}

void setupBlynk(){
    Blynk.begin(auth, ssid, password);
}

void loopBlynk(){
    Blynk.run();
}
