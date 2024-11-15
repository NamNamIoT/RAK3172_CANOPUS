#include <HardwareSerial.h>
#define TX1 26
#define RX1 25
HardwareSerial Serial_Lora(1);

#define LED_RED 14
#define LED_BLUE 27
#include "RAK3172_AT.h"
#define WORK_MODE LoRaP2P  //  LoRaWAN or LoRaP2P
RAK3172 RAKLoRa(Serial_Lora, Serial);

void IRAM_ATTR resetModule()  //timer watchdog overflow
{
  Serial.printf("\r\nReset bcuz WDT\r\n");
  esp_restart();
};
bool ReceiveMsg() {
  String ret = RAKLoRa.rk_recvP2PData();
  if (ret == NULL || ret == "")
    return 0;
  else
    Serial.print(ret);
  return 1;
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Initializing...");
  Serial.flush();
  Serial_Lora.begin(115200);
  while (Serial_Lora.available()) {
    Serial_Lora.read();
  }

  if (!RAKLoRa.rk_setWorkingMode(WORK_MODE))  //set WisNode work_mode to LoRaP2P.
  {
    Serial.println(F("set work_mode failed, please reset module."));
    Serial.println(F("\r\nPlease check all wire connect\n"));
    delay(5000);
    //resetModule();
  }

  RAKLoRa.rk_getVersion();                //get RAK3172 firmware version
  Serial.println(RAKLoRa.rk_recvData());  //print version number
  Serial.println(F("Start init LoRaP2P parameters..."));

  if (!RAKLoRa.rk_initP2P("868000000", 12, 1, 3, 8, 20)) {
    Serial.println(F("Init error,please reset module."));
    resetModule();
  }
}

void loop() {
  //RAKLoRa.rk_sendP2PData(count);
  delay(100);
}
