
# RAK3172_Canopus Board Quick Start Guide  
## ✌️✌️ Welcome! ✌️✌️  

##### Hi, i'm **Namnam** 🕴🏼.  
<p align="left">
<a href="https://fb.com/kuem0912" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/facebook.svg" alt="kuem0912" 
height="30" width="40" /></a>
<a href="https://wa.me/84969809444" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/whatsapp.svg" alt="84969809444" height="30" width="40" /></a>
</p>  
  
##### 📝Note: *Especially, you will get 3% discount on the total amount to pay when using code [CANOPUS](https://rakwireless.kckb.st/canopus) to shop at [https://store.rakwireless.com/products/](https://rakwireless.kckb.st/canopus)*

```c
$ tree
|-- Quick access table
|-- Information board
|      |-- Version hardware log
|      |-- Hardware Setup
|      |-- Software setup
|      |-- RAK3172 I/O
|-- Examples
|      |-- How to Use Digital I/O
|      |-- How to Use Analog Input
|      |-- How to Use Modbus RTU
|      |      |-- Modbus master
|      |      |-- Modbus slave
|      |-- How to Use I2C
|      |      |-- Scan I2C
|      |      |-- Read sensor SHT3X
|      |      |-- Read sensor BH1750
|      |-- How to use Lora P2P
|      |      |-- Sender
|      |      |-- Reciever
|      |-- How to use LoraWan
|      |-- How to get information System
|      |      |-- Powersave
|      |      |-- Time
|      |      |-- Timer
|      |      |-- General
|      |      |      |-- Battery Level
|      |      |      |-- Hardware ID
|      |      |      |-- Model ID
|      |      |      |-- Firmware Version
|      |      |      |-- AT Command Version
|      |      |      |-- RUI API Version
```

## Quick access panel  
  
