
# RAK3172_Canopus Module Quick Start Guide  
## ✌️✌️ Welcome! ✌️✌️  
Hi, im Namnam 🕴🏼.  
Please contact me if you need to develop IoT products.  
<p align="left">
<a href="https://fb.com/kuem0912" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/facebook.svg" alt="kuem0912" 
height="30" width="40" /></a>
<a href="https://wa.me/84969809444" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/whatsapp.svg" alt="84969809444" height="30" width="40" /></a>
</p>

## Information RAK3172_Canopus board
|     **Object**    |      **Detail component**      |          **Note**      |
| ----------------- | ------------------------------ | ---------------------- |
|        Power      | LP5301QVF                      | 5-30VDC                |
|    Solar charge   | LT4054			     | upto 800mA             |
|        RS485      | SP485EE                        | Serial1, auto DERE     |
|         I2C       | -                              | SDA = PA12, SCL = PA11 |
|      One-wire     | -                              | PA10		      |
|        4-20mA     | -                              | PB3 (ADC1)	      |
|      Led blue     | -                              | PIN PA9                |
|      Led yellow   | -                              | PIN PA8                |
|      LORA SoC     | RAK3172		             | STM32WL inside	      |
|       Case        | Plastic                        | IP65         	      | 

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

### Electrical Characteristics

#### Operating Current

| Feature           | Condition | Minimum                              | Typical | Maximum | Unit |
| ----------------- | --------- | ------------------------------------ | ------- | ------- | ---- |
| Operating Current | TX Mode   | 87 (@&nbsp;20&nbsp;dBm 868&nbsp;Mhz) |         |         | mA   |
|                   | RX Mode   | 5.22                                 |         |         | mA   |

##### Sleep Current

| Feature             | Condition | Minimum (2.1&nbsp;V) | Typical (3.3&nbsp;V) | Maximum | Unit |
| ------------------- | --------- | -------------------- | -------------------- | ------- | ---- |
| Current Consumption | EU868     | -                    | 1.69                 | -       | μA   |
|                     | US915     | -                    | 1.69                 | -       | μA   |
|                     | CN470     | -                    | 1.69                 | -       | μA   |

