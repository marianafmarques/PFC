#include <BlynkSimpleEsp8266.h>

//char auth[] = "9-v08woyP24BlG2hmq_fQE5Vutjm5X7K"; //Sala, escuro
char auth[] = "4oKTySLr_KYQBETyHjSxWD8-OeLLbARv"; //Garagem

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

    if(pinValue == 1 || pinValue == 0)
        LightStatus = !LightStatus;
    // if(LightStatus == 1)
    //     Blynk.setProperty(V1, "onLabel", "ON");
    // else
    //     Blynk.setProperty(V1, "offLabel", "OFF");
}

BLYNK_WRITE(V2)
{
    int pinValue = param.asInt();

    if(pinValue == 1 || pinValue == 0)
        LightStatus = !LightStatus;
    // if(LightStatus == 1)
    //     Blynk.virtualWrite(V2, 1023);
    // else
    //     Blynk.virtualWrite(V2, 0);
}

BLYNK_WRITE(V3)
{
    int pinValue = param.asInt();

    if(pinValue == 1){
        LightStatus = LOW;
    }
    else{
        LightStatus = HIGH;
    }

    // if(LightStatus == 1)
    //     Blynk.virtualWrite(V2, 1023);
    // else
    //     Blynk.virtualWrite(V2, 0);
}

void setupBlynk(){
    Blynk.begin(auth, ssid, password);
}

void loopBlynk(){
    Blynk.run();
}
