#include "Canopus_Modbus.h"
#include "Rak3172_Canopus.h"
ModbusMaster node;

uint8_t result;
void setup()
{
  pinMode(VRS_PIN, PWR_ON);
  pinMode(LED_YELLOW, OUTPUT);
  Serial.begin(115200);
  Serial.print("\r\n*****************RAK3172_CANOPUS*******************");
  Serial_Canopus.begin(9600, SERIAL_8N1);

}
void loop()
{
  //***************READ node 1**************************
  node.begin(1, Serial_Canopus); //slave ID node
  Serial.printf("");
  Serial.printf("\r\n\n\nExample read modbus RTU for RAK3172_Canopus board");

  result = node.readHoldingRegisters(0, 10);//Read 40000 to 40009
  delay(10);
  if (result == node.ku8MBSuccess) //Read success
  {
    for (uint8_t i = 0; i < 10; i ++ )
    {
      Serial.printf("\r\nValue 4000%d: %d", i, node.getResponseBuffer(i));
    }
  }
  else Serial.print("Read Fail node 1"); //read fail
  digitalWrite(LED_YELLOW, !digitalRead(PA8)); //blink led
  delay(500);
}