:::tip 📝 NOTE:
For the reference application schematic of RAK3172 with minimum components requirements, refer to the [RAK3272S Breakout Board Datasheet.](https://docs.rakwireless.com/Product-Categories/WisDuo/RAK3272S-Breakout-Board/Datasheet/#schematic-diagram)
:::

#### 🕵🏻‍♀️Version 0.98[First version] ==> Version 0.99 [Change to use typeC vertical, fix some bug hardware V0.98 👋]  
<img src="https://user-images.githubusercontent.com/49629370/224533350-f1d8af92-e01a-412e-9fec-aa1b8b0195c0.jpg" height="350"><img src="https://user-images.githubusercontent.com/49629370/236106303-ffb90c4f-a551-4fc7-9612-1e5bb125eecb.png" height="350"> 

### 🧑🏻‍🔧 Hardware Setup  
The RAK3172_Canopus requires a few hardware connections before you can make it work. The bare minimum requirement is to have the power section properly configured,  antenna, and USB type C.

### 🧑🏼‍💻 Software setup  
##### [Follow this guide: Install IDE arduino, add RAK3172 to manager board and import Canopus library](https://github.com/NamNamIoT/RAK3172_CANOPUS/blob/main/Readme_extension.md)  
##### [Compile an Example with RAK3172_Canopus board](https://github.com/NamNamIoT/RAK3172_CANOPUS/blob/main/Readme_extension.md)  

### RAK3172 I/O Pins and Peripherals

This section discusses how to use and access RAK3172 pins using the RUI3 API. It shows basic code on using digital I/O, analog input, UART, and I2C.

![rak3172-pins](https://user-images.githubusercontent.com/49629370/224521329-eb63e943-dd5c-4a59-9920-9f6aa959f3dc.png)

#### How to Use Digital I/O

You can use any of the pins below as Digital Pin.


| **Pin Name** | **Alternative Pin Usage** |
| ------------ | ------------------------- |
| PA8          | LED_YELLOW                |
| PA9          | LED_GREEN  (only v0.98)   |
| PA10         | One-Wire                  |
| PA11         | I2C_SDA                   |
| PA12         | I2C_SCL                   |
| PB3          | ADC1                      |
| PB4          | ADC2                      |
| PB6          | UART1_TX  RS485 MODBUSRTU |
| PB7          | UART1_RX  RS485 MODBUSRTU |

![rak3172-io-pins](https://user-images.githubusercontent.com/49629370/224521420-2f575c71-559b-45e6-a3ad-e7ac7075fcd9.png)

The pins listed below must not be used.

| **Pin name** | **Pin Usage**                                                                                                                                     |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| PA2          | UART2_TX                                                                                                                                          |
| PA3          | UART2_RX                                                                                                                                          |
| PA13         | SWDIO                                                                                                                                             |
| PA14         | SWCLK                                                                                                                                             |
| PB8          | RAK3172 Internal                                                                                                                                  |
| PB12         | Internal 10k pull-up resistor for RAK3172 high frequency variant (8xx - 9xx Mhz) or pull-down resistor for RAK3172 low frequency variant (4xx Mhz)|


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

You can use any of the pins below as Analog Input.

| **Analog Port** | **Pin Name** |
| --------------- | ------------ |
| ADC1            | PB3          |
| ADC2            | PB4          |


Use Arduino [analogRead](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/) to read the value from the specified Analog Input pin.

![rak3172-adc-pins](https://user-images.githubusercontent.com/49629370/224522583-21ff739b-7f3b-4a7d-9697-72e8b69e8c4a.png)


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

**UART**

There are two UART peripherals available on the RAK3172 module. There are also different [Serial Operating Modes](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/#rui3-serial-operating-modes) possible in RUI3, namely [Binary Mode](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/Binary-Command-Manual/), [AT Mode](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/AT-Command-Manual/), and [Custom Mode](https://docs.rakwireless.com/RUI3/Serial-Operating-Modes/Custom-Mode/).


| **Serial Port**   | **Serial Instance Assignment** | **Default Mode** |
| ----------------- | ------------------------------ | ---------------- |
| UART1 (pins 4, 5) | Serial1                        | Custom Mode      |
| UART2 (pins 1, 2) | Serial                         | AT Command       |

![rak3172-uart-pins](https://user-images.githubusercontent.com/49629370/224522599-7e96ce64-dc19-47e5-b921-4494c3b7081b.png)

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

**Modbus RTU**

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


![rak3172-i2c-pins](https://user-images.githubusercontent.com/49629370/224522611-246efbcf-a1fb-4503-9ea5-41dc0b514656.png)

**Example Code**

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

**SPI**

If your RUI3 project uses SPI, then PA4 to PA7 pins are reserved for RUI3 SPI interface.


:::tip 📝 NOTE:
PA13 and PA14 pins are reserved for SWD debug interface. Check the [Connect to the RAK3172](#connect-to-the-rak3172) section.
:::

#### LoRaWAN Example

This example illustrates how to program RAK3172 module as a stand-alone LoRaWAN end-device via [RUI3 Arduino APIs](https://docs.rakwireless.com/RUI3/Arduino-API/). To use RAK3172 module as a LoRaWAN end-device, it needs to be within reach of a working **LoRaWAN gateway** registered to a **LoRaWAN network server (LNS)** or with a built-in network server.

:::tip 📝 NOTE:
If you are new to LoRaWAN, here are a few good references about LoRaWAN and gateways:

- [LoRaWAN 101](https://news.rakwireless.com/lorawan-r-101-all-you-need-to-know/)
- [What is a LoRaWAN Gateway](https://news.rakwireless.com/what-is-a-lorawan-gateway/)
- [How do LoRaWAN Gateways work?](https://news.rakwireless.com/how-do-lorawan-gateways-work/)
- [Things to Consider When Picking A LoRaWAN Gateway](https://news.rakwireless.com/things-to-consider-when-picking-a-lorawan-gateway/)

RAKwireless LoRaWAN gateway models like [WisGate Edge](https://store.rakwireless.com/collections/wisgate-edge) have built-in network servers. It is also common that the LoRaWAN network server is external or in the cloud. The popular LoRaWAN network server in the cloud that you can use for free (but offers enterprise service, too) is [TTN](https://www.thethingsnetwork.org/).

To correctly run this example, it is necessary to configure the LoRaWAN parameters and create an OTAA application on your LoRaWAN gateway.

:::

##### Register the LoRaWAN Gateway on TTNv3 Community Edition

After configuring your gateway, you need to register it in TTNv3:

1. Log in to the TTNv3 Network Server with a web browser.

- [Europe](https://eu1.cloud.thethings.network/)
- [North America](https://nam1.cloud.thethings.network/)
- [Australia](https://au1.cloud.thethings.network/)

2. Navigate to the **Console** page and click on **gateway** icon.

![ttnv3-initial](https://user-images.githubusercontent.com/49629370/224522665-860970ca-7272-4955-9953-532928a196cd.png)

3. On **General Settings**, enter the **Gateway ID**, **Gateway EUI**, and **Gateway Name**. This information is available in your LoRaWAN gateway configuration. Select the **Gateway Server address** according to the region where the LoRaWAN gateway will be installed.

![ttnv3-gwconfig](https://user-images.githubusercontent.com/49629370/224522671-602e8d99-a976-4767-a6a2-efc0f3e8b52e.png)

4. Select the **Frequency plan** for your region (with used by TTN), then click on the **Create gateway** button. This will add a new gateway to TTNv3.

![ttnv3-add](https://user-images.githubusercontent.com/49629370/224522677-b88c5a16-9be7-4a4d-8c36-32aa5136c4d1.png)

##### Register the Device on TTNv3

The next step is to follow the procedure described in the section [TTN OTAA Device Registration](#ttn-otaa-device-registration).

##### Uploading LoRaWAN Example to RAK3172

After a successful registration of the RAK3172 device on the LNS, you can now proceed with running the LoRaWAN OTAA demo application example.

1. Launch Arduino IDE and configure WisDuo RAK3172 Evaluation Board on board selection.

2. Connect the RAK3172 via UART and check RAK3172 COM Port.

3. Open the example code under **RAK WisBlock RUI examples**: **File** -> **Examples** -> **RAK WisBlock RUI examples** -> **Example** -> **LoRaWan_OTAA**.

![otaa-rak3172](https://user-images.githubusercontent.com/49629370/224522686-55cd5692-a755-47cd-9f46-097ff5fc2154.png)

4. In the example code, you need to modify the device EUI **OTAA_DEVEUI**, the application EUI **OTAA_APPEUI**, and the application key **OTAA_APPKEY**.

- The **OTAA_DEVEUI** parameter should match the device EUI registered in your network server. Note that your RAK3172 module has a sticker with a QR code printed on it. You can use the QR code information to configure the **OTAA_DEVEUI** parameter. The **OTAA_DEVEUI** format is MSB first.

```c
  // OTAA Device EUI MSB
#define OTAA_DEVEUI   {0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x04, 0xF1, 0xC0}
```
- The **OTAA_APPEUI** parameter. This parameter should also be the same as the **APPEUI** in the network server you configured.

```c
  // OTAA Application EUI MSB
#define OTAA_APPEUI   {0x70, 0xB3, 0xD5, 0x7E, 0xD0,0x03, 0xAB, 0xA2}
```

- Another important parameter to change is the application key **OTAA_APPKEY**. This parameter should also be the same as the **APPKEY** in the network server you configured. The **OTAA_APPKEY** format is MSB first.

```c
// OTAA Application Key MSB
#define OTAA_APPKEY   {0xB4, 0x85, 0x7E, 0xFE, 0x1C, 0xB5, 0x15, 0xEB, 0x44, 0x61, 0x0D, 0x9B, 0x20, 0x6A, 0xF3, 0x3A}
```

![lorawan_otaa_parameter](https://user-images.githubusercontent.com/49629370/224522694-c9c069bf-c3a9-4030-af6b-071d917ff565.png)

3. Depending on the Regional Band you selected, you might need to configure the sub-band of your RAK module to match the gateway and LoRaWAN network server. This is especially important for Regional Bands like US915, AU915, and CN470.

This guide uses US915 regional band, so you need to update the band in the code as well. In addition to that, you also need to set up the channel mask (channels 8 to 15 are the most commonly used channels in the US915 band).

```c
  if (!api.lorawan.band.set(OTAA_BAND)) {
    Serial.printf("LoRaWan OTAA - set band is incorrect! \r\n");
    return;
  }
  uint16_t maskBuff = 0x0002;
  if (!api.lorawan.mask.set(&maskBuff)) {
    Serial.printf("LoRaWan OTAA - set mask is incorrect! \r\n");
    return;
  }

```

:::tip 📝 NOTE:
RAK3172 supports the following regions:

* RAK_REGION_EU433 = 0
* RAK_REGION_CN470 = 1
* RAK_REGION_RU864 = 2
* RAK_REGION_IN865 = 3
* RAK_REGION_EU868 = 4
* RAK_REGION_US915 = 5
* RAK_REGION_AU915 = 6
* RAK_REGION_KR920 = 7
* RAK_REGION_AS923 = 8
* RAK_REGION_AS923-2 = 9
* RAK_REGION_AS923-3 = 10
* RAK_REGION_AS923-4 = 11
:::

![otaa-band](https://user-images.githubusercontent.com/49629370/224522713-bee3c241-aac0-4a87-a305-2df3b9ec5faa.png)


:::tip 📝 NOTE:

- Make sure you have configured the correct RAK board before uploading the code. See [Configure RAK3172 on Boards Manager](#configure-rak3172-on-boards-manager) section.

- Also, check [RAK3172 COM Port on Device Manager](#rak3172-com-port-on-device-manager) section.

:::

4. Open the **Tools** Menu and select a COM port. **COM28** is currently used.
![select-port](https://user-images.githubusercontent.com/49629370/224522719-e3b13b50-e84d-4d48-9710-83a4e0893356.png)

5. The last step is to upload the code by clicking the **Upload** icon on Arduino IDE. Take note that you should select the right board and COM port.
![otaa-upload](https://user-images.githubusercontent.com/49629370/224522725-7bd9acd6-efb5-4b5c-a8f9-21b88db19ba1.png)

6. You should now be able to see the console logs using the serial monitor of Arduino IDE. Sometimes COM port will be disconnected, so you won't be able to see the terminal output immediately. You can reconnect the module or try to push the reset button to see the terminal output.

![serial-console](https://user-images.githubusercontent.com/49629370/224522736-16703c2e-8764-4117-8bab-1e05e0a0fac8.png)

7. Check on the LoRaWAN network TTN console logs if your device has been successfully joined with the `join-request` and `join-accept` messages.

![ttn-log](https://user-images.githubusercontent.com/49629370/224522740-a3101151-ad78-406d-9213-debf502d70d2.png)

The modified `LoRaWAN_OTAA` project is available below.

```c

#define OTAA_PERIOD   (20000)
/*************************************

   LoRaWAN band setting:
     RAK_REGION_EU433
     RAK_REGION_CN470
     RAK_REGION_RU864
     RAK_REGION_IN865
     RAK_REGION_EU868
     RAK_REGION_US915
     RAK_REGION_AU915
     RAK_REGION_KR920
     RAK_REGION_AS923

 *************************************/
#define OTAA_BAND     (RAK_REGION_US915)
#define OTAA_DEVEUI   {0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x04, 0xF1, 0xC0}
#define OTAA_APPEUI   {0x70, 0xB3, 0xD5, 0x7E, 0xD0,0x03, 0xAB, 0xA2}
#define OTAA_APPKEY   {0xB4, 0x85, 0x7E, 0xFE, 0x1C, 0xB5, 0x15, 0xEB, 0x44, 0x61, 0x0D, 0x9B, 0x20, 0x6A, 0xF3, 0x3A}


/** Packet buffer for sending */
uint8_t collected_data[64] = { 0 };

void recvCallback(SERVICE_LORA_RECEIVE_T * data)
{
  if (data->BufferSize > 0) {
    Serial.println("Something received!");
    for (int i = 0; i < data->BufferSize; i++) {
      Serial.printf("%x", data->Buffer[i]);
    }
    Serial.print("\r\n");
  }
}

void joinCallback(int32_t status)
{
  Serial.printf("Join status: %d\r\n", status);
}

void sendCallback(int32_t status)
{
  if (status == 0) {
    Serial.println("Successfully sent");
  } else {
    Serial.println("Sending failed");
  }
}

void setup()
{
  Serial.begin(115200, RAK_AT_MODE);

  Serial.println("RAKwireless LoRaWan OTAA Example");
  Serial.println("------------------------------------------------------");

  // OTAA Device EUI MSB first
  uint8_t node_device_eui[8] = OTAA_DEVEUI;
  // OTAA Application EUI MSB first
  uint8_t node_app_eui[8] = OTAA_APPEUI;
  // OTAA Application Key MSB first
  uint8_t node_app_key[16] = OTAA_APPKEY;

  if (!api.lorawan.appeui.set(node_app_eui, 8)) {
    Serial.printf("LoRaWan OTAA - set application EUI is incorrect! \r\n");
    return;
  }
  if (!api.lorawan.appkey.set(node_app_key, 16)) {
    Serial.printf("LoRaWan OTAA - set application key is incorrect! \r\n");
    return;
  }
  if (!api.lorawan.deui.set(node_device_eui, 8)) {
    Serial.printf("LoRaWan OTAA - set device EUI is incorrect! \r\n");
    return;
  }

  if (!api.lorawan.band.set(OTAA_BAND)) {
    Serial.printf("LoRaWan OTAA - set band is incorrect! \r\n");
    return;
  }
  uint16_t maskBuff = 0x0002;
  if (!api.lorawan.mask.set(&maskBuff)) {
    Serial.printf("LoRaWan OTAA - set mask is incorrect! \r\n");
    return;
  }


  if (!api.lorawan.deviceClass.set(RAK_LORA_CLASS_A)) {
    Serial.printf("LoRaWan OTAA - set device class is incorrect! \r\n");
    return;
  }
  if (!api.lorawan.njm.set(RAK_LORA_OTAA))	// Set the network join mode to OTAA
  {
    Serial.printf
	("LoRaWan OTAA - set network join mode is incorrect! \r\n");
    return;
  }
  if (!api.lorawan.join())	// Join to Gateway
  {
    Serial.printf("LoRaWan OTAA - join fail! \r\n");
    return;
  }

  /** Wait for Join success */
  while (api.lorawan.njs.get() == 0) {
    Serial.print("Wait for LoRaWAN join...");
    api.lorawan.join();
    delay(10000);
  }

  if (!api.lorawan.adr.set(true)) {
    Serial.printf
	("LoRaWan OTAA - set adaptive data rate is incorrect! \r\n");
    return;
  }
  if (!api.lorawan.rety.set(1)) {
    Serial.printf("LoRaWan OTAA - set retry times is incorrect! \r\n");
    return;
  }
  if (!api.lorawan.cfm.set(1)) {
    Serial.printf("LoRaWan OTAA - set confirm mode is incorrect! \r\n");
    return;
  }

  /** Check LoRaWan Status*/
  Serial.printf("Duty cycle is %s\r\n", api.lorawan.dcs.get()? "ON" : "OFF");	// Check Duty Cycle status
  Serial.printf("Packet is %s\r\n", api.lorawan.cfm.get()? "CONFIRMED" : "UNCONFIRMED");	// Check Confirm status
  uint8_t assigned_dev_addr[4] = { 0 };
  api.lorawan.daddr.get(assigned_dev_addr, 4);
  Serial.printf("Device Address is %02X%02X%02X%02X\r\n", assigned_dev_addr[0], assigned_dev_addr[1], assigned_dev_addr[2], assigned_dev_addr[3]);	// Check Device Address
  Serial.printf("Uplink period is %ums\r\n", OTAA_PERIOD);
  Serial.println("");
  api.lorawan.registerRecvCallback(recvCallback);
  api.lorawan.registerJoinCallback(joinCallback);
  api.lorawan.registerSendCallback(sendCallback);
}

void uplink_routine()
{
  /** Payload of Uplink */
  uint8_t data_len = 0;
  collected_data[data_len++] = (uint8_t) 't';
  collected_data[data_len++] = (uint8_t) 'e';
  collected_data[data_len++] = (uint8_t) 's';
  collected_data[data_len++] = (uint8_t) 't';

  Serial.println("Data Packet:");
  for (int i = 0; i < data_len; i++) {
    Serial.printf("0x%02X ", collected_data[i]);
  }
  Serial.println("");

  /** Send the data package */
  if (api.lorawan.send(data_len, (uint8_t *) & collected_data, 2, true, 1)) {
    Serial.println("Sending is requested");
  } else {
    Serial.println("Sending failed");
  }
}

void loop()
{
  static uint64_t last = 0;
  static uint64_t elapsed;

  if ((elapsed = millis() - last) > OTAA_PERIOD) {
    uplink_routine();

    last = millis();
  }
  //Serial.printf("Try sleep %ums..", OTAA_PERIOD);
  api.system.sleep.all(OTAA_PERIOD);
  //Serial.println("Wakeup..");
}

```
### Arduino Installation

Refer to [Software section](#Software).
