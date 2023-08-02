/*
 * A library for controlling RAK3172 LoRa radio.
 *
 * @Author Nam Nguyen Thanh
 * @Date 09/07/2023
 * @Github https://github.com/NamNamIoT/RAK3172_CANOPUS/tree/main
 *
 */

#include "Arduino.h"
#include "RAK3172_AT.h"

extern "C" {
#include "string.h"
#include "stdlib.h"
}
String ret = "";
String command = "";
/*
  @param serial Needs to be an already opened Stream ({Software/Hardware}Serial) to write to and read from.
*/
RAK3172::RAK3172(Stream &serial, Stream &serial1)
  : _serial(serial), _serial1(serial1) {
  _serial.setTimeout(100);
  _serial1.setTimeout(100);
}

bool RAK3172::rk_getVersion() {
  return sendRawCommand(F("AT+VER=?"));
}

bool RAK3172::rk_switchToRecv() {
  command = "AT+PRECV=65534";
  _serial1.print("Enable recv ");
  sendRawCommand(command);
  ret = rk_recvP2PData();
  if (ret.indexOf("OK") >= 0)
  {
    _serial1.println("OK");
    return true;
  }
  else {
    _serial1.println("Fail");
    return false;
  }
}

String RAK3172::rk_getLoRaStatus() {
  return false;
}

String RAK3172::rk_getChannelList() {
  return false;
}

bool RAK3172::rk_setRate(int rate) {
  return false;
}

bool RAK3172::rk_setClass(int classMode) {
  return false;
}

bool RAK3172::rk_setRegion(int region) {
  if (region > 9) {
    _serial1.println(F("Parameter error"));
    return false;
  }
  String REGION;
  switch (region) {
    case 0:
      REGION = "AS923";

      break;
    case 1:
      REGION = "AU915";
      break;
    case 2:
      REGION = "CN470";
      break;
    case 3:
      REGION = "CN779";
      break;
    case 4:
      REGION = "EU433";
      break;
    case 5:
      REGION = "EU868";
      break;
    case 6:
      REGION = "KR920";
      break;
    case 7:
      REGION = "IN865";
      break;
    case 8:
      REGION = "US915";
      break;
    case 9:
      REGION = "US915_Hybrid";
      break;
  }
return false;
}

void RAK3172::rk_sleep(int mode) {
  return false;
}

bool RAK3172::rk_setSendinterval(int mode, int value) {
  return false;
}

void RAK3172::rk_reset(void) {
  return false;
}

bool RAK3172::rk_setWorkingMode(int mode) {
  switch (mode) {
    case 0:
      sendRawCommand(F("AT+NWM=0"));  //Set LoRaWAN Mode.
      break;
    case 1:
      sendRawCommand(F("AT+NWM=1"));  //Set LoRaP2P Mode.
      break;
    default:
      return false;
  }

  for (int i = 0; i < 10; i++) {
    ret = rk_recvData();
    _serial1.println(ret);
    if ((ret.indexOf("OK") >= 0) || (ret.indexOf("No switch work_mode") >= 0)) {
      return true;
    }
  }

  return false;
}

bool RAK3172::rk_setJoinMode(int mode) {
  return false;
}

bool RAK3172::rk_joinLoRaNetwork(int timeout) {
  return false;
}

bool RAK3172::rk_initOTAA(String devEUI, String appEUI, String appKEY) {
  return false;
}

bool RAK3172::rk_initABP(String devADDR, String nwksKEY, String appsKEY) {
  return false;
}

bool RAK3172::rk_isConfirm(int type) {
  return false;
}

bool RAK3172::rk_sendData(int port, char *datahex) {
  // String command = "";
  command = "at+send=lora:" + (String)port + ":" + datahex;
  // _serial1.println(command);
  sendRawCommand(command);

  return true;
}

String RAK3172::rk_recvData(void) {
  _serial.setTimeout(100);
  ret = _serial.readStringUntil('\0');
  // ret.trim();
  // _serial1.println(ret);
  return ret;
}

bool RAK3172::rk_initP2P(String FREQ, int SF, int BW, int CR, int PRlen, int PWR) {
  String command = "";
  command = "AT+PFREQ=" + FREQ;
  _serial1.print("Set Frequency. ");
  sendRawCommand(command);
  ret = rk_recvP2PData();
  if (ret.indexOf("OK") >= 0)
    _serial1.println("OK");
  else
    _serial1.println("Fail");

  command = "AT+PSF=" + String(SF);
  _serial1.print("Set SF. ");
  sendRawCommand(command);
  ret = rk_recvP2PData();
  /*
  if (ret.indexOf("OK") >= 0)
    _serial1.println("OK");
  else
    _serial1.println("Fail");
  */

  command = "AT+PBW=" + String(BW);
  _serial1.print("Set BW. ");
  sendRawCommand(command);
  ret = rk_recvP2PData();
  /*
  if (ret.indexOf("OK") >= 0)
    _serial1.println("OK");
  else
    _serial1.println("Fail");
  */

  command = "AT+PCR=" + String(CR);
  _serial1.print("Set CR. ");
  sendRawCommand(command);
  ret = rk_recvP2PData();
  /*
  if (ret.indexOf("OK") >= 0)
    _serial1.println("OK");
  else
    _serial1.println("Fail");
  */

  command = "AT+PPL=" + String(PRlen);
  _serial1.print("Set PRlen. ");
  sendRawCommand(command);
  ret = rk_recvP2PData();
  /*
  if (ret.indexOf("OK") >= 0)
    _serial1.println("OK");
  else
    _serial1.println("Fail");
  */

  command = "AT+PTP=" + String(PWR);
  _serial1.print("Set power. ");
  sendRawCommand(command);
  ret = rk_recvP2PData();
  /*
  if (ret.indexOf("OK") >= 0)
    _serial1.println("OK");
  else
    _serial1.println("Fail");
  */
  return true;
}

String RAK3172::rk_recvP2PData(void) {
  ret = _serial.readStringUntil('\0');
  ret.trim();

  return ret;
}

bool RAK3172::rk_sendP2PData(char *datahex) {
  command = "AT+PRECV=0";
  _serial1.print("Enable send ");
  sendRawCommand(command);
  ret = rk_recvP2PData();
  if (ret.indexOf("OK") >= 0)
    _serial1.println("OK");
  else {
    _serial1.println("Fail");
    return false;
  }

  String DATAHEX = datahex;
  String command = "AT+PSEND=" + DATAHEX;
  sendRawCommand(command);

  while (!_serial.available()) {
    _serial1.println(".");
    delay(100);
  }
  ret = rk_recvP2PData();
  if (ret.indexOf("OK") >= 0) {
    _serial1.println("Send success.");
  } else {
    _serial1.println("Send fail.");
    _serial1.println(ret);
    return false;
  }

  return true;
}

String RAK3172::rk_checkDeviceStatus(void) {
  return false;
}

bool RAK3172::rk_setUARTConfig(int UartPort, int Baud) {
return false;
}

bool RAK3172::sendRawCommand(String cmd) {
  while (_serial.available()) {
    _serial.read();
  }
  _serial1.println(cmd);
  _serial.println(cmd);
  delay(100);
  return true;
}