|    **Examples**   |               **Description**            | **Click download** |  
| --- | --- | :---: |
| Digital I/O       | On/off led on board|[Go!](#blink-led)|
| Analog Input      | Read 0-10V sensor|[Go!](#read-analog)|
| Modbus RTU        | RAK3172 is master|[Go!](#modbus-master)|
|                   | RAK3172 is slave               |[Go!](#modbus-slave)|
| I2C               | SHT3X (Temperature air)|[Go!](#sht3x)|
|                   | BH1750  (Light)|[Go!](#bh1750)|
| Lora P2P          | Sender     |[Go!](#sender)|
|                   | Reciever|[Go!](#receive)|
|                   | Lora Ra02 - Lora Rak3172|[Go!](https://github.com/NamNamIoT/RAK3172_CANOPUS/blob/main/Rak2Ra02.md)|
| LoraWan           | Class B, Info, Multicast, ABP  |[Go!]|
| System            | Powersave     |[Go!](#Powersave)|
|                   | Time          |[Go!](#Time)|
|                   | Timer         |[Go!](#Timer)|
|                   | General       |[Go!](#General)|


[![GitHub Repo stars](https://img.shields.io/badge/share%20on-facebook-1976D2?logo=facebook)](https://www.facebook.com/sharer/sharer.php?u=https://github.com/NamNamIoT/RAK3172_CANOPUS)
[![GitHub Repo stars](https://img.shields.io/badge/share%20on-linkedin-3949AB?logo=linkedin)](https://www.linkedin.com/shareArticle?url=https://github.com/NamNamIoT/RAK3172_CANOPUS)
[![GitHub Repo stars](https://img.shields.io/badge/share%20on-twitter-03A9F4?logo=twitter)](https://twitter.com/share?url=https://github.com/NamNamIoT/RAK3172_CANOPUS)
[![GitHub Repo stars](https://img.shields.io/static/v1?label=Sponsor&message=%E2%9D%A4&logo=GitHub&color=ff69b4)](https://www.paypal.com/paypalme/thanhnamlt5)

  
## Information board   
#### 🕵🏻‍♀️Version hardware log   
🏷️Version 0.98 [March-2023] (Prototype).  
🏷️Version 0.99 [April-2023] (Prototype).  
🏷️Version 1.0 [June-2023].  
🏷️Version 2 [Oct-2023].  
🏷️**Version 3 [Jan-2024].**  

<img src="https://github.com/NamNamIoT/RAK3172_CANOPUS/assets/49629370/7da1e890-1e2c-4b1b-82d6-35317b26b6f7" height="450">  
<img src="https://github.com/NamNamIoT/RAK3172_CANOPUS/assets/49629370/f26dc802-9b8b-4454-9a64-da986ab88c23" height="450">  
  
#### 🧑🏻‍🔧 Hardware Setup  
The RAK3172_Canopus requires a few hardware connections before you can make it work.  
The requirement is:  
-Antenna  
-USB type C  
-Battery 18650  
-Solar panel (Ex: 5V-3W)  

#### 🧑🏼‍💻 Software setup  
##### Follow this guide:  
-[*Install IDE arduino, add RAK3172 to manager board and import Canopus library*](https://github.com/NamNamIoT/RAK3172_CANOPUS/blob/main/Readme_extension.md)  
-[*Compile an Example with RAK3172_Canopus board*](https://github.com/NamNamIoT/RAK3172_CANOPUS/blob/main/Readme_extension.md)  

#### 🏷️RAK3172 I/O Pins

This section discusses how to use and access RAK3172 pins using the RUI3 API. It shows basic code on using digital I/O, analog input, UART, and I2C.

<img src="https://user-images.githubusercontent.com/49629370/224521329-eb63e943-dd5c-4a59-9920-9f6aa959f3dc.png" height="450" width="500">
  
This is table pin map of Rak3172_Canopus board.    

| **Alternative Pin Usage** | **Pin Name (V1)** | **Pin Name (V2)** | **Pin Name (V3)** | **Note** |  
| :---: | :---: | :---: | :---: | :---: |    
|LED_SEND | PA8 | PA8 | PA8 |   BLUE color   |  
|LED_SYNC | PA0 | **PA10** | PA9 |   RED color   |  
|LED_RECV | PB2 | PB2 | PB2 | YELLOW color |  
|VSS_PIN  | PB5 | PB5 | PB5 | Enable power sensor |  
|I2C_SDA | PA11 | PA11 | PA11 | I2C pin |  
|I2C_SCL | PA12 | PA12 | PA12 | I2C pin |  
|mA_PIN | PB3 | PB3 | **---** |    -    |  
|AI1_PIN  | PB4 | PB4 | PB4 | 0-10V |  
|AI2_PIN  |  -  |  -  | **PA10** | 0-10V |  
|V_RS485  | PB12 | **PA1** | PA1 | Enable power RS485 |  
|UART1_TX | PB6 | PB6 | PB6 | RS485 ModbusRTU |  
|UART1_RX | PB7 | PB7 | PB7 | RS485 ModbusRTU |  
|BATTERY_PIN | PA15 | **---** | **PB3** | meansure battery   |  

  
####  ⚠️ WARNING: Prepare yourself a cup of coffee ☕☕☕, because the next is a fascinating journey with Canopus board 🤪.   

## Examples
### How to Use Digital I/O  
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

### How to Use Analog Input  
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

### How to Use Modbus RTU  
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
#define V3
uint8_t result;
void setup()
{
  pinMode(V_SS5, PWR_ON);
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
  digitalWrite(LED_YELLOW, !digitalRead(LED_YELLOW)); //blink led
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
#include <Rak3172_Canopus.h>
#define V3
#include "modbus.h"
#include "modbusDevice.h"
#include "modbusRegBank.h"
#include "modbusSlave.h"
modbusDevice regBank;
modbusSlave slave;


void setup()
{
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(V_SS5, OUTPUT);
  digitalWrite(V_SS5, PWR_ON);  //On power Vrs485
  pinMode(V_SS3, OUTPUT);
  digitalWrite(V_SS3, PWR_ON);  //On power Vsensor
  
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
  int analog_In = analogRead(AI1_PIN); 
  
  regBank.set(40001, analog_In);  //Update value for 40001 is analog_In
  slave.run();  //Run service modbus RTU slave
  digitalWrite(LED_YELLOW, !digitalRead(LED_YELLOW)); //blink led
  delay(200);
}
```

### How to Use I2C

There is one I2C peripheral available on RAK3172.

| **I2C Pin Number** | **I2C Pin Name** |
| ------------------ | ---------------- |
| PA12               | I2C_SCL          |
| PA11               | I2C_SDA          |


- Use Arduino [Wire](https://www.arduino.cc/reference/en/language/functions/communication/wire/) library to communicate with I2C devices.

<img src="https://github.com/NamNamIoT/RAK3172_CANOPUS/assets/49629370/a8da41d4-12a5-4daa-89a1-7c62a2648887" height="350" width="250"><img src="https://user-images.githubusercontent.com/49629370/224522611-246efbcf-a1fb-4503-9ea5-41dc0b514656.png" height="350" width="500">

**Example Code I2C**  
***Scan I2C***  
Make sure you have an I2C device connected to specified I2C pins to run the I2C scanner code below:

```c
#include <Wire.h>
#include <Rak3172_Canopus.h>
#define V3  // Define macro V3.

void setup()
{
  pinMode(V_SS3, OUTPUT);
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
#include <Arduino.h>  // Include the Arduino core library.
#include <Wire.h>  // Include the Wire library for I2C communication.
#include <ArtronShop_SHT3x.h>  // Include the SHT3x library.
#include <Rak3172_Canopus.h>  // Include the Rak3172_Canopus library header file.
#define V3  // Define macro V3.
ArtronShop_SHT3x sht3x(0x44, &Wire);  // ADDR: 0 => 0x44, ADDR: 1 => 0x45

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud rate.
  Serial.print("\r\n************RAK3172_CANOPUS**************");  // Print a message indicating the start of the program.
  pinMode(V_SS3, OUTPUT);  // Set pin V_SS3 as an output.
  digitalWrite(V_SS3, PWR_ON);  // Turn on the V_SS3 pin.
  delay(100);  // Wait for 100 milliseconds.
  Wire.begin();  // Initialize the I2C communication.
  while (!sht3x.begin()) {  // Check if SHT3x sensor is detected.
    Serial.println("SHT3x not found !");  // Print a message if SHT3x sensor is not detected.
    delay(1000);  // Wait for 1 second before retrying.
  }
}

void loop() {
  if (sht3x.measure()) {  // Check if the measurement is successful.
    Serial.print("Temperature: ");  // Print a label indicating the temperature measurement.
    Serial.print(sht3x.temperature(), 1);  // Print the temperature value with one decimal place.
    Serial.print(" *C\tHumidity: ");  // Print a label indicating the humidity measurement.
    Serial.print(sht3x.humidity(), 1);  // Print the humidity value with one decimal place.
    Serial.print(" %RH");  // Print unit (% relative humidity).
    Serial.println();  // Print a newline character.
  } else {
    Serial.println("SHT3x read error");  // Print a message if there is an error reading from the SHT3x sensor.
  }
  delay(1000);  // Wait for 1 second before the next measurement.
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
#include <Arduino.h>  // Include the Arduino core library.
#include <Wire.h>  // Include the Wire library for I2C communication.
#include <ArtronShop_BH1750.h>  // Include the BH1750 library.
#include <Rak3172_Canopus.h>  // Include the Rak3172_Canopus library header file.
#define V3  // Define macro V3.
ArtronShop_BH1750 bh1750(0x23, &Wire); // Non Jump ADDR: 0x23, Jump ADDR: 0x5C

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud rate.
  Serial.print("\r\n************RAK3172_CANOPUS**************");  // Print a message indicating the start of the program.
  pinMode(V_SS3, OUTPUT);  // Set pin V_SS3 as an output.
  digitalWrite(V_SS3, PWR_ON);  // Turn on the V_SS3 pin.
  Wire.begin();  // Initialize the I2C communication.
  while (!bh1750.begin()) {  // Check if BH1750 sensor is detected.
    Serial.println("BH1750 not found !");  // Print a message if BH1750 sensor is not detected.
    delay(1000);  // Wait for 1 second before retrying.
  }
}

void loop() {
  Serial.print("Light: ");  // Print a label indicating the light intensity measurement.
  Serial.print(bh1750.light());  // Print the light intensity value.
  Serial.print(" lx");  // Print unit (lux).
  Serial.println();  // Print a newline character.
  delay(1000);  // Wait for 1 second before the next measurement.
}
```

The Arduino Serial Monitor shows value.

```c
19:36:53.106 -> Light: 0.83 lx
19:36:54.088 -> Light: 0.83 lx
19:36:55.089 -> Light: 0.83 lx
19:36:56.103 -> Light: 0.83 lx
```

### Lora P2P
##### Sender
```c
#include <Rak3172_Canopus.h>
#define V3

long startTime;
bool rx_done = false;
double myFreq = 868000000;
uint16_t sf = 12, bw = 0, cr = 0, preamble = 8, txPower = 22;

void hexDump(uint8_t* buf, uint16_t len) {
  for (uint16_t i = 0; i < len; i += 16) {
    char s[len];
    uint8_t iy = 0;
    for (uint8_t j = 0; j < 16; j++) {
      if (i + j < len) {
        uint8_t c = buf[i + j];
        if (c > 31 && c < 128)
          s[iy++] = c;
      }
    }

    String msg = String(s);
    Serial.println(msg);
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
  sprintf(buff, "Incoming message, length: %d, RSSI: %d, SNR: %d",
          data.BufferSize, data.Rssi, data.Snr);
  Serial.println(buff);
  hexDump(data.Buffer, data.BufferSize);
  digitalWrite(LED_RECV, LOW);
}

void send_cb(void) {
  Serial.printf("P2P set Rx mode %s\r\n",
                api.lorawan.precv(65534) ? "Success" : "Fail");
}

void setup() {
  pinMode(LED_SEND, OUTPUT);
  digitalWrite(LED_SEND, LOW);
  pinMode(LED_SYNC, OUTPUT);
  digitalWrite(LED_SYNC, HIGH);
  Serial.begin(115200);
  Serial.println("RAK3172_Canopus LoRaWan P2P Example");
  Serial.println("------------------------------------------------------");
  delay(2000);
  startTime = millis();

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
  Serial.printf("Set P2P mode frequency %3.3f: %s\r\n", (myFreq / 1e6),
                api.lorawan.pfreq.set(myFreq) ? "Success" : "Fail");
  Serial.printf("Set P2P mode spreading factor %d: %s\r\n", sf,
                api.lorawan.psf.set(sf) ? "Success" : "Fail");
  Serial.printf("Set P2P mode bandwidth %d: %s\r\n", bw,
                api.lorawan.pbw.set(bw) ? "Success" : "Fail");
  Serial.printf("Set P2P mode code rate 4/%d: %s\r\n", (cr + 5),
                api.lorawan.pcr.set(cr) ? "Success" : "Fail");
  Serial.printf("Set P2P mode preamble length %d: %s\r\n", preamble,
                api.lorawan.ppl.set(preamble) ? "Success" : "Fail");
  Serial.printf("Set P2P mode tx power %d: %s\r\n", txPower,
                api.lorawan.ptp.set(txPower) ? "Success" : "Fail");
  api.lorawan.registerPRecvCallback(recv_cb);
  api.lorawan.registerPSendCallback(send_cb);
  Serial.printf("P2P set Rx mode %s\r\n",
                api.lorawan.precv(65534) ? "Success" : "Fail");
}

void loop() {
  uint8_t payload[] = "payload";
  bool send_result = false;
  while (!send_result) {
    send_result = api.lorawan.psend(sizeof(payload), payload);
    if (!send_result) {
      api.lorawan.precv(0);
      delay(1000);
    }
  }
  Serial.printf("P2P send Success\r\n");
  delay(1000);
  digitalWrite(LED_SYNC, !digitalRead(LED_SYNC));
}
```

##### Receive
```c
#include <Rak3172_Canopus.h>
#define V3

long startTime;
bool rx_done = false;
double myFreq = 868000000;
uint16_t sf = 12, bw = 0, cr = 0, preamble = 8, txPower = 22;

void recv_cb(rui_lora_p2p_recv_t data) {
  rx_done = true;
  if (data.BufferSize == 0) {
    Serial.println("Empty buffer.");
    return;
  }
  digitalWrite(LED_RECV, HIGH);
  char buff[92];
  sprintf(buff, "Incoming message, length: %d, RSSI: %d, SNR: %d",
          data.BufferSize, data.Rssi, data.Snr);
  Serial.println(buff);
  digitalWrite(LED_RECV, LOW);
}

void send_cb(void) {
  Serial.printf("P2P set Rx mode %s\r\n",
                api.lorawan.precv(65534) ? "Success" : "Fail");
}

void setup() {
  pinMode(LED_SEND, OUTPUT);
  pinMode(LED_RECV, OUTPUT);
  pinMode(LED_SYNC, OUTPUT);
  Serial.begin(115200);
  Serial.println("RAK3172_Canopus LoRaWan P2P Example");
  Serial.println("------------------------------------------------------");
  delay(2000);
  startTime = millis();

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
  Serial.printf("Set P2P mode frequency %3.3f: %s\r\n", (myFreq / 1e6),
                api.lorawan.pfreq.set(myFreq) ? "Success" : "Fail");
  Serial.printf("Set P2P mode spreading factor %d: %s\r\n", sf,
                api.lorawan.psf.set(sf) ? "Success" : "Fail");
  Serial.printf("Set P2P mode bandwidth %d: %s\r\n", bw,
                api.lorawan.pbw.set(bw) ? "Success" : "Fail");
  Serial.printf("Set P2P mode code rate 4/%d: %s\r\n", (cr + 5),
                api.lorawan.pcr.set(cr) ? "Success" : "Fail");
  Serial.printf("Set P2P mode preamble length %d: %s\r\n", preamble,
                api.lorawan.ppl.set(preamble) ? "Success" : "Fail");
  Serial.printf("Set P2P mode tx power %d: %s\r\n", txPower,
                api.lorawan.ptp.set(txPower) ? "Success" : "Fail");
  api.lorawan.registerPRecvCallback(recv_cb);
  api.lorawan.registerPSendCallback(send_cb);
  Serial.printf("P2P set Rx mode %s\r\n",
                api.lorawan.precv(65534) ? "Success" : "Fail");
}

void loop() {
  uint8_t payload[] = "payload_B";
  bool send_result = false;
  if (rx_done) {
    rx_done = false;
    while (!send_result) {
      digitalWrite(LED_SEND, HIGH);
      send_result = api.lorawan.psend(sizeof(payload), payload);
      Serial.printf("P2P send %s\r\n", send_result ? "Success" : "Fail");
      if (!send_result) {
        Serial.printf("P2P finish Rx mode %s\r\n", api.lorawan.precv(0) ? "Success" : "Fail");
        delay(1000);
      }
    }
    digitalWrite(LED_SEND, LOW);
  }
  delay(500);
  digitalWrite(LED_SYNC, !digitalRead(LED_SYNC));
}
```

### System
##### Powersave
```c
void setup()
{
    Serial.begin(115200);
    Serial.println("RAKwireless System Powersave Example");
    Serial.println("------------------------------------------------------");

}

void loop()
{
    Serial.print("The timestamp before sleeping: ");
    Serial.print(millis());
    Serial.println(" ms");
    Serial.println("(Wait 10 seconds or Press any key to wakeup)");
    api.system.sleep.all(10000);
    Serial.print("The timestamp after sleeping: ");
    Serial.print(millis());
    Serial.println(" ms");
}
```

##### Time
```c
/***
 *  This example shows time function, including millis, micros, delay, delayMicroseconds.
***/

long delayTime = 1000;		// variable for setting the delay time 

void setup()
{
    // initialize serial communication at 115200 bits per second
    Serial.begin(115200);

    Serial.println("RAKwireless Arduino Time Example");
    Serial.println("------------------------------------------------------");
}

void loop()
{
    Serial.println("Now Time:");
    Serial.print("millis(): ");
    Serial.println(millis());	// show the time with millis
    Serial.print("micros(): ");
    Serial.println(micros());	// show the time with micros
  
    Serial.printf("After Delay %d milliseconds\n", delayTime);
    delay(delayTime);		// delay time (second)
    Serial.print("millis(): ");
    Serial.println(millis());	// show the time with millis
    Serial.print("micros(): ");
    Serial.println(micros());	// show the time with micros
  
    Serial.printf("After Delay %d microseconds\n", delayTime);
    delayMicroseconds(delayTime);	// delay time (Microseconds)
    Serial.print("millis(): ");
    Serial.println(millis());	// show the time with millis
    Serial.print("micros(): ");
    Serial.println(micros());	// show the time with micros
  
    Serial.println("");
  
    delayTime += 1000;		// delay time add 1000
  
    delay(5000);
}
```
 
##### Timer
```c
void handler(void *data)
{
    Serial.printf("[%lu]This is the handler of timer #%d\r\n", millis(), (int)data);
    /* Actually, the handler is not executed in interrupt context. The real ISR for timer just sends an event to the system event queue.
     * If main loop found there is any event in the event queue, the handler for that event will be processed. */
}

void setup()
{
    Serial.begin(115200);
  
    Serial.println("RAKwireless System Timer Example");
    Serial.println("------------------------------------------------------");
  
    for (int i = 0 ; i < RAK_TIMER_ID_MAX ; i++) {
        if (api.system.timer.create((RAK_TIMER_ID)i, (RAK_TIMER_HANDLER)handler, RAK_TIMER_PERIODIC) != true) {
            Serial.printf("Creating timer #%d failed.\r\n", i);
            continue;
        }
        if (api.system.timer.start((RAK_TIMER_ID)i, (i+1)*1000, (void *)i) != true) {
            Serial.printf("Starting timer #%d failed.\r\n", i);
            continue;
        }
    }
}

void loop()
{
}
```
  
##### General
```c
/***
 *  This example print the device information.
***/
int i;
void setup()
{
    Serial.begin(115200);
    Serial.println("RAKwireless System General Example");
    Serial.println("------------------------------------------------------");
    api.system.restoreDefault();
}

void loop()
{
    if (++i == 20) {
        Serial.printf("Reboot now..\r\n");
        api.system.reboot();
    }
    Serial.printf("===Loop %d==\r\n", i);
    Serial.printf("Firmware Version: %s\r\n",
		api.system.firmwareVersion.get().c_str());
    Serial.printf("AT Command Version: %s\r\n",
		api.system.cliVersion.get().c_str());
    Serial.printf("RUI API Version: %s\r\n",
		api.system.apiVersion.get().c_str());
    Serial.printf("Model ID: %s\r\n", api.system.modelId.get().c_str());
    Serial.printf("Hardware ID: %s\r\n", api.system.chipId.get().c_str());
    Serial.printf("Battery Level: %f\r\n", api.system.bat.get());
    delay(1000);
}
```
### Continue update  
[Click go top](#Quick-access-panel)
