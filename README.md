
# RAK3172_Canopus Board Quick Start Guide  
## ✌️✌️ Welcome! ✌️✌️  

Hi, i'm **Namnam** 🕴🏼.  
<p align="left">
<a href="https://fb.com/kuem0912" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/facebook.svg" alt="kuem0912" 
height="30" width="40" /></a>
<a href="https://wa.me/84969809444" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/whatsapp.svg" alt="84969809444" height="30" width="40" /></a>
</p>  
  
##### 📝Note: *Especially, you will get 3% discount on the total amount to pay when using code [CANOPUS](https://rakwireless.kckb.st/canopus) to shop at [https://store.rakwireless.com/products/](https://rakwireless.kckb.st/canopus)*
  
## What's included in this library:  
  
|    **Examples**   |               **Description**            | **Click download** |  
| --- | --- | :---: |
| Blink led| On/off led on board|[Go!](#blink-led)|
| **Lora P2P**      | Sender     |[Go!]|
|                   | Reciever|[Go!]|
|                   | Lora Ra02 - Lora Rak3172|[Go!](https://github.com/NamNamIoT/RAK3172_CANOPUS/blob/main/Rak2Ra02.md)|
| LoraWan           | Class B, Info, Multicast, ABP  |[Go!]|
| Modbus RTU        | RAK3172 is master|[Go!](#modbus-master)|
|                   | RAK3172 is slave               |[Go!](#modbus-slave)|
| General           | Powersave, timer, interupt     |[Go!]|
|                   | Multitasking                   |[Go!]|
| Sensor            | SHT3X (Temperature air)|[Go!](#sht3x)|
|                   | BH1750  (Light)|[Go!](#bh1750)|
| Read analog       | Read 0-10V sensor|[Go!](#read-analog)|
|                   | Read 4-20mA sensor|[Go!](#read-analog)|

[![GitHub Repo stars](https://img.shields.io/badge/share%20on-facebook-1976D2?logo=facebook)](https://www.facebook.com/sharer/sharer.php?u=https://github.com/NamNamIoT/RAK3172_CANOPUS)
[![GitHub Repo stars](https://img.shields.io/badge/share%20on-linkedin-3949AB?logo=linkedin)](https://www.linkedin.com/shareArticle?url=https://github.com/NamNamIoT/RAK3172_CANOPUS)
[![GitHub Repo stars](https://img.shields.io/badge/share%20on-twitter-03A9F4?logo=twitter)](https://twitter.com/share?url=https://github.com/NamNamIoT/RAK3172_CANOPUS)
[![GitHub Repo stars](https://img.shields.io/static/v1?label=Sponsor&message=%E2%9D%A4&logo=GitHub&color=ff69b4)](https://www.paypal.com/paypalme/thanhnamlt5)

  
## Information RAK3172_Canopus board  
  
|     **Object**    |      **Detail component**      |             **Note**         |
| --- | --- | --- |
| Power             | Solar or DC power              | Maximum 6VDC (V1, V2) or **18V (V3)**|  
| Solar charge      | LT4054 (V1, V2) or TP5100 (V3) | 800mA (V1, V2) or 2A (V3)            |
| RS485             | SP485EE                        | Protect over volt, current   |
| I2C               | -                              | Pullup internal ~100k        |
| 0-10V             | -                              | Resolution 14bit             |
| LORA SoC          | RAK3172		                     | STM32WL inside	              |
| Case              | Plastic                        | Size 100x68x50	              |  
  
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
🏷️Version 0.98 [March-2023] (Prototype).  
🏷️Version 0.99 [April-2023] (Prototype).  
🏷️Version 1.0 [June-2023].  
🏷️Version 2 [Oct-2023].  
🏷️**Version 3 [Jan-2024].**  

<img src="https://github.com/NamNamIoT/RAK3172_CANOPUS/assets/49629370/7da1e890-1e2c-4b1b-82d6-35317b26b6f7" height="450">  
<img src="https://github.com/NamNamIoT/RAK3172_CANOPUS/assets/49629370/f26dc802-9b8b-4454-9a64-da986ab88c23" height="450">  
  
### 🧑🏻‍🔧 Hardware Setup  
The RAK3172_Canopus requires a few hardware connections before you can make it work.  
The requirement is:  
-Antenna  
-USB type C  
-Battery 18650  
-Solar panel (Ex: 5V-3W)  

### 🧑🏼‍💻 Software setup  
##### Follow this guide:  
-[*Install IDE arduino, add RAK3172 to manager board and import Canopus library*](https://github.com/NamNamIoT/RAK3172_CANOPUS/blob/main/Readme_extension.md)  
-[*Compile an Example with RAK3172_Canopus board*](https://github.com/NamNamIoT/RAK3172_CANOPUS/blob/main/Readme_extension.md)  

### 🏷️RAK3172 I/O Pins and Peripherals

This section discusses how to use and access RAK3172 pins using the RUI3 API. It shows basic code on using digital I/O, analog input, UART, and I2C.

<img src="https://user-images.githubusercontent.com/49629370/224521329-eb63e943-dd5c-4a59-9920-9f6aa959f3dc.png" height="450" width="500">
  
This is table pin map of Rak3172_Canopus board.    

| **Alternative Pin Usage** | **Pin Name (V1)** | **Pin Name (V2)** | **Pin Name (V3)** | **Note** |  
| :---: | :---: | :---: | :---: | :---: |    
|LED_SEND | PA8 | PA8 | PA8 |           |  
|LED_SYNC | PA0 | **PA10** | PA10 |           |  
|LED_RECV | PB2 | PB2 | PB2 |           |  
|VSS_PIN | PB5 | PB5 | PB5 | Enable power sensor |  
|I2C_SDA | PA11 | PA11 | PA11 | I2C pin |  
|I2C_SCL | PA12 | PA12 | PA12 | I2C pin |  
|mA_PIN | PB3 | PB3 | **---** | 4-20mA |  
|Volt_PIN | PB4 | PB4 | PB4 | 0-10V |  
|VRS_485 | PB12 | **PA1** | PA1 | Enable power RS485 |  
|UART1_TX | PB6 | PB6 | PB6 | RS485 ModbusRTU |  
|UART1_RX | PB7 | PB7 | PB7 | RS485 ModbusRTU |  
|BATTERY_PIN | **PA15** | **---** | **PB3** |    |  

  
####  ⚠️ WARNING: Prepare yourself a cup of coffee ☕☕☕, because the next is a fascinating journey with Canopus board 🤪.   
  
#### How to Use Digital I/O  
##### Blink led  
  
- Use Arduino [digitalRead](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/) to read the value from a specified Digital I/O pin, either HIGH or LOW.
- Use Arduino [digitalWrite](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/) to write a HIGH or a LOW value to a Digital I/O pin.
  
> **tip 📝 NOTE:**  
> The GPIO Pin Name is the one to be used on the digitalRead and digitalWrite and NOT the pin numbers.
  
**Example code blink led on RAK3172_Canopus board**

```c
#include <Rak3172_Canopus.h>

void setup()
{
  pinMode(LED_SEND, OUTPUT); //Change the LED_SEND to any digital pin you want. Also, you can set this to INPUT or OUTPUT
}

void loop()
{
  digitalWrite(LED_SEND, HIGH); //Change the LED_SEND to any digital pin you want. Also, you can set this to HIGH or LOW state.
  delay(1000); // delay for 1 second
  digitalWrite(LED_SEND, LOW); //Change the LED_SEND to any digital pin you want. Also, you can set this to HIGH or LOW state.
  delay(1000); // delay for 1 second
}
```

#### How to Use Analog Input  
##### Read analog  
You can use any of the pins below as Analog Input.

| **Analog Port** | **Pin Name** | **Onboard** |
| --------------- | ------------ | ----------- |
| ADC4 (0-10V)    |  PA15        | AI1          |
| ADC5 (0-10V)    |  PA10        | AI2          |


Use Arduino [analogRead](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/) to read the value from the specified Analog Input pin.

<img src="https://github.com/NamNamIoT/RAK3172_CANOPUS/assets/49629370/c48d3ecc-73a6-4a35-ae64-f4ed497c8023" height="400" width="270"><img src="https://user-images.githubusercontent.com/49629370/224522583-21ff739b-7f3b-4a7d-9697-72e8b69e8c4a.png" height="400" width="500">
  
**Example code read analog on RAK3172_Canopus board**

```c
#include <Rak3172_Canopus.h>  // Include the Rak3172_Canopus library header file.

#define V3  // Define macro V3.

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud rate.
  Serial.println("Canopus Analog Example");  // Print a message indicating the start of the program.
  Serial.println("------------------------------------------------------");  // Print a separator line.
  pinMode(V_SS5, OUTPUT);  // Set pin V_SS5 as an output.
  digitalWrite(V_SS5, PWR_ON);  // Turn on the V_SS5 pin.
  analogReadResolution(12);  // Set analog read resolution to 12 bits.
}

void loop() {
  float AI1 = analogRead(AI1_PIN)*2.58;         // Read analog voltage from pin AI1_PIN and store it in AI1.
  Serial.printf("AI1 = %0.0fmV\r\n", AI1); // Print the analog voltage value of AI1 in millivolts.

  float AI2 = analogRead(AI2_PIN)*2.58;         // Read analog voltage from pin AI2_PIN and store it in AI2.
  Serial.printf("AI2 = %0.0fmV\r\n", AI2); // Print the analog voltage value of AI2 in millivolts.

  delay(1000);  // Wait for 1 second before the next iteration of the loop.
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


**Example Code modbus master read slave**

##### 📝Note: Make sure you have an ModbusRTU device connected to pin A and B on Rak3172_Canopus board.

```c
#include "Canopus_Modbus.h"
ModbusMaster node;
#include <Rak3172_Canopus.h>

uint8_t result;
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(VRS_PIN, OUTPUT);
  digitalWrite(VRS_PIN, PWR_ON);  //On power Vrs485
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
  digitalWrite(LED, !digitalRead(LED)); //blink led
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

  
##### Modbus slave  
*This example, our board is modbus **slave**. Board read AI(4-20mA) and set value register 040001 (FC03, address 1)*  
**Example Code modbus slave update value register**

```c
#include "modbus.h"
#include "modbusDevice.h"
#include "modbusRegBank.h"
#include "modbusSlave.h"
modbusDevice regBank;
modbusSlave slave;

#include <Rak3172_Canopus.h>

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
```

**I2C**

There is one I2C peripheral available on RAK3172.

| **I2C Pin Number** | **I2C Pin Name** |
| ------------------ | ---------------- |
| PA12               | I2C_SCL          |
| PA11               | I2C_SDA          |


- Use Arduino [Wire](https://www.arduino.cc/reference/en/language/functions/communication/wire/) library to communicate with I2C devices.

<img src="https://github.com/NamNamIoT/RAK3172_CANOPUS/assets/49629370/a8da41d4-12a5-4daa-89a1-7c62a2648887" height="350" width="250"><img src="https://user-images.githubusercontent.com/49629370/224522611-246efbcf-a1fb-4503-9ea5-41dc0b514656.png" height="350" width="500">

**Example Code**  
***Scan I2C***  
Make sure you have an I2C device connected to specified I2C pins to run the I2C scanner code below:

```c
#include <Wire.h>
#include <Rak3172_Canopus.h>

void setup()
{
  pinMode(VSS_PIN, OUTPUT);
  digitalWrite(VSS_PIN, PWR_ON); //enable power sensor
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
#include <Rak3172_Canopus.h>

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

***Read sensor BH1750***
##### BH1750  
  ```c
#include <Arduino.h>
#include <Wire.h>
#include <ArtronShop_BH1750.h>
#include <Rak3172_Canopus.h>

ArtronShop_BH1750 bh1750(0x23, &Wire); // Non Jump ADDR: 0x23, Jump ADDR: 0x5C

void setup() {
  Serial.begin(115200);
  Serial.print("\r\n************RAK3172_CANOPUS**************");
  pinMode(VSS_PIN, OUTPUT);
  digitalWrite(VSS_PIN, PWR_ON);
  Wire.begin();
  while (!bh1750.begin()) {
    Serial.println("BH1750 not found !");
    delay(1000);
  }
}

void loop() {
  Serial.print("Light: ");
  Serial.print(bh1750.light());
  Serial.print(" lx");
  Serial.println();
  delay(1000);
}
```

The Arduino Serial Monitor shows value.

```c
19:36:53.106 -> Light: 0.83 lx
19:36:54.088 -> Light: 0.83 lx
19:36:55.089 -> Light: 0.83 lx
19:36:56.103 -> Light: 0.83 lx
```
### Continue update  
