#include "modbus.h"
#include "modbusDevice.h"
#include "modbusRegBank.h"
#include "modbusSlave.h"
modbusDevice regBank;
modbusSlave slave;

#define LED PA8
#define mA_PIN PB3
#define VSS_PIN PB5
#define VRS_PIN PB12
#define PWR_ON LOW
#define PWR_OFF HIGH

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(VRS_PIN, OUTPUT);
  digitalWrite(VRS_PIN, PWR_ON);  //On power Vrs485
  pinMode(VSS_PIN, OUTPUT);
  digitalWrite(VSS_PIN, PWR_ON);  //On power Vsensor
  
  Serial.begin(115200);
  Serial.print("\r\n*****************RAK3172_CANOPUS*******************");
  
  regBank.setId(1);  //Set id slave
  regBank.add(40001);  //Add register FC03, holding register, address 1
  regBank.set(40001,0);  //Set default value for 40001 is 0
  slave._device = &regBank;
  slave.setBaud(9600); //Set baudrate 9600
  
  analogReadResolution(12);  //Set Resolution adc is 12bit, can upto 14bit
}
void loop()
{
  int analog_In = (float)analogRead(mA_PIN) * 3300 / 100 / 4096;  //Get value 4-20mA
  
  regBank.set(40001, analog_In);  //Update value for 40001 is analog_In
  slave.run();  //Run service modbus RTU slave
  digitalWrite(LED, !digitalRead(LED)); //blink led
  delay(200);
}