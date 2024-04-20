#include <Rak3172_Canopus.h>
#include <Arduino.h>
#include "function.h"
#define V3

long startTime;
bool rx_done = false;
uint16_t sf = 12, bw = 0, cr = 0, preamble = 8, txPower = 22;

void Modbus_read(uint8_t* buf, uint16_t len) {
  Serial.print("\r\n[Lora]Read/Write: ");
  for (int i = 0; i < len; i++) {
    Serial.print("[");
    Serial.print(buf[i], HEX);
    Serial_modbus.printf("%c", buf[i]);
    Serial.print("]");
  }
}

void recv_cb(rui_lora_p2p_recv_t data) {
  rx_done = true;
  if (data.BufferSize == 0) {
    Serial.println("Empty buffer.");
    return;
  }
  digitalWrite(LED_RECV, HIGH);
  char buff[92];
  sprintf(buff, "[Lora]Incoming message, length: %d, RSSI: %d, SNR: %d",
          data.BufferSize, data.Rssi, data.Snr);
  Serial.println(buff);
  Modbus_read(data.Buffer, data.BufferSize);
  digitalWrite(LED_RECV, LOW);
}

void send_cb(void) {
  Serial.printf("\r\n[Lora]Back to Rx mode %s",
                api.lorawan.precv(65534) ? "Success" : "Fail");
}
void init_io() {
  pinMode(LED_SEND, OUTPUT);
  digitalWrite(LED_SEND, LOW);
  pinMode(LED_SYNC, OUTPUT);
  digitalWrite(LED_SYNC, HIGH);
  pinMode(V_SS5, OUTPUT);
  digitalWrite(V_SS5, HIGH);  //On power Vrs485
  pinMode(V_SS3, OUTPUT);
  digitalWrite(V_SS3, PWR_ON);  //On power Vsensor
  delay(1000);
}
bool init_lora(double freq) {

  if (api.lorawan.nwm.get() != 0) {
    Serial.printf("Set Node device work mode %s\r\n",
                  api.lorawan.nwm.set(0) ? "Success" : "Fail");
    api.system.reboot();
  }

  Serial.println("P2P Start");
  Serial.printf("Hardware ID: %s\r\n", api.system.chipId.get().c_str());
  Serial.printf("Model ID: %s\r\n", api.system.modelId.get().c_str());
  Serial.printf("RUI API Version: %s\r\n",
                api.system.apiVersion.get().c_str());
  Serial.printf("Firmware Version: %s\r\n",
                api.system.firmwareVersion.get().c_str());
  Serial.printf("AT Command Version: %s\r\n",
                api.system.cliVersion.get().c_str());
  Serial.printf("Set P2P mode frequency %3.3f: %s\r\n", (freq / 1e6),
                api.lorawan.pfreq.set(freq) ? "Success" : "Fail");
  Serial.printf("Set P2P mode spreading factor %d: %s\r\n", sf,
                api.lorawan.psf.set(sf) ? "Success" : "Fail");
  Serial.printf("Set P2P mode bandwidth %d: %s\r\n", bw,
                api.lorawan.pbw.set(bw) ? "Success" : "Fail");
  Serial.printf("Set P2P mode code rate 4/%d: %s\r\n", (cr + 5),
                api.lorawan.pcr.set(cr) ? "Success" : "Fail");
  Serial.printf("Set P2P mode preamble length %d: %s\r\n", preamble,
                api.lorawan.ppl.set(preamble) ? "Success" : "Fail");
  Serial.printf("Set P2P mode tx power %ddB: %s\r\n", txPower,
                api.lorawan.ptp.set(txPower) ? "Success" : "Fail");
  api.lorawan.registerPRecvCallback(recv_cb);
  api.lorawan.registerPSendCallback(send_cb);
  Serial.printf("P2P set Rx mode %s\r\n",
                api.lorawan.precv(65534) ? "Success" : "Fail");
  delay(1000);
  return true;
}

bool lora_send(int size_msg, uint8_t* msg) {
  Serial.printf("\r\n[Lora]P2P sending...");
  bool send_result = false;
  int count = 0;
  api.lorawan.precv(0);
  while (!send_result) {
    send_result = api.lorawan.psend(size_msg, msg);
    delay(1);
    count++;
    if (count > 2000) {
      Serial.printf("\r\n[Lora]P2P send Fail");
      return false;
    }
  }
  Serial.printf("\r\n[%d][Lora]P2P send Success", size_msg);
  return true;
}
