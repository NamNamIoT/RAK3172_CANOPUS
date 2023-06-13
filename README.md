
# RAK3172_Canopus Board Quick Start Guide  
## ✌️✌️ Welcome! ✌️✌️  

Hi, im **Namnam** 🕴🏼.  
Please contact me if you need to develop IoT products.  
<p align="left">
<a href="https://fb.com/kuem0912" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/facebook.svg" alt="kuem0912" 
height="30" width="40" /></a>
<a href="https://wa.me/84969809444" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/whatsapp.svg" alt="84969809444" height="30" width="40" /></a>
</p>
  
#### 🎉🎉🎉*RAK3172_Canopus has become part of the [Rakwireless ecosystem.](https://rakwireless.kckb.st/canopus)* 
##### 📝 *Find Gateway of Rak3172_Canopus at [here.](https://rakwireless.kckb.st/canopus)*  
##### 📝 *Especially, you will get 3% discount on the total amount to pay when using code [CANOPUS](https://rakwireless.kckb.st/canopus) to shop at [https://store.rakwireless.com/products/](https://rakwireless.kckb.st/canopus)*

  
  
## Here's a quick summary of what's included in this library:  
  
|    **Examples**   |          **Description**       | **Available** |  
| ----------------- | ------------------------------ | --------------|  
| [Blink led](#blink-led)         | Pin PA8                        |       ☑       |  
| [Read analog](#read-analog)     | Read 0-10V sensor              |       ☑       |  
|                                | Read 4-20mA sensor             |       ☑       |  
| [Serial1](#uart)           | Serial1 print                  |       ☑       |  
| [Modbus RTU](#modbus-master)        | RAK3172 is master              |       ☑       |  
|                   | RAK3172 is slave               |       ☐       |  
| Lora P2P          | Sender (send value sensor)     |       ☑       |  
|                   | Reciever (request from gateway)|       ☑       |  
| LoraWan           | Class B, Info, Multicast, ABP  |       ☑       |  
| General           | Powersave, timer, interupt     |       ☑       |  
|                   | Multitasking,                  |       ☑       |  
| Sensor            | DHT11, DHT21, DHT22, AM23xx    |       ☐       |  
|                   | DS18B20			                   |       ☐       |  
|                   | SR04 Ultrasonic                |       ☐       |  
|                   | VL53L1x Sensor                 |       ☐       |  
|                   | Adafruit STEMMA Soil           |       ☐       |  
|                   | [SHT3X](#sht3x)                          |       ☑       |  

All examples not yet available, we have plan update in Q3-2023  
Regarding One-Wire sensors, we will wait for support from RAK team in Q3-2023.  
Currently because of RUI3 limitations, there is no official library for this communication standard from Rakwireless.  
  
## Information RAK3172_Canopus board  
  
|     **Object**    |      **Detail component**      |          **Note**      |  
| ----------------- | ------------------------------ | ---------------------- |  
| Power             | Solar 5V or DC 5V              | Maximun 6VDC             |  
| Solar charge      | LT4054			                   | upto 800mA             |  
| RS485             | SP485EE                        | Serial1, auto DERE     |  
| I2C               | -                              | SDA = PA12, SCL = PA11 |  
| One-wire          | -                              | PA10		                |  
| 4-20mA            | -                              | PB3 (ADC1)	            |  
| LORA SoC          | RAK3172		                     | STM32WL inside	        |  
| Case              | Plastic                        |              	        |    
  
### RF Characteristics

The RAK3172 supports two different frequency variations: RAK3172(L) Low Radio Frequency and RAK3172(H) High Radio Frequency.

#### Operating Frequencies

| Module     | Region        | Frequency     |
| ---------- | ------------- | ------------- |
| RAK3172(L) | Europe        | EU433         |
|            | China         | CN470         |
| RAK3172(H) | Europe        | EU868         |
|            | North America | US915         |
|            | Australia     | AU915         |
|            | Korea         | KR920         |
|            | Asia          | AS923-1/2/3/4 |
|            | India         | IN865         |
|            | Russia        | RU864         |
  
#### 🕵🏻‍♀️Version hardware log   
🏷️Version 0.98 [March-2023] First version  
🏷️Version 0.99 [April-2023] Change to use typeC vertical, fix some bug hardware V0.98 👋  
🏷️Version 1.0 [June-2023] Upgrade charge battery, solar charge.  

<img src="https://user-images.githubusercontent.com/49629370/224533350-f1d8af92-e01a-412e-9fec-aa1b8b0195c0.jpg" height="350"><img src="https://user-images.githubusercontent.com/49629370/236106303-ffb90c4f-a551-4fc7-9612-1e5bb125eecb.png" height="350"> 

### 🧑🏻‍🔧 Hardware Setup  
The RAK3172_Canopus requires a few hardware connections before you can make it work.  
The bare minimum requirement is to have the power section properly configured,  antenna, and USB type C.

### 🧑🏼‍💻 Software setup  
##### Follow this guide:  
-[*Install IDE arduino, add RAK3172 to manager board and import Canopus library*](https://github.com/NamNamIoT/RAK3172_CANOPUS/blob/main/Readme_extension.md)  
-[*Compile an Example with RAK3172_Canopus board*](https://github.com/NamNamIoT/RAK3172_CANOPUS/blob/main/Readme_extension.md)  

### 🏷️🏷️RAK3172 I/O Pins and Peripherals

This section discusses how to use and access RAK3172 pins using the RUI3 API. It shows basic code on using digital I/O, analog input, UART, and I2C.

<img src="https://user-images.githubusercontent.com/49629370/224521329-eb63e943-dd5c-4a59-9920-9f6aa959f3dc.png" height="450" width="500">

#### How to Use Digital I/O  
##### Blink led  
This is table pin map of Rak3172_Canopus board.    

| **Pin Name** | **Alternative Pin Usage** |
| ------------ | ------------------------- |
| PA8          | LED_SEND                  |
| PA0          | LED_SYNC                  |
| PB2          | LED_RECV                  |
| PA9          | LED_YELLOW  (only v0.98)  |
| PB5          | Enable power sensor       |
| PA11         | I2C_SDA or One-Wire       |
| PA12         | I2C_SCL or One-Wire       |
| PB3          | ADC1      4-20mA          |
| PB4          | ADC2      0-10V           |
| PB12         | Enable power RS485        |
| PB6          | UART1_TX  RS485 MODBUSRTU |
| PB7          | UART1_RX  RS485 MODBUSRTU |


- Use Arduino [digitalRead](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/) to read the value from a specified Digital I/O pin, either HIGH or LOW.
- Use Arduino [digitalWrite](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/) to write a HIGH or a LOW value to a Digital I/O pin.

:::tip 📝 NOTE:
The GPIO Pin Name is the one to be used on the digitalRead and digitalWrite and NOT the pin numbers.
:::

####  ⚠️ WARNING: Prepare yourself a cup of coffee ☕☕☕, because the next is a fascinating journey with Canopus board 🤪.   
You will be stronger after working through the next 12 examples. 

**Example code blink led yellow on RAK3172_Canopus board**

```c
void setup()
{
  pinMode(PA8, OUTPUT); //Change the PA8 to any digital pin you want. Also, you can set this to INPUT or OUTPUT
}

void loop()
{
  digitalWrite(PA8,HIGH); //Change the PA8 to any digital pin you want. Also, you can set this to HIGH or LOW state.
  delay(1000); // delay for 1 second
  digitalWrite(PA8,LOW); //Change the PA8 to any digital pin you want. Also, you can set this to HIGH or LOW state.
  delay(1000); // delay for 1 second
}
```

#### How to Use Analog Input  
##### Read analog  
You can use any of the pins below as Analog Input.

| **Analog Port** | **Pin Name** |
| --------------- | ------------ |
| ADC1 (4-20mA)   | PB3          |
| ADC2 (0-10V)    | PB4          |


Use Arduino [analogRead](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/) to read the value from the specified Analog Input pin.

<img src="https://user-images.githubusercontent.com/49629370/224522583-21ff739b-7f3b-4a7d-9697-72e8b69e8c4a.png" height="400" width="500">  
  
**Example code read analog on RAK3172_Canopus board**

```c
#define analogPin PB3

int val = 0;  // variable to store the value read

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val);          // debug value
  delay(100);
}
```

#### How to Use Serial Interfaces  
##### UART

There are two UART peripherals available on the RAK3172 module. There are also different [Serial Operating Modes](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/#rui3-serial-operating-modes) possible in RUI3, namely [Binary Mode](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/Binary-Command-Manual/), [AT Mode](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/), and [Custom Mode](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/Custom-Mode/).


| **Serial Port**   | **Serial Instance Assignment** | **Default Mode** |
| ----------------- | ------------------------------ | ---------------- |
| UART1 (pins 4, 5) | Serial1                        | Custom Mode      |
| UART2 (pins 1, 2) | Serial                         | AT Command       |

<img src="https://user-images.githubusercontent.com/49629370/224522599-7e96ce64-dc19-47e5-b921-4494c3b7081b.png" height="300" width="450">  

**Example Code**  
```c
void setup()
{
  Serial1.begin(115200); // use Serial1 for UART1 and Serial for UART2
                         // you can designate separate baudrate for each.
  Serial.begin(115200);
}

void loop()
{
  Serial1.println("RAK3172 UART1 TEST!");
  Serial.println("RAK3172 UART2 TEST!");
  delay(1000); // delay for 1 second
}

```

#### How to Use Modbus RTU  
##### Modbus master  
*This example, our board is modbus master.*

Modbus RTU use Serial1 on RAK3172_Canopus board

| **Serial Port**   | **Serial Instance Assignment** | **Default Mode** |
| ----------------- | ------------------------------ | ---------------- |
| UART1 (pins 4, 5) | Serial1                        | Custom Mode      |

![RAKmodbus](https://user-images.githubusercontent.com/49629370/224534542-f279d2f3-cd5c-4dbe-8af6-d8c383c315a0.PNG)


**Example Code**

Make sure you have an ModbusRTU device connected to pin A and B on Rak3172_Canopus board:

```c
#include "Canopus_Modbus.h"
ModbusMaster node;
#define LED_YELLOW PA8
uint8_t result;
void setup()
{
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
  digitalWrite(LED_YELLOW, !digitalRead(PA8)); //blink led yellow
  delay(500);
}
```

The Arduino Serial Monitor shows the value of register:

```c
Example read modbus RTU for RAK3172_Canopus board
Value 40000: 1
Value 40001: 2
Value 40002: 3
Value 40003: 4
Value 40004: 5
Value 40005: 6
Value 40006: 7
Value 40007: 8
Value 40008: 9
Value 40009: 10
```
**I2C**

There is one I2C peripheral available on RAK3172.

| **I2C Pin Number** | **I2C Pin Name** |
| ------------------ | ---------------- |
| PA12               | I2C_SCL          |
| PA11               | I2C_SDA          |


- Use Arduino [Wire](https://www.arduino.cc/reference/en/language/functions/communication/wire/) library to communicate with I2C devices.

<img src="https://user-images.githubusercontent.com/49629370/224522611-246efbcf-a1fb-4503-9ea5-41dc0b514656.png" height="350" width="500">

**Example Code**  
***Scan I2C***  
Make sure you have an I2C device connected to specified I2C pins to run the I2C scanner code below:

```c
#include <Wire.h>

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  while (!Serial);
  Serial.println("\nI2C Scanner");
}

void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmission to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
  delay(5000);           // wait 5 seconds for next scan
}
```

The Arduino Serial Monitor shows the I2C device found.

```c
17:29:15.690 -> Scanning...
17:29:15.738 -> I2C device found at address 0x28  !
17:29:15.831 -> done
17:29:15.831 ->
17:29:20.686 -> Scanning...
17:29:20.733 -> I2C device found at address 0x28  !
17:29:20.814 -> done
17:29:20.814 ->
```
  
***Read sensor SHT3X***
##### SHT3X  
  ```c
#include <Arduino.h>
#include <Wire.h>
#include <ArtronShop_SHT3x.h>
#define VSS_PIN PB5
#define PWR_ON LOW
ArtronShop_SHT3x sht3x(0x44, &Wire); // ADDR: 0 => 0x44, ADDR: 1 => 0x45

void setup() {
  Serial.begin(115200);
   Serial.print("\r\n************RAK3172_CANOPUS**************");
  pinMode(VSS_PIN, OUTPUT);
  digitalWrite(VSS_PIN, PWR_ON); //enable power sensor
  delay(100);
  Wire.begin();
  while (!sht3x.begin()) {
    Serial.println("SHT3x not found !");
    delay(1000);
  }
}

void loop() {
  if (sht3x.measure()) {
    Serial.print("Temperature: ");
    Serial.print(sht3x.temperature(), 1);
    Serial.print(" *C\tHumidity: ");
    Serial.print(sht3x.humidity(), 1);
    Serial.print(" %RH");
    Serial.println();
  } else {
    Serial.println("SHT3x read error");
  }
  delay(1000);
}
```

The Arduino Serial Monitor shows value.

```c
18:53:24.520 -> Temperature: 33.2 *C	Humidity: 76.1 %RH
18:53:25.504 -> Temperature: 33.2 *C	Humidity: 75.8 %RH
18:53:26.521 -> Temperature: 33.2 *C	Humidity: 76.0 %RH
18:53:27.534 -> Temperature: 33.2 *C	Humidity: 76.3 %RH
```
### Continue update  
  

[Buy me coffee☕](https://www.paypal.com/donate/?cmd=_s-xclick&hosted_button_id=U9ZHRXAWPY688&ssrt=1683260874159)  

