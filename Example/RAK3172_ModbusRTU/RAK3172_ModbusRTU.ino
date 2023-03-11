#include "Canopus_Modbus.h"
ModbusMaster node;
uint8_t result;
void setup()
{
  pinMode(PA8, OUTPUT);
  pinMode(PA9, OUTPUT);
  Serial.begin(115200);
  Serial.print("\r\n*****************KIT DEV ESP32*******************");
  Serial_Canopus.begin(9600, SERIAL_8N1); 
  
}
void loop()
{ 
  //***************READ node 1**************************
  node.begin(1, Serial_Canopus); //ID node 1
  Serial.println("");
  Serial.println("Wait Read node 1");

  result = node.readHoldingRegisters(1, 4);//Read 40001, 40002, 40003
  delay(10);
  if (result == node.ku8MBSuccess) //Read ok
  {
    uint16_t data[3];
    data[0]=node.getResponseBuffer(0);
    data[1]=node.getResponseBuffer(1);
    data[2]=node.getResponseBuffer(2);
    Serial.printf("\r\nValue 40001: %d",data[0]);
    Serial.printf("\r\nValue 40002: %d",data[1]);
    Serial.printf("\r\nValue 40003: %d",data[2]);
  }
  else Serial.print("Read Fail node 1");
  
// //***************READ node 2**************************
//  node.begin(2, Serial_Canopus); //ID node 2
//  Serial.println("");
//  Serial.println("Wait Read node 2");
//  result = node.readHoldingRegisters(1, 4);//Read 40001, 40002, 40003
//  delay(10);
//  if (result == node.ku8MBSuccess) //Read ok
//  {
//    uint16_t data[3];
//    data[0]=node.getResponseBuffer(0);
//    data[1]=node.getResponseBuffer(1);
//    data[2]=node.getResponseBuffer(2);
//    Serial.printf("\r\nValue 40001: %d",data[0]);
//    Serial.printf("\r\nValue 40002: %d",data[1]);
//    Serial.printf("\r\nValue 40003: %d",data[2]);
//  }
//  else Serial.print("Read Fail node 2");
  digitalWrite(PA8, !digitalRead(PA8));
  delay(500); 
}
