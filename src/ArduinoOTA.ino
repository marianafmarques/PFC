//#include <ArduinoOTA.h>

// void ArduinoOTA_setup(){
//     ArduinoOTA.setHostname("PFC");
//     ArduinoOTA.setPassword("74747474");
//     ArduinoOTA.setPort(8266);
//     ArduinoOTA.onStart([]() {
//       Serial.println("Inicio...");
//     });
//     ArduinoOTA.onEnd([]() {
//       Serial.println("nFim!");
//     });
//     ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
//       Serial.printf("Progresso: %u%%r", (progress / (total / 100)));
//     });
//     ArduinoOTA.onError([](ota_error_t error) {
//       Serial.printf("Erro [%u]: ", error);
//       if (error == OTA_AUTH_ERROR); //Serial.println("Autenticacao Falhou");
//       else if (error == OTA_BEGIN_ERROR); // Serial.println("Falha no Inicio");
//       else if (error == OTA_CONNECT_ERROR); // Serial.println("Falha na Conexao");
//       else if (error == OTA_RECEIVE_ERROR); // Serial.println("Falha na Recepcao");
//       else if (error == OTA_END_ERROR);
//       Serial.println("Falha no Fim");
//     });
//     ArduinoOTA.begin();
// }
//
// void ArduinoOTA_loop(){
//   ArduinoOTA.handle();
// }
