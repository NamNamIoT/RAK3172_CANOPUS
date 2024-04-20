#include <Rak3172_Canopus.h>
#include "function.h"
#define V3

void setup() {
  Serial.begin(115200);
  Serial.println("RAK3172_Canopus LoRa P2P Example");
  Serial.println("------------------------------------------------------");
  delay(1000);  //do not remove this delay, it use for detect baud upload code UART mode
  init_io();
  init_lora(868000000);
  Serial_modbus.begin(9600, RAK_CUSTOM_MODE);
  Serial_modbus.println("RAK3172_Canopus LoRa_Modbus tunnel Example");
}


void loop() {
  uint8_t frame_input[100];
  int size_input = 0;
  while (Serial_modbus.available()) {
    frame_input[size_input++] = Serial_modbus.read();
  }
  if (size_input != 0) {
    lora_send(size_input, frame_input);
  }
  delay(100);
}