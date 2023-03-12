# RAK3172_Canopus Module Quick Start Guide

#### Information RAK3172_Canopus board

- Schematic
- Layout
- Bom list and CPL

#### Software

- Download and install the [Arduino IDE](https://www.arduino.cc/en/Main/Software).

:::warning ⚠️ WARNING
_**If you are using Windows 10**_.
Do _**NOT**_ install the Arduino IDE from the Microsoft App Store. Instead, install the original Arduino IDE from the Arduino official website. The Arduino app from the Microsoft App Store has problems using third-party Board Support Packages.
:::

- Add RAK3172_Canopus as a supported board in Arduino IDE by updating Board Manager URLs in **Preferences** settings of Arduino IDE with the JSON URL below.
```json
https://raw.githubusercontent.com/RAKWireless/RAKwireless-Arduino-BSP-Index/main/package_rakwireless.com_rui_index.json
```
After that, you can then add **RAKwireless RUI STM32 Boards** via Arduino board manager.

#### Hardware Setup

The RAK3172_Canopus requires a few hardware connections before you can make it work. The bare minimum requirement is to have the power section properly configured,  antenna, and USB type C.

#### Software Setup

The default firmware of RAK3172_Canopus is based on RUI3, which allows you to develop your own custom firmware to connect sensors and other peripherals to it. To develop using your custom firmware using the Arduino IDE, you need to first add RAKwireless RUI STM32 boards to the Arduino board manager, which will be discussed in this guide. You can then use [RUI3 APIs] (https://docs.rakwireless.com/RUI3/Arduino-API/) for your intended application.

##### RAK3172_Canopus board Support Package in Arduino IDE

If you don't have an Arduino IDE yet, you can download it on the [Arduino official website](https://www.arduino.cc/en/Main/Software) and follow the installation procedure in the [miscellaneous section](/Product-Categories/wisduo/RAK3172-Module/Quickstart/#arduino-installation) of this document.

::: tip 📝 NOTE
**For Windows 10 and up users**:
If your Arduino IDE is installed from the Microsoft App Store, you need to reinstall your Arduino IDE by getting it from the Arduino official website. The Arduino app from the Microsoft App Store has problems using third-party Board Support Packages.
:::

Once the Arduino IDE has been successfully installed, you can now configure the IDE to add the RAK3172_Canopus to its board selection by following these steps.

1. Open Arduino IDE and go to **File** > **Preferences**.

![preferences](https://user-images.githubusercontent.com/49629370/224521061-7ff3624f-7f93-479d-98b3-5c6e0dc08208.png)

2. To add the RAK3172_Canopus to your Arduino Boards list, edit the **Additional Board Manager URLs**.

![additional-boards](https://user-images.githubusercontent.com/49629370/224521079-1eee507e-22ed-4f4e-b52d-965619bf090e.png)

3. Copy the URL below and paste it on the field. If there are other URLs already there, just add them on the next line. After adding the URL, click **OK**.

```json
https://raw.githubusercontent.com/RAKWireless/RAKwireless-Arduino-BSP-Index/main/package_rakwireless.com_rui_index.json
```

![preferences-url](https://user-images.githubusercontent.com/49629370/224521108-5f18b3a2-7775-48fd-b8c5-f71ffb2e427c.png)

4. Restart the Arduino IDE.

5. Open the Boards Manager from the Tools Menu.

![boards-manager](https://user-images.githubusercontent.com/49629370/224521119-0c5ceeaf-b944-413b-9f04-d7f7e5b9ca50.png)

6. Write `RAK` in the search bar. This will show the available RAKwireless module boards that you can add to your Arduino Board list.

7. Click on the area highlighted in blue to select **RAKwireless RUI STM32 Boards**. Install the latest version of the  **RAKwireless RUI STM32 Boards** by clicking on **Install** button.

![rui3-stm32](https://user-images.githubusercontent.com/49629370/224521130-6419c6b9-d8fc-41d8-ac7e-e9a03db0fd59.png)

##### Configure RAK3172_Canopus on Boards Manager

8. Once the BSP is installed, select  **Tools** > **Boards Manager** > **RAKWireless RUI STM32 Modules** > **WisDuo RAK3172 Evaluation Board**. The RAK3172 Evaluation board uses the RAK3172 WisDuo module.

![rui-stm32](https://user-images.githubusercontent.com/49629370/224521144-d1ec1a5f-5c67-46f1-8f99-5da1b4b57a23.png)

##### RAK3172 COM Port on Device Manager

Connect the RAK3172 via USB type C and check COM Port using Windows **Device Manager**. Double-click the reset button if the module is not detected.

![rui-port](https://user-images.githubusercontent.com/49629370/224521157-ca08067c-cce1-434d-bd27-10ac67277c7b.png)

##### Compile an Example with Arduino LED Breathing

1. After completing the steps on adding your RAK3172_Canopus to the Arduino IDE, you can now try to run a simple program to test your setup. You need to add two LEDs to the bare minimum schematic of the RAK3172 module.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/rak3172_bare_minimum_schematic_led.png"
  width="90%"
  caption="RAK3172 with two LEDs"
/>

2. Launch Arduino IDE and configure WisDuo RAK3172 Evaluation Board on board selection.

3. Connect the RAK3172_Canopus via USB type C.

4. Open the **Tools** Menu and select a COM port. **COM28** is currently used.
![select-port](https://user-images.githubusercontent.com/49629370/224521257-10db6f5c-5e77-4e4c-b020-58a330de9ba4.png)

5. You can see the serial monitor icon and click it to connect the COM port.
![serial-mon](https://user-images.githubusercontent.com/49629370/224521270-9a2f7282-18f3-4334-a568-788f2e5a7bf0.png)

6. Open **Arduino_Led_Breathing** example code.

![led-example](https://user-images.githubusercontent.com/49629370/224521281-3bb48679-7d97-43c2-a011-3373e572af73.png)

7. Click on the **Verify** icon to check if you have successfully compiled the example code.

![verify-code](https://user-images.githubusercontent.com/49629370/224521295-0991bbb8-ab1a-44a7-b6fd-228f8f26dc27.png)

8. Click the **Upload** icon to send the compiled firmware to your RAK3172 module.

:::tip 📝 NOTE:
RAK3172_Canopus should automatically go to BOOT mode when the firmware is uploaded via Arduino IDE.

If BOOT mode is not initiated, pull to ground the RESET pin twice (or double click the reset button if available) to force BOOT mode.
:::

![upload-code](https://user-images.githubusercontent.com/49629370/224521302-282b1a09-dc2c-43ae-a24a-9be1c7050a3d.png)

9. If the upload is successful, you will see the **Upgrade Complete** message.

![dev-prog](https://user-images.githubusercontent.com/49629370/224521311-344542b3-d8ec-4008-a721-58e47bf241ce.png)

10. After the Device Programmed is completed, you will see that LEDs are blinking.

##### RAK3172 I/O Pins and Peripherals

This section discusses how to use and access RAK3172 pins using the RUI3 API. It shows basic code on using digital I/O, analog input, UART, and I2C.

![rak3172-pins](https://user-images.githubusercontent.com/49629370/224521329-eb63e943-dd5c-4a59-9920-9f6aa959f3dc.png)

###### How to Use Digital I/O

You can use any of the pins below as Digital Pin.


| **Pin Name** | **Alternative Pin Usage** |
| ------------ | ------------------------- |
| PA0          |                           |
| PA1          |                           |
| PA4          | SPI                       |
| PA5          | SPI                       |
| PA6          | SPI                       |
| PA7          | SPI                       |
| PA8          | LED_YELLOW                |
| PA9          | I2C_SCL                   |
| PA10         | I2C_SDA                   |
| PA15         |                           |
| PB2          |                           |
| PB3          | ADC1                      |
| PB4          | ADC2                      |
| PB5          |                           |
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


**Example code**

```c
void setup()
{
  pinMode(PA0, OUTPUT); //Change the P0_04 to any digital pin you want. Also, you can set this to INPUT or OUTPUT
}

void loop()
{
  digitalWrite(PA0,HIGH); //Change the PA0 to any digital pin you want. Also, you can set this to HIGH or LOW state.
  delay(1000); // delay for 1 second
  digitalWrite(PA0,LOW); //Change the PA0 to any digital pin you want. Also, you can set this to HIGH or LOW state.
  delay(1000); // delay for 1 second
}
```

###### How to Use Analog Input

You can use any of the pins below as Analog Input.

| **Analog Port** | **Pin Name** |
| --------------- | ------------ |
| ADC1            | PB3          |
| ADC2            | PB4          |


Use Arduino [analogRead](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/) to read the value from the specified Analog Input pin.

![rak3172-adc-pins](https://user-images.githubusercontent.com/49629370/224522583-21ff739b-7f3b-4a7d-9697-72e8b69e8c4a.png)


**Example code**

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

###### How to Use Serial Interfaces

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

**I2C**

There is one I2C peripheral available on RAK3172.

| **I2C Pin Number** | **I2C Pin Name** |
| ------------------ | ---------------- |
| PA9                | I2C_SCL          |
| PA10               | I2C_SDA          |


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

##### LoRaWAN Example

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

###### Register the LoRaWAN Gateway on TTNv3 Community Edition

After configuring your gateway, you need to register it in TTNv3:

1. Log in to the TTNv3 Network Server with a web browser.

- [Europe](https://eu1.cloud.thethings.network/)
- [North America](https://nam1.cloud.thethings.network/)
- [Australia](https://au1.cloud.thethings.network/)

2. Navigate to the **Console** page and click on **gateway** icon, as shown in **Figure 25**.

![ttnv3-initial](https://user-images.githubusercontent.com/49629370/224522665-860970ca-7272-4955-9953-532928a196cd.png)

3. On **General Settings**, enter the **Gateway ID**, **Gateway EUI**, and **Gateway Name**. This information is available in your LoRaWAN gateway configuration. Select the **Gateway Server address** according to the region where the LoRaWAN gateway will be installed.

![ttnv3-gwconfig](https://user-images.githubusercontent.com/49629370/224522671-602e8d99-a976-4767-a6a2-efc0f3e8b52e.png)

4. Select the **Frequency plan** for your region (with used by TTN), then click on the **Create gateway** button. This will add a new gateway to TTNv3.

![ttnv3-add](https://user-images.githubusercontent.com/49629370/224522677-b88c5a16-9be7-4a4d-8c36-32aa5136c4d1.png)

###### Register the Device on TTNv3

The next step is to follow the procedure described in the section [TTN OTAA Device Registration](#ttn-otaa-device-registration).

###### Uploading LoRaWAN Example to RAK3172

After a successful registration of the RAK3172 device on the LNS, you can now proceed with running the LoRaWAN OTAA demo application example.

1. Launch Arduino IDE and configure WisDuo RAK3172 Evaluation Board on board selection. See [**Figure 9**](#configure-rak3172-on-boards-manager).

2. Connect the RAK3172 via UART and check RAK3172 COM Port. See [**Figure 10**](#rak3172-com-port-on-device-manager).

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

### RAK3172 as a LoRa/LoRaWAN Modem via AT Command

#### AT Command via UART2

RAK3172 module can be configured using AT commands via the UART2 interface. You need a USB to UART TTL adapter to connect the RAK3172 to your computer's USB port and a serial terminal tool. You can use the [RAK Serial Port Tool](https://downloads.rakwireless.com/en/LoRa/Tools) so you can easily send AT commands and view the replies from the console output. The RAK Serial Port Tool commands still uses the RUI V2 AT commands by default. You can modify it to have RUI3 AT commands and then save it.

:::warning ⚠️ WARNING
Firmware update and AT command functionality are done via UART2 pins. If you will connect the module to an external host MCU that will send AT commands via UART2, take extra precautions in your board design to ensure you can still perform FW update to it. There should be a way in your board design that can disconnect the host MCU UART to connect to RAK3172 UART2 before connecting the module to the PC (via USB-UART converter) for the FW update process.

An alternative option to update firmware aside from UART2 is to use SWD pins (SWCLK & SWDIO). This method will require you to use external tools like ST-LINK and RAKDAP1.
:::

##### Connect to the RAK3172

1. Connect the RAK3172 to the serial port of a general-purpose computer (USB port) using a USB to UART TTL adapter like [RAKDAP1](https://store.rakwireless.com/collections/accessories/products/daplink-tool), as shown in **Figure 35**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_UART_Connection.svg"
  width="55%"
  caption="RAK3172 Module Connection"
/>

2. Any serial communication tool can be used; but, it is recommended to use the [RAK Serial Port Tool](https://downloads.rakwireless.com/en/LoRa/Tools).

3. Configure the serial communication tool by selecting the proper port detected by the computer and configure the link as follows:

 * Baud Rate: **115200&nbsp;baud**
 * Data Bits: **8&nbsp;bits**
 * Stop Bits: **1&nbsp;stop bit**
 * Parity: **NONE**

##### RAK3172 Configuration for LoRaWAN or LoRa P2P

To enable the RAK3172 module as a LoRa P2P module or a LoRaWAN end-device, the module must be configured and parameters must be set by sending AT commands. You can configure the RAK3172 in two ways:

- [LoRaWAN End-Device](/Product-Categories/WisDuo/RAK3172-Module/quickstart/#configuring-rak3172-as-lorawan-end-device) - RAK3172 as LoRaWAN IoT device.
- [LoRa P2P](/Product-Categories/WisDuo/RAK3172-Module/quickstart/#lora-p2p-mode) - Point-to-point communication between two RAK3172 modules.

#### Configuring RAK3172 as LoRaWAN End-Device

To enable the RAK3172 module as a LoRaWAN end-device, a device must be registered first in the LoRaWAN network server. This guide will cover both TTN and Chirpstack LoRaWAN network servers and the associated AT commands for the RAK3172.

This guide covers the following topics:

- [TheThingsNetwork Guide](#connecting-to-the-things-network-ttn) - How to log in, register new accounts and create new applications on TTN.
- [RAK3172 TTN OTAA Guide](#ttn-otaa-device-registration) - How to add OTAA device on TTN and what AT commands to use on RAK3172 OTAA activation.
- [RAK3172 TTN ABP Guide](#ttn-abp-device-registration) - How to add ABP device on TTN and what AT commands to use on RAK3172 ABP activation.
- [Chirpstack Guide](#connecting-with-chirpstack) - How to create new applications on Chirpstack.
- [RAK3172 Chirpstack OTAA Guide](#chirpstack-otaa-device-registration) - How to add OTAA device to Chirpstack and what AT commands to use on RAK3172 OTAA activation.
- [RAK3172 Chirpstack ABP Guide](#chirpstack-abp-device-registration) - How to add ABP device on Chirpstack and what AT commands to use on RAK3172 ABP activation.

##### Connecting to The Things Network (TTN)

In this section, a quick tutorial guide will show how to connect the RAK3172 module to the TTN platform.

:::tip 📝 NOTE:

In this guide, you need to have a working gateway that is connected to TTN or you have to be within the coverage of a TTN community network.

:::

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/4.ttn-context.png"
  width="95%"
  caption="RAK3172 EVB in the context of the TTN"
/>

As shown in **Figure 36**, The Things Stack (TTN V3) is an open-source LoRaWAN Network Server suitable for global, geo-distributed public and private deployments, as well as for small local networks. The architecture follows the LoRaWAN Network Reference Model for standards compliance and interoperability. This project is actively maintained by [The Things Industries](https://www.thethingsindustries.com/).

LoRaWAN is a protocol for low-power wide-area networks. It allows for large-scale Internet of Things deployments where low-powered devices efficiently communicate with Internet-connected applications over long-range wireless connections.

The RAK3172 WisDuo module can be part of this ecosystem as a device, and the objective of this section is to demonstrate how simple it is to send data to The Things Stack using the LoRaWAN protocol. To achieve this, the RAK3172 WisDuo module must be located inside the coverage of a LoRaWAN gateway connected to The Things Stack server.

##### Registration to TTN and Creating LoRaWAN Applications

1. The first step is to go to [The Things Network](https://www.thethingsnetwork.org/) and sign up an account shown in **Figure 37**. Then select a cluster as shown in **Figure 39**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_1.png"
  width="100%"
  caption="Signing up an account in TTN"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_2.png"
  width="100%"
  caption="Signing up an account in TTN"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_3.png"
  width="100%"
  caption="Selecting Cluster in TTN"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_4.png"
  width="100%"
  caption="Signing up through the Things ID"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_5.png"
  width="100%"
  caption="Creation of an account through the Things ID"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_6.png"
  width="100%"
  caption="Creation of an account through the Things ID"
/>

 You can use the same login credentials on the TTN V2 if you have one. If you have no account yet, you need to create one.

2. Now that you are logged in to the platform, the next step is to create an application. Click **Create an application**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_7X.png"
  width="100%"
  caption="The Things Stack Platform"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_8X.png"
  width="100%"
  caption="Creating TTN application for your LoRaWAN devices"
/>

3. To have an application registered, input first the specific details and necessary information about your application then click **Create application**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_7.png"
  width="100%"
  caption="Details of the TTN application"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_8.png"
  width="80%"
  caption="Details of the TTN application"
/>

4. If you have no error on the previous step, you should now be on the application console page. The next step is to add end-devices to your TTN application.

LoRaWAN specifications enforce that each end-device has to be personalized and activated. There are two options in registering devices depending on the activation mode selected. Activation can be done either via Over-The-Air-Activation (OTAA) or Activation-By-Personalization (ABP).

##### TTN OTAA Device Registration

1. Go to your application console to register a device. To start adding an OTAA end-device, click **+ Register end device**, as shown in **Figure 47**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_9.png"
  width="100%"
  caption="Register end device"
/>

2. To register the board, click the **Enter end device specifics manually**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_10.png"
  width="100%"
  caption="Enter end device specifics manually"
/>

3. Next step is to set up **Frequency plan**, compatible **LoRaWAN version**, and **Regional Parameters version** supported. Then provide the **JoinEUI** credentials by entering zeroes into it.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_11.png"
  width="80%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_12.png"
  width="80%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_13.png"
  width="90%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_14.png"
  width="90%"
  caption="Setting up for your device"
/>

4. Then click **Show advanced activation, LoRaWAN class and cluster settings**. Configure the activation mode by selecting **Over the air activation (OTAA)** and Additional LoRaWAN class capabilities to **class A only**. Then click **Confirm**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_15.png"
  width="90%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_16.png"
  width="90%"
  caption="Setting up for your device"
/>

5. Once done, provide the DevEUI credentials of your device into the **DevEUI** portion. This will automatically generate the specific end-device ID of your board. Click **Generate** in **AppKey** tab under **Provisioning information** section. Then click **Register end device**.

:::tip 📝 NOTE:

- The **AppEUI**, **DevEUI**, and **AppKey** are hidden in this section as these are unique from a specific device. The **DevEUI** credential is unique to every RAK3172 device. Also, you should generate your own **AppEUI** and **AppKey** credentials for your specific device and application.

- The **AppEUI** is the same as **JoinEUI**.

:::

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_17B.png"
  width="80%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_18B.png"
  width="80%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_19A.png"
  width="90%"
  caption="Register end device"
/>

6. You should now be able to see the device on the TTN console after you fully register your device, as shown in **Figure 58**.

:::tip 📝 NOTE:

- The **AppEUI**, **DevEUI**, and **AppKey** are the parameters that you will need to activate your LoRaWAN end-device via OTAA. The **AppKey** is hidden by default for security reasons, but you can easily show it by clicking the show button. You can also copy the parameters quickly using the copy button.

- The three OTAA parameters on the TTN device console are MSB by default.

- These parameters are always accessible on the device console page, as shown in **Figure 58**.
:::

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/RAK3172_New_20A.png"
  width="100%"
  caption="OTAA device successfully registered to TTN"
/>

##### OTAA Configuration for TTN

The RAK3172 module can be configured using WisToolBox to do the OTAA configuration. **WisToolBox** is a software tool that supports **RAK3172** module. It automatically detects the RAK3172 module once it is connected to the PC. Below are the options in WisToolBox where the OTAA configuration can be done.

- [OTAA Configuration for TTN via WisToolBox UI](#otaa-configuration-for-ttn-via-wistoolbox-ui)
- [OTAA Configuration for TTN via WisToolBox Console](#otaa-configuration-for-ttn-via-wistoolbox-console)

##### OTAA Configuration for TTN via WisToolBox UI

The **RAK3172** should have the correct OTAA credentials to connect to TTN. This can be done using **WisToolBox UI**. Below are the steps on setting up your **RAK3172** using **WisToolBox**.

1. Connect your **RAK3172** with your chosen WisBlock base board to the PC via USB cable and open the **WisToolBox** application.

2. Click **CONNECT DEVICE** button to launch the WisToolBox Dashboard.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_1.png"
  width="90%"
  caption="CONNECT DEVICE"
/>

3. Then select your target port where your **RAK3172** is connected. Once recognized, click **CONNECT**, as shown in **Figure 60**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_2.png"
  width="90%"
  caption="Setting up your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_3.png"
  width="90%"
  caption="Setting up your device"
/>

4. Once done, **RAK3172** will appear in the dashboard then select it.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_4A.png"
  width="90%"
  caption="Device seen from WisToolBox dashboard"
/>

5. Then click **PARAMETERS** configure your RAK3172.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_5.png"
  width="90%"
  caption="Setting up your device"
/>

6. Click **Global settings** to set the network mode to **LoRaWAN** and join mode to **OTAA**. Make sure that the active region is using **EU868** for this configuration. If you wish to work on other regional bands, you can choose among active regions based on your location.

- LoRa network mode: **LoRaWAN**
- LoRaWAN join mode: **OTAA**
- LoRaWAN region: **EU868**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_6.png"
  width="90%"
  caption="Global settings"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_7A.png"
  width="90%"
  caption="Global settings"
/>

7. Click **LoRaWAN keys, ID, EUI** to configure the **Application EUI (AppEUI)**, **Application key (AppKey)**, and **Device EUI (DevEUI)**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_7B.png"
  width="90%"
  caption="LoRaWAN keys, ID, EUI"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_8B.png"
  width="90%"
  caption="Setting up your device"
/>

8. Then go back to the console where your RAK3172 end-device is created previously. Copy the credentials from there since it will be used in the WisToolBox dashboard. Once encoded into the dashboard, click **APPLY COMMAND** to update your device, as shown in **Figure 75**.

:::tip 📝 NOTE:

- The **AppEUI**, **DevEUI**, and **AppKey** are hidden in this section as these are unique from a specific device.

:::

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_9.png"
  width="100%"
  caption="Your created OTAA device from your console"
/>

- **For Application EUI (AppEUI)**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_9A.png"
  width="100%"
  caption="Copying the AppEUI credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_10A.png"
  width="90%"
  caption="Copying the AppEUI credential from TTN to WisToolBox"
/>

- **For Application key (AppKey)**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_9B.png"
  width="100%"
  caption="Copying the AppKey credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_10B.png"
  width="90%"
  caption="Copying the AppKey credential from TTN to WisToolBox"
/>

- **For Device EUI (DevEUI)**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_9C.png"
  width="100%"
  caption="Copying the DevEUI credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_10C.png"
  width="90%"
  caption="Copying the DevEUI credential from TTN to WisToolBox"
/>

- **WisToolBox Dashboard**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_10.png"
  width="90%"
  caption="Used credentials from your console in WisToolBox dashboard"
/>

9. Once done, you will see the summary of commands that is applied to your device. Then click **CLOSE**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_11.png"
  width="90%"
  caption="Summary of commands"
/>

10. Now, you will see it return to the dashboard with updated credentials of your device.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_12.png"
  width="90%"
  caption="Successfully configured OTAA device via WisToolBox dashboard"
/>

11. After your device's credentials are updated, it can now join the network. To do this, you need to go to **Data on LoRa network** under **PARAMETERS**, and then click **JOIN NETWORK** under **LoRaWAN join settings**. After a few seconds, it will notify you that your OTAA device has already joined the TTN server. You can also access your TTN console if your device has successfully joined the TTN.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_13.png"
  width="90%"
  caption="Joining mode of your OTAA device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_14.png"
  width="90%"
  caption="OTAA device successfully joined the TTN server"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/Wis_RAK3172_New_15.png"
  width="90%"
  caption="OTAA device successfully joined the TTN server"
/>

##### OTAA Configuration for TTN via WisToolBox Console

Here's another way of OTAA configuration using **WisToolBox Console**. Below are the steps on setting up your **RAK3172** using **WisToolBox Console**.

1. Connect your **RAK3172** with your chosen WisBlock base board to the PC via USB cable and open the **WisToolBox** application.

2. Click **CONNECT DEVICE** button to launch the WisToolBox Dashboard.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_1.png"
  width="90%"
  caption="CONNECT DEVICE"
/>

3. Select your target port where your **RAK3172** is connected. Once recognized, click **CONNECT**, as shown in **Figure 83**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_2.png"
  width="90%"
  caption="Setting up your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_3.png"
  width="90%"
  caption="Setting up your device"
/>

4. Once done, **RAK3172** will appear in the dashboard, then select it.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_4.png"
  width="90%"
  caption="Device seen from WisToolBox dashboard"
/>

5. Then click **ADVANCED**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_5.png"
  width="90%"
  caption="Setting up your device"
/>

6. Once done, click **OPEN CONSOLE** to do the configuration.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_6.png"
  width="90%"
  caption="OPEN CONSOLE"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_7.png"
  width="90%"
  caption="Opening the Console terminal of WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_8.png"
  width="90%"
  caption="Opening the Console terminal of WisToolBox"
/>

7. To start the configuration, type `ATE` so you can echo the commands you input during your configuration. Then press **Enter**.

It is recommended to start by testing the console and verify that the current configuration is working by sending these two AT commands:

```
AT
```

```
ATE
```

`ATE` is useful for tracking the commands and troubleshooting.

You will receive `OK` when you input the two commands. After setting `ATE`, you can now see all the commands you input together with the replies.

:::tip 📝 NOTE:

If there is no `OK` or any reply, check if the device is powered correctly. If you are getting power from a USB port, ensure that you have a good USB cable.

:::

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_9A.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_9B.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_9C.png"
  width="90%"
  caption="Setting up your Console"
/>

8. Then configure the LoRaWAN join mode to **OTAA**. You can check what parameter you will input by typing **AT+NJM?** and then **Enter** into the console terminal. For **OTAA**, you should input **AT+NJM=1** and then press **Enter**, as shown in **Figure 92**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_10.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_11.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_12.png"
  width="90%"
  caption="Setting up your Console"
/>

9. Once done, set your LoRaWAN region to EU868. You can check what parameter you will input by typing `AT+BAND?` then **Enter** into the console terminal. For **EU868**, you should input **AT+BAND=4** then press **Enter**. If you wish to work on other regional bands, you may check the list of band parameter options below.

Set the frequency/region to EU868.

```
AT+BAND=4
```

:::tip 📝 NOTE:

Depending on the Regional Band you selected, you might need to configure the sub-band of your RAK3172 to match the gateway and LoRaWAN network server. This is especially important for regional bands like US915, AU915, and CN470.

To configure the masking of channels for the sub-bands, you can use the `AT+MASK` command that can be found on the [AT Command Manual](https://docs.rakwireless.com/Product-Categories/WisDuo/RAK3172-Module/AT-Command-Manual/#at-mask).

To illustrate, you can use sub-band 2 by sending the command `AT+MASK=0002`.
:::

**List of band parameter options**

| Code | Regional Band |
| ---- | ------------- |
| 0    | EU433         |
| 1    | CN470         |
| 2    | RU864         |
| 3    | IN865         |
| 4    | EU868         |
| 5    | US915         |
| 6    | AU915         |
| 7    | KR920         |
| 8    | AS923-1       |
| 9    | AS923-2       |
| 10   | AS923-3       |
| 11   | AS923-4       |


<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_13.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_14.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_15.png"
  width="90%"
  caption="Setting up your Console"
/>

10. Then next to this will be updating the OTAA credentials of your device. First on this list will be the **Application EUI (AppEUI)**. Go back to your console where your RAK3172 End device was created to copy the AppEUI credential, then paste it to the WisToolBox Console and press **Enter**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_W.png"
  width="90%"
  caption="Your created OTAA device from your TTN console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_16.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_17.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_18.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_X.png"
  width="90%"
  caption="Copying the AppEUI credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_19.png"
  width="90%"
  caption="Setting up your Console"
/>

11. Once done, do the same procedure to **Application key (AppKey)** and **Device EUI (DevEUI)**.

- **For Application key (AppKey)**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_20.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_21.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_22.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_Y.png"
  width="90%"
  caption="Copying the AppKey credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_23.png"
  width="90%"
  caption="Setting up your Console"
/>

- **For Device EUI (DevEUI)**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_24.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_25.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_Z.png"
  width="90%"
  caption="Copying the DevEUI credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_26.png"
  width="90%"
  caption="Setting up your Console"
/>

12. Once done, click **Dashboard** to check the updated credentials of your OTAA device. Click **PARAMETERS** to open the **Global Settings** and **LoRaWAN keys, ID, EUI**, and check whether these portions are updated.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_27.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_28.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_29.png"
  width="90%"
  caption="PARAMETERS"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_30A.png"
  width="90%"
  caption="Global settings and LoRaWAN keys, ID, EUI"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_30B.png"
  width="90%"
  caption="Global settings and LoRaWAN keys, ID, EUI details"
/>

13. Now you have a configured OTAA device using WisToolBox Console. You can now join the network using the WisToolBox console.

14. To do this, you need to go back to the WisToolBox console and type **AT+JOIN**. Edit it to **AT+JOIN=1** and press **Enter** to join the network.

:::tip 📝 NOTE:
`AT+JOIN` command parameters are optional. You can configure the settings for auto-join, reattempt interval, and the number of join attempts if your application needs it. If not configured, it will use the default parameter values.

`AT+JOIN` and `AT+JOIN=1` also share the common functionality of trying to join the network.
:::

Join command format: **`AT+JOIN=w:x:y:z`**

| Parameter | Description                                                  |
| --------- | ------------------------------------------------------------ |
| w         | Join command - 1: joining, 0: stop joining.                  |
| x         | Auto-join config - 1: auto-join on power-up, 0: no auto-join |
| y         | Reattempt interval in seconds (7-255) - 8 is the default.    |
| z         | Number of join attempts (0-255) - 0 is default.              |

After 5 or 6 seconds, if the request is successfully received by a LoRa gateway, you should see `+EVT:JOINED` status reply, as shown in the figure below:

:::tip 📝 NOTE:

If the OTAA device failed to join, you need to check if your device is within reach of a working LoRaWAN gateway that is configured to connect to TTN. It is also important to check that all your OTAA parameters (DEVEUI, APPEUI, and APPKEY) are correct using the `AT+DEVEUI=?`, `AT+APPEUI=?`, and `AT+APPKEY=?` commands. Lastly, ensure that the antenna of your device is properly connected.

After checking all the things above, try to join again.
:::

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_34.png"
  width="90%"
  caption="Joining mode using WisToolBox Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_35.png"
  width="90%"
  caption="Joining mode using WisToolBox Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_36.png"
  width="90%"
  caption="Joining mode using WisToolBox Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_37.png"
  width="90%"
  caption="Joining mode using WisToolBox Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_38.png"
  width="90%"
  caption="OTAA device successfully joined the network"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_39A.png"
  width="90%"
  caption="OTAA device successfully joined the network"
/>

15. With the end-device properly joined to the TTN, you can now try to send some payload after a successful join. Send command format: **`AT+SEND=<port>:<payload>`**

```
AT+SEND=2:12345678
```

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_40.png"
  width="90%"
  caption="OTAA device sending payload to the network"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_41.png"
  width="90%"
  caption="OTAA device sending payload to the network"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_42.png"
  width="90%"
  caption="OTAA device sending payload to the network"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_43.png"
  width="90%"
  caption="OTAA device sending payload to the network"
/>

16. You can see the data sent by the RAK3172 module on the TTN device console *Live data* section. Also, the *Last seen* info should be a few seconds or minutes ago.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ConWis_RAK3172_New_44A.png"
  width="90%"
  caption="OTAA Test Sample Data Sent Viewed in TTN"
/>

##### TTN ABP Device Registration

1. To register an ABP device, go to your application console and select the application to which you want your device to be added. Then click **+ Register end device**, as shown in **Figure 129**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_1.png"
  width="100%"
  caption="Adding ABP Device"
/>

2. To register the board, click the **Enter end device specifics manually**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_2.png"
  width="100%"
  caption="Enter end device specifics manually"
/>

3. Next step is to set up **Frequency plan**, compatible **LoRaWAN version**, and **Regional Parameters version** supported.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_3.png"
  width="80%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_4.png"
  width="80%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_5.png"
  width="90%"
  caption="Setting up for your device"
/>

4. Then click **Show advanced activation, LoRaWAN class and cluster settings**. Configure the activation mode by selecting **Activation by personalization (ABP)** and Additional LoRaWAN class capabilities to **class A only**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_6.png"
  width="90%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_7.png"
  width="90%"
  caption="Setting up for your device"
/>

5. Once done, provide the DevEUI credentials of your device into the **DevEUI** portion. This will automatically generate the specific End
device ID of your board. Then click **Generate** under **Device address**, **AppSKey**, and **NwkSKey** under the Provisioning information section. Then click **Register end device**.

:::tip 📝 NOTE:

- The **DevEUI**, **Device address**, **AppSKey**, and **NwkSKey** are hidden in this section as these are unique from a specific device. The **DevEUI** credential is unique to every RAK3172 device. Also, you should generate your own **Device address**, **AppSKey**, and **NwkSKey** credentials for your specific device and application.

:::

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_8.png"
  width="90%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_9.png"
  width="100%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_10.png"
  width="100%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_11.png"
  width="100%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_12.png"
  width="100%"
  caption="Setting up for your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_13.png"
  width="100%"
  caption="Register end device"
/>

6. You should now be able to see the device on the TTN console after you fully register your device, as shown in **Figure 142**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABP_RAK3172_New_14.png"
  width="100%"
  caption="ABP device successfully registered to TTN"
/>

##### ABP Configuration for TTN

The RAK3172 module can be configured using WisToolBox to do the ABP configuration. **WisToolBox** is a software tool that supports **RAK3172** module. It automatically detects the RAK3172 module once it is connected to the PC. Below are the options in WisToolBox where the ABP configuration can be done.

- [ABP Configuration for TTN via WisToolBox UI](#abp-configuration-for-ttn-via-wistoolbox-ui)
- [ABP Configuration for TTN via WisToolBox Console](#abp-configuration-for-ttn-via-wistoolbox-console)

##### ABP Configuration for TTN via WisToolBox UI

The **RAK3172** should have the correct ABP credentials to connect to TTN. This can be done using **WisToolBox**. Below are the steps on setting up your **RAK3172** using **WisToolBox**.

1. Connect your **RAK3172** with your chosen WisBlock base board to the PC via USB cable and open the **WisToolBox** application.

2. Click the **CONNECT DEVICE** button to launch the WisToolBox Dashboard.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_1.png"
  width="90%"
  caption="CONNECT DEVICE"
/>

3. Select your target port where your **RAK3172** is connected. Once recognized, click **CONNECT**, as shown in **Figure 145**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_2.png"
  width="90%"
  caption="Setting up your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_3.png"
  width="90%"
  caption="Setting up your device"
/>

4. Once done, **RAK3172** will appear in the dashboard, and then select it.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_4A.png"
  width="90%"
  caption="Device seen from WisToolBox dashboard"
/>

5. Then click **PARAMETERS** to do the configuration in your RAK3172.

:::tip 📝 NOTE:

- The **AppSKey**, **Device address**, and **NwkSKey** are hidden in this section as these are unique from a specific device.

:::

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_5.png"
  width="90%"
  caption="Setting up your device"
/>

 6. Click **Global settings** to set the network mode into **LoRaWAN** and join mode to **ABP**. Make sure that the active region is using **EU868** for this configuration. If you wish to work on other regional bands, you can choose among active regions based on your location.

- LoRa network mode: **LoRaWAN**
- LoRaWAN join mode: **ABP**
- LoRaWAN region: **EU868**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_6.png"
  width="90%"
  caption="Global settings"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_7A.png"
  width="90%"
  caption="Global settings"
/>

7. Then click **LoRaWAN keys, ID, EUI** to configure the **Application session key (AppSKey)**, **Device address** and **Network session key (NwkSKey)**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_7B.png"
  width="90%"
  caption="LoRaWAN keys, ID, EUI"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_8A.png"
  width="90%"
  caption="Setting up your device"
/>

8. Then go back to the console where your RAK3172 End device is created previously. Then copy all the credentials from there. Those will be the ones to be used also in the WisToolBox dashboard. Once encoded into the dashboard, click **APPLY COMMANDS** to update your device, as shown in **Figure 159**.

:::tip 📝 NOTE:

- The **AppSKey**, **Device address**, and **NwkSKey** are hidden in this section as these are unique from a specific device.

:::

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_9.png"
  width="100%"
  caption="Your created ABP device from your console"
/>

- **For Application session key (AppSKey)**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_9A.png"
  width="90%"
  caption="Copying the AppSKey credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_10A.png"
  width="90%"
  caption="Copying the AppSKey credential from TTN to WisToolBox"
/>

- **For Device address**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_9B.png"
  width="90%"
  caption="Copying the Device address credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_10B.png"
  width="90%"
  caption="Copying the Device address credential from TTN to WisToolBox"
/>

- **For Network session key (NwkSKey)**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_9C.png"
  width="90%"
  caption="Copying the NwkSKey credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_10C.png"
  width="90%"
  caption="Copying the NwkSKey credential from TTN to WisToolBox"
/>

- **WisToolBox Dashboard**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_10.png"
  width="90%"
  caption="Used credentials from your console in WisToolBox dashboard"
/>

9. Once done, you will see the summary of commands that is applied to your device. Then click **CLOSE**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_11.png"
  width="90%"
  caption="Summary of commands"
/>

10. Now, you will see it returns to the dashboard with updated credentials of your device.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPWis_RAK3172_New_12.png"
  width="90%"
  caption="Successfully configured ABP device via WisToolBox dashboard"
/>

##### ABP Configuration for TTN via WisToolBox Console

Here's another way of ABP configuration using **WisToolBox Console**. Below are the steps on setting up your **RAK3172** using **WisToolBox Console**.

1. Connect your **RAK3172** with your chosen WisBlock base board to the PC via USB cable and open the **WisToolBox** application.

2. Click the **CONNECT DEVICE** button to launch the WisToolBox Dashboard.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_1.png"
  width="90%"
  caption="CONNECT DEVICE"
/>

3. Select your target port where your **RAK3172** is connected. Once recognized, click **CONNECT**, as shown in **Figure 164**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_2.png"
  width="90%"
  caption="Setting up your device"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_3.png"
  width="90%"
  caption="Setting up your device"
/>

4. Once done, **RAK3172** will appear in the dashboard, and then select it.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_4.png"
  width="90%"
  caption="Device seen from WisToolBox dashboard"
/>

5. Then click **ADVANCED**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_5.png"
  width="90%"
  caption="Setting up your device"
/>

6. Once done, click **OPEN CONSOLE** to do the configuration.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_6.png"
  width="90%"
  caption="OPEN CONSOLE"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_7.png"
  width="90%"
  caption="Opening the Console terminal of WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_8.png"
  width="90%"
  caption="Opening the Console terminal of WisToolBox"
/>

7. To start the configuration, type **ATE** so you can echo the commands you input during your configuration. Then press **Enter**.

It is recommended to start by testing the console and verify that the current configuration is working by sending these two AT commands:

```
AT
```

```
ATE
```

`ATE` is useful for tracking the commands and troubleshooting.

You will receive `OK` when you input the two commands. After setting `ATE`, you can now see all the commands you input together with the replies.

:::tip 📝 NOTE:

If there is no `OK` or any reply, check if the device is powered correctly. If you are getting power from a USB port, ensure that you have a good USB cable.

:::

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_9A.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_9B.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_9C.png"
  width="90%"
  caption="Setting up your Console"
/>

8. Then configure the LoRaWAN join mode to **ABP**. You can check what parameter you will input by typing **AT+NJM?**, and then **Enter** into the console terminal. For **ABP**, you should input **AT+NJM=0**, and then press **Enter** as shown in **Figure 173**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_10.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_11.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_12.png"
  width="90%"
  caption="Setting up your Console"
/>

9. Once done, set up your LoRaWAN region to EU868. You can check what parameter you will input by typing **AT+BAND?**, and then **Enter** into the console terminal. For **EU868**, you should input **AT+BAND=4** then press **Enter**. If you wish to work on other regional bands, you may check the list of band parameter options below.

Set the frequency/region to EU868.

```
AT+BAND=4
```

:::tip 📝 NOTE:

Depending on the Regional Band you selected, you might need to configure the sub-band of your RAK3172 to match the gateway and LoRaWAN network server. This is especially important for Regional Bands like US915, AU915, and CN470.

To configure the masking of channels for the sub-bands, you can use the `AT+MASK` command that can be found on the [AT Command Manual](https://docs.rakwireless.com/Product-Categories/WisDuo/RAK3172-Module/AT-Command-Manual/#at-mask).

To illustrate, you can use sub-band 2 by sending the command `AT+MASK=0002`.
:::

**List of band parameter options**

| Code | Regional Band |
| ---- | ------------- |
| 0    | EU433         |
| 1    | CN470         |
| 2    | RU864         |
| 3    | IN865         |
| 4    | EU868         |
| 5    | US915         |
| 6    | AU915         |
| 7    | KR920         |
| 8    | AS923-1       |
| 9    | AS923-2       |
| 10   | AS923-3       |
| 11   | AS923-4       |

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_13.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_14.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_15.png"
  width="90%"
  caption="Setting up your Console"
/>

10. Then next to this will be updating the ABP credentials of your device. First to this will be the **Application session key (AppSKey)**. Go back to your console where your RAK3172 End device was created to copy the AppSKey credential then paste it to the WisToolBox Console then press **Enter**.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_W.png"
  width="90%"
  caption="Your created ABP device from your TTN console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_16.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_17.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_18.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_X.png"
  width="90%"
  caption="Copying the AppSKey credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_19.png"
  width="90%"
  caption="Setting up your Console"
/>

11. Once done, do the same procedure to **Device address** and **Network session key (NwkSKey)**.

- **For Device address**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_20.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_21.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_22.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_Y.png"
  width="90%"
  caption="Copying the Device address credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_23.png"
  width="90%"
  caption="Setting up your Console"
/>

- **For Network session key (NwkSKey)**

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_24.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_25.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_26.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_Z.png"
  width="90%"
  caption="Copying the NwkSKey credential from TTN to WisToolBox"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_27.png"
  width="90%"
  caption="Setting up your Console"
/>

12. Once done, click **Dashboard** to check the updated credentials of your ABP device. Click **PARAMETERS** to open the **Global Settings** and **LoRaWAN keys, ID, EUI**, and check whether these portions are updated.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_28.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_29.png"
  width="90%"
  caption="Setting up your Console"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_30.png"
  width="90%"
  caption="PARAMETERS"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_31A.png"
  width="90%"
  caption="Global settings and LoRaWAN keys, ID, EUI"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_31B.png"
  width="90%"
  caption="Global settings and LoRaWAN keys, ID, EUI details"
/>

13. Now you have a configured ABP device using WisToolBox Console. **ABP-configured devices** are directly tied to the network once done with the above procedures so the joining procedure is not needed.

14. Now, you can try sending the payload to TTN. Open again the terminal console of WisToolBox to send some payload using it. Send command format: **`AT+SEND=<port>:<payload>`**

```
AT+SEND=2:12345678
```

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_35.png"
  width="90%"
  caption="ABP device sending payload to the network"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_36.png"
  width="90%"
  caption="ABP device sending payload to the network"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_37.png"
  width="90%"
  caption="ABP device sending payload to the network"
/>

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_38.png"
  width="90%"
  caption="ABP device sending payload to the network"
/>

15. You can see the data sent by the RAK3172 module on the TTN device console *Live data* section. Also, the *Last seen* info should be a few seconds or minutes ago.

<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/ABPConWis_RAK3172_New_39.png"
  width="90%"
  caption="ABP Test Sample Data Sent Viewed in TTN"
/>

##### Connecting with ChirpStack

This section shows how to connect the RAK3172 module to the ChirpStack platform.


<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/23.chirpstack-platform.png"
  width="60%"
  caption="RAK3172 Module in the Context of the ChirpStack Platform"
/>

The ChirpStack, previously known as the LoRaServer project, provides open-source components for building LoRaWAN networks. In the case of TTN, the RAK3172 module is located in the periphery and will transmit the data to the backend servers through a LoRa gateway. Learn more about [ChirpStack](https://www.chirpstack.io/).

:::tip 📝 NOTE:

It is assumed that you are using a RAK Gateway and its built-in ChirpStack. Also, the gateway with the ChirpStack must be configured successfully. For further information, check the RAK documents for more details.

:::

* In summary, these are the requirements:

  1. In a ChirpStack online gateway, the frequency band of the nodes should be consistent with the frequency band of the gateway in use.
      * [Connect the Gateway with Chirpstack](/Product-Categories/WisGate/RAK7243/Quickstart/#connect-the-gateway-with-chirpstack)
  2.  The RAK Serial Port Tool provided by RAK
  3.  RAK3172 module

:::tip 📝 NOTE:
The frequency band used in the demonstration is EU868. Use a high-frequency version of RAK3172. The product number should be **RAK3172 (H)**.
:::

##### Create a New Application

1. Log in to the ChirpStack server using your account and password.

2. Go to the Application section, as shown in **Figure 206**.

![24 chirpstack](https://user-images.githubusercontent.com/49629370/224524821-5c92ccb3-5e9f-4d0c-b4cc-ef3730331e84.png)

3. By default, you should create a new application, although you can reuse existing ones. For this setup, create a new Application by clicking on the **CREATE** button and filling in the required parameters, as shown in **Figure 207** and **Figure 208**.

![25 new-application](https://user-images.githubusercontent.com/49629370/224524815-8e403432-1528-4f67-ab2f-dc023c4d5bd9.png)


* For this setup, create an Application named **rak_node_test**.

ChirpStack LoraServer supports multiple system configurations, with only one by default.

* **Service profile**: Field is to select the system profile.
* **Payload codec**: It is the parsing method for selecting load data, such as parsing LPP format data.

![26 filling-parameters](https://user-images.githubusercontent.com/49629370/224524811-897286de-6d6d-4c3c-955a-50be13d290cf.png)

<b>Register a New Device</b>

1. Choose the **Application** created in the previous step, then select the **DEVICES** tab, as shown in **Figure 209** and **Figure 210**.

2. Once done, click the "**+ CREATE**" button.

![27 application-available](https://user-images.githubusercontent.com/49629370/224524804-16a378d0-7356-4c5a-b875-3434c23b6423.png)


![28 application-page](https://user-images.githubusercontent.com/49629370/224524800-f93775aa-b832-45e5-9a24-b9d4fba3ed37.png)

3. Once inside the **DEVICES** tab, create a new device (LoRaWAN node) by clicking on the "**+ CREATE**" button.

![29 adding-node](https://user-images.githubusercontent.com/49629370/224524792-ff98d592-b3fa-484b-83e0-24853e3a37c2.png)

![30 new-device-registration](https://user-images.githubusercontent.com/49629370/224524780-8ffb71fc-5d44-4600-a6d5-3ed03de9ceb8.png)

6. Once the node is created, fill in the necessary data. You can generate a Device EUI automatically by clicking the following icon, or you can write a correct Device EUI in the edit box.

Fill in the parameters requested:

* **Device name and Device description**: These are descriptive texts about your device.

* **Device EUI**: This interface allows you to generate a Device EUI automatically by clicking the generate icon. You can also add a specific Device EUI directly in the form.

* **Device Profile**:
  * If you want to join in OTAA mode, select **DeviceProfile_OTAA**.
  * If you want to join in ABP mode, select **DeviceProfile_ABP**.

:::tip 📝 NOTE:
Device profiles **DeviceProfile_OTAA** and **DeviceProfile_ABP** are only available if you are using the built-in Chirpstack LoRaWAN Server of RAK Gateways.

If you have your own Chirpstack installation, you can set up the device profile with `LoRaWAN MAC version 1.0.3` and `LoRaWAN Regional Parameters revision B` to make it compatible with RAK3172.
:::

![31 adding-parameters](https://user-images.githubusercontent.com/49629370/224524771-8e4b2375-3695-439d-90c3-d102eff2696c.png)


##### Chirpstack OTAA Device Registration

1. If you have selected **DeviceProfile_OTAA**, as shown in **Figure 214**, then after the device is created, an Application Key must be also created for this device.

![32 otaa](https://user-images.githubusercontent.com/49629370/224524767-b09791ba-3ffa-4c5e-ab7f-1fc2ce588137.png)

2. A previously created Application Key can be entered here, or a new one can be generated automatically by clicking the icon highlighted in red in **Figure 215**.

![33 otaa-set-device-keys](https://user-images.githubusercontent.com/49629370/224524761-75639bf2-d922-4dc3-b2fd-bc0ed6441a0e.png)

3. Once the Application Key is added to the form, the process can be finalized by clicking on the **SET DEVICE-KEYS** button.

* As shown in **Figure 216**, a new device should be listed in the **DEVICES** tab. The most important parameters, such as the **Device EUI**, are shown in the summary.

![34 set-device-eui](https://user-images.githubusercontent.com/49629370/224524754-21ff172e-713c-42e0-be2d-c65250dbf7e7.png)

4. To end the process, it is a good practice to review that the Application Key is properly associated with this device. The Application Key can be verified in the **KEYS (OTAA)** tab, as shown in **Figure 217**.


![35 application-key](https://user-images.githubusercontent.com/49629370/224524749-ef78d2de-8e03-4150-9c82-9af53b09b72e.png)

:::tip 📝 NOTE:

Standard OTAA mode requires the **Device EUI**, **Application Key**, and **Application EUI**, but in ChirpStack’s implementation, only the Device EUI and the Application Key are mandatory. The Application EUI is not required and not recorded in the Application tab. Nevertheless, you can reuse the Device EUI as the Application EUI during the configuration on the side of the node.

:::

##### OTAA Configuration for Chirpstack

The RAK3172 module supports a series of AT commands to configure its internal parameters and control the functionalities of the module.

1. To set up the RAK3172 module to join the Chirpstack using OTAA, start by connecting the RAK3172 module to the Computer (see [Figure 35](#connect-to-the-rak3172)) and open the RAK Serial Port Tool. Select the right COM port and set the baud rate to 115200.

It is recommended to start by testing the serial communication and verify that the current configuration is working by sending these two AT commands:

```
AT
```

```
ATE
```

`ATE` will echo the commands you input to the module, which is useful for tracking the commands and troubleshooting.

You will receive `OK` when you input the two commands. After setting `ATE`, you can now see all the commands you input together with the replies. Try again `AT` and you should see it on the terminal followed by `OK`, as shown in **Figure 218**.

:::tip 📝 NOTE:

If there is no `OK` or any reply, you need to check if the wiring of your UART lines is correct and if the baud is correctly configured to 115200. Also, you can check if the device is powered correctly. If you are getting power from a USB port, ensure that you have a good USB cable.
:::

<img width="460" alt="atstart" src="https://user-images.githubusercontent.com/49629370/224524747-a61c6cf1-4028-4cb3-9efd-78102cc8adcb.png">

2. The next step is to configure the OTAA LoRaWAN parameters in RAK3172:

- LoRa work mode: **LoRaWAN**
- LoRaWAN join mode: **OTAA**
- LoRaWAN class: **Class A**
- LoRaWAN region: **EU868**

Set the work mode to LoRaWAN.

```
AT+NWM=1
```

Set the LoRaWAN activation to OTAA.

```
AT+NJM=1
```

Set the LoRaWAN class to Class A.

```
AT+CLASS=A
```

Set the frequency/region to EU868.

```
AT+BAND=4
```

:::tip 📝 NOTE:

Depending on the Regional Band you selected, you might need to configure the sub-band of your RAK3172 to match the gateway and LoRaWAN network server. This is especially important for Regional Bands like US915, AU915, and CN470.

To configure the masking of channels for the sub-bands, you can use the `AT+MASK` command that can be found on the [AT Command Manual](https://docs.rakwireless.com/Product-Categories/WisDuo/RAK3172-Module/AT-Command-Manual/#at-mask).

To illustrate, you can use sub-band 2 by sending the command `AT+MASK=0002`.
:::

**List of band parameter options**

| Code | Regional Band |
| ---- | ------------- |
| 0    | EU433         |
| 1    | CN470         |
| 2    | RU864         |
| 3    | IN865         |
| 4    | EU868         |
| 5    | US915         |
| 6    | AU915         |
| 7    | KR920         |
| 8    | AS923-1       |
| 9    | AS923-2       |
| 10   | AS923-3       |
| 11   | AS923-4       |



<img width="460" alt="otaaconfig" src="https://user-images.githubusercontent.com/49629370/224524741-b802c028-2a57-48f2-92ca-a747dc38d3e4.png">

3. After the configuration of the LoRaWAN parameters, the next step is to set up the DevEUI and AppKey. You need the use the values from the Chirpstack device console.

:::tip 📝 NOTE:
The Application EUI parameter is not required in the ChirpStack platform; therefore, it is possible to use the same id as the Device EUI.
:::

- Device EUI: **5E9D1E0857CF25F1**
- Application EUI: **5E9D1E0857CF25F1**
- Application Key: **F921D50CD7D02EE3C5E6142154F274B2**

Set the Device EUI.

```
AT+DEVEUI=5E9D1E0857CF25F1
```

Set the Application EUI.

```
AT+APPEUI=5E9D1E0857CF25F1
```

Set the Application Key.

```
AT+APPKEY=F921D50CD7D02EE3C5E6142154F274B2
```

![chirp_otaa_eui](https://user-images.githubusercontent.com/49629370/224524729-d9c1afab-07ea-411c-9cee-a9598890a24d.png)

4. After EUI and key configuration, the device can now join the network and send some payload.

```
AT+JOIN=1:0:10:8
```
:::tip 📝 NOTE:
`AT+JOIN` command parameters are optional. You can configure the settings for auto-join, reattempt interval, and the number of join attempts if your application needs it. If not configured, it will use the default parameter values.

`AT+JOIN` and `AT+JOIN=1` also share the common functionality of trying to join the network.
:::

Join command format: **`AT+JOIN=w:x:y:z`**

| Parameter | Description                                                  |
| --------- | ------------------------------------------------------------ |
| w         | Join command - 1: joining, 0: stop joining.                  |
| x         | Auto-join config - 1: auto-join on power-up, 0: no auto-join |
| y         | Reattempt interval in seconds (7-255) - 8 is the default.    |
| z         | Number of join attempts (0-255) - 0 is the default.              |

After 5 or 6 seconds, if the request is successfully received by a LoRa gateway, you should see the JOINED status reply.

:::tip 📝 NOTE:

If the OTAA device failed to join, you need to check if your device is within reach of a working LoRaWAN gateway that is configured to connect to Chirpstack. It is also important to check that all your OTAA parameters (DEVEUI and APPKEY) are correct, using the `AT+DEVEUI=?` and `AT+APPKEY=?` commands. Lastly, ensure that the antenna of your device is properly connected.

After checking all the things above, try to join again.
:::

5. With the end-device properly activated, you can now try to send some payload after a successful join.

```
AT+SEND=2:12345678
```

Send command format: **`AT+SEND=<port>:<payload>`**

![41 message-received](https://user-images.githubusercontent.com/49629370/224524677-85e83d6f-8fd0-4138-91b6-39368053261f.png)

On the ChirpStack platform, you should see the join and uplink messages in the **LORAWAN FRAMES** tab, as shown in **Figure 222**. By convention, messages sent from nodes to gateways are considered as **Uplinks** while messages sent by gateways to nodes are considered as **Downlinks**.


<rk-img
  src="/assets/images/wisduo/rak3172-module/quickstart/41.message-received.png"
  width="100%"
  caption="Chirpstack Data Received Preview"
/>

##### Chirpstack ABP Device Registration

1. During the registration of a new device, if you select **DeviceProfile_ABP**, as shown in **Figure 223**, then the ChirpStack platform will assume that this device will join the LoRaWAN network using the ABP mode.


:::tip 📝 NOTE:

Tick the checkbox **Disable counting frame verification**. During the test, when the module is restarted, the frame counting number will also be restarted from zero. This would cause a synchronization problem with the ChirpStack server treating it as a replay attack. For testing purposes, it is safe to disable this feature, but remember to activate it in a production environment.

:::


![42 configuring-device-abp](https://user-images.githubusercontent.com/49629370/224524665-9a05076f-669f-4fd8-a9ad-5aa9a2959302.png)

2. After selecting the ABP mode, the following parameters appear in the **ACTIVATION** tab:

Then, you can see that there are some parameters for ABP in the **ACTIVATION** item:

  * **Device address**
  * **Network Session Key**
  * **Application Session Key**

![43 abp-activation-parameters](https://user-images.githubusercontent.com/49629370/224524661-ecdc62b3-aac4-444a-8895-586e01ae3071.png)

3. The parameters can be generated as random numbers by the platform or can be set with user values. Once these parameters are filled in properly, the process is completed by clicking on the **ACTIVATE DEVICE** button.


##### ABP Configuration for Chirpstack

1. To set up the RAK3172 module to join the Chirpstack using ABP, start by connecting the RAK3172 module to the Computer (see [Figure 35](#connect-to-the-rak3172)) and open the RAK Serial Port Tool. Select the right COM port and set the baud rate to 115200.

It is recommended to start by testing the serial communication and verify that the current configuration is working by sending these two AT commands:

```
AT
```

```
ATE
```

`ATE` will echo the commands you input to the module, which is useful for tracking the commands and troubleshooting.

You will receive `OK` when you input the two commands. After setting `ATE`, you can now see all the commands you input together with the replies. Try again `AT` and you should see it on the terminal followed by `OK`, as shown in **Figure 225**.

:::tip 📝 NOTE:

If there is no `OK` or any reply, you need to check if the wiring of your UART lines is correct and if the baud is correctly configured to 115200. Also, you can check if the device is powered correctly. If you are getting power from a USB port, ensure that you have a good USB cable.
:::

<img width="460" alt="atstart" src="https://user-images.githubusercontent.com/49629370/224524650-00faec78-8ba4-4053-bf64-61a717d2aabf.png">

2. The next step is to configure the ABP LoRaWAN parameters in RAK3172:

- LoRa work mode: **LoRaWAN**
- LoRaWAN join mode: **ABP**
- LoRaWAN class: **Class A**
- LoRaWAN region: **EU868**

Set the work mode to LoRaWAN. It can be set to P2P as well but by default, the device is in LoRaWAN mode.

```
AT+NWM=1
```

Set the LoRaWAN activation to ABP.

```
AT+NJM=0
```

Set the LoRaWAN class to Class A.

```
AT+CLASS=A
```

Set the frequency/region to EU868.

```
AT+BAND=4
```

:::tip 📝 NOTE:

Depending on the Regional Band you selected, you might need to configure the sub-band of your RAK3172 to match the gateway and LoRaWAN network server. This is especially important on Regional Bands like US915, AU915, and CN470.

To configure the masking of channels for the sub-bands, you can use the [AT+MASK command](https://docs.rakwireless.com/Product-Categories/WisDuo/RAK3172-Module/AT-Command-Manual/#at-mask) that can be found on the AT Commands Manual.

To illustrate, you can use sub-band 2 by sending the command `AT+MASK=0002`.
:::

**List of band parameter options**

| Code | Regional Band |
| ---- | ------------- |
| 0    | EU433         |
| 1    | CN470         |
| 2    | RU864         |
| 3    | IN865         |
| 4    | EU868         |
| 5    | US915         |
| 6    | AU915         |
| 7    | KR920         |
| 8    | AS923-1       |
| 9    | AS923-2       |
| 10   | AS923-3       |
| 11   | AS923-4       |



<img width="460" alt="abpconfig" src="https://user-images.githubusercontent.com/49629370/224524640-fc7b77ad-5f62-4189-a5fb-99a62dc916e4.png">

3. After the configuration of the LoRaWAN parameters, the next step is to set up the device address and session keys. You need the use the values from the TTN device console.

- Device Address: **26011AF9**
- Application Session Key: **4D42EC5CAF97F03D833CDAf5003F69E1**
- Network Session Key: **C280CB8D1DF688BC18601A97025C5488**

Set the Device Address.

```
AT+DEVADDR=26011AF9
```

Set the Application Session Key.

```
AT+APPSKEY=4D42EC5CAF97F03D833CDAf5003F69E1
```

Set the Network Session Key.

```
AT+NWKSKEY=C280CB8D1DF688BC18601A97025C5488
```

![chirp_abp_key](https://user-images.githubusercontent.com/49629370/224524630-4c1c7007-5bcd-408a-ba86-aaa7ee73ebc3.png)

After EUI and keys configuration, the device can now join the network and send some payload.

```
AT+JOIN=1:0:10:8
```
:::tip 📝 NOTE:
`AT+JOIN` command parameters are optional. You can configure the settings for auto-join, reattempt interval, and the number of join attempts if your application needs it. If not configured, it will use the default parameter values.

`AT+JOIN` and `AT+JOIN=1` also share the common functionality of trying to join the network.
:::

Join command format: **`AT+JOIN=w:x:y:z`**

| Parameter | Description                                                  |
| --------- | ------------------------------------------------------------ |
| w         | Join command - 1: joining, 0: stop joining.                  |
| x         | Auto-join config - 1: auto-join on power-up, 0: no auto-join |
| y         | Reattempt interval in seconds (7-255) - 8 is the default.    |
| z         | Number of join attempts (0-255) - 0 is the default.              |

4. After 5 or 6 seconds, if the request is successfully received by a LoRa gateway, then you should see the JOINED status reply.

5. You can now try to send some payload after a successful join.

```
AT+SEND=2:12341234
```
Send command format: **`AT+SEND=<port>:<payload>`**

![chirp_abp_send](https://user-images.githubusercontent.com/49629370/224524623-5662f060-9426-4ae0-9a27-7461ca28b893.png)


#### LoRa P2P Mode

This section will show you how to set up and connect two RAK3172 units to work in the LoRa P2P mode. The configuration of the RAK3172 units is done by connecting the two modules to a general-purpose computer using a USB-UART converter. The setup of each RAK3172 can be done separately, but testing the LoRa P2P mode will require having both units connected simultaneously. This could be done by having one computer with two USB ports or two computers with one USB port each.

It is recommended to start by testing the serial communication and verify the current configuration is working by sending these two AT commands:

```
AT
```

```
ATE
```

`ATE` will echo the commands you input to the module, which is useful for tracking the commands and troubleshooting.

You will receive `OK` when you input the two commands. After setting `ATE`, you can now see all the commands you input together with the replies.

Try again `AT` and you should see it on the terminal followed by `OK`.


![p2p-1](https://user-images.githubusercontent.com/49629370/224524615-d20e0a21-361c-40a8-80a4-3d8cef0deaca.png)

1. In setting up the RAK3172 to work in LoRa P2P mode, you need to change the LoRa network work mode command on both RAK3172 modules.

```
AT+NWM=0
```
`AT+NWM` parameter mode can be either 0=LoRa P2P or 1=LoRaWAN.

![p2p-2](https://user-images.githubusercontent.com/49629370/224524610-91c6307a-f24b-4c43-8982-68f66167c7ab.png)

:::tip 📝 NOTE:
- The device will start automatically if you change modes from LoRaWAN to LoRa P2P and vice-versa.
- You might need to input the `ATE` command again to ensure that your succeeding commands on P2P mode echo on the terminal.
:::

2. You need to input the P2P setup on both RAK3172 modules. The parameters should be exactly the same in the two modules.

```
AT+P2P=868000000:7:125:0:10:14
```

For this P2P setup, the LoRa parameters are the following:

- Link frequency: **868000000&nbsp;Hz**
- Spreading factor: **7**
- Bandwidth: **125&nbsp;kHz**
- Coding Rate: 0 = **4/5**
- Preamble Length: **10**
- Power: **14&nbsp;dBm**

:::tip 📝 NOTE:
Refer to the P2P Mode section of the [AT command documentation](/Product-Categories/WisDuo/RAK3172-Module/AT-Command-Manual/) to learn more about the definition of the parameters used and the individual commands if you want specific parameters changed.
:::

![p2p-3](https://user-images.githubusercontent.com/49629370/224524597-f169952d-3d5b-4b55-98e8-68aea2b88236.png)

3. To set one module as the receiver (RX), you need to set the value of the P2P receive command.

:::tip 📝 NOTE:
LoRa P2P default setting is Transmitter (TX) mode. This consumes lower power compared to Receiver (RX) mode where the radio is always listening for LoRa packets.
:::

a. P2P LoRa RX configurable duration value is from 1 to 65533&nbsp;ms. In this example, the device will listen and wait for LoRa P2P Packets for 30000&nbsp;ms or 30&nbsp;seconds. It will automatically disable RX mode and switch to TX mode after the timeout. If the device did not receive any packets within the time period, then the callback after timeout is `+EVT:RXP2P RECEIVE TIMEOUT`.

```
AT+PRECV=30000
```
b. If the `AT+PRECV` value is set to **65535**, the device will listen to P2P LoRa packets without a timeout, but it will stop listening once a P2P LoRa packet is received. After receiving the packets, it will disable RX mode and automatically switch to TX mode again.

```
AT+PRECV=65535
```

c. If the `AT+PRECV` value is set to **65534**, the device will continuously listen to P2P LoRa packets without any timeout. They will continuously stay in RX mode until `AT+PRECV` is set to **0**.

```
AT+PRECV=65534
```

d. If the `AT+PRECV` value is set to **0**, the device will stop listening to P2P LoRa packets. It disables LoRa P2P RX mode and switches to TX mode.

```
AT+PRECV=0
```

4. With one module configured as Transmitter (TX) and the other device will be the Receiver (RX), you can now try to send or transmit P2P payload data.

```
AT+PSEND= <payload>
```
:::tip 📝 NOTE:
- `AT_PARAM_ERROR` is returned when setting the wrong or malformed value.
- `AT_BUSY_ERROR` is returned if the device is still in RX mode and you try to send or reconfigure the RX period. If the `AT+PRECV` command is set to **65534**, you need to execute first `AT+PRECV=0` to be able to configure again the TX and RX state and avoid `AT_BUSY_ERROR`.
- `<payload>`: 2~500 digit length, must be an even number of digits and character 0-9, a-f, A-F only, representing 1~256 hexadecimal numbers. For example, if the payload is like ` 0x03, 0xAA, 0x32`, then the AT command should be `AT+PSEND = 03AA32`.
:::

![p2p-4](https://user-images.githubusercontent.com/49629370/224524586-c2448080-6a90-4dd9-97e0-b2adf4c41690.png)

## Miscellaneous

### Upgrading the Firmware

If you want to upgrade to the latest version of the firmware of the module, you can follow this section. The latest firmware can be found in the software section of [RAK3172 Datasheet](/Product-Categories/WisDuo/RAK3172-Module/Datasheet/#firmware-os).

:::tip 📝 NOTE:

**What if the RAK3172 module stops responding to AT commands and firmware updates?**

You can recover your device by using the `.hex` file in the datasheet and uploading it using STM32CubeProgrammer. The guide on updating STM32 firmware using STM32CubeProgrammer can be found in the [Learn section](/Knowledge-Hub/Learn/STM32Cube-Programmer-Guide/).

**WARNING:** Uploading the **.hex** file via STM32CubeProgrammer will erase all configured data on the device.

:::

#### Firmware Upgrade Through UART2

##### Minimum Hardware and Software Requirements

Refer to the table for the minimum hardware and software required to perform the firmware upgrade via UART2:

| Hardware/Software | Requirement                                   |
| ----------------- | --------------------------------------------- |
| Computer          | A Windows/Ubuntu/Mac computer                 |
| Firmware File     | Bin firmware file downloaded from the website |
| Others            | A USB to TTL module                           |

##### Firmware Upgrade Procedure

Execute the following procedure to upgrade the firmware in Device Firmware Upgrade (DFU) mode through the UART2 interface.

:::tip 📝 NOTE:
RAK3172 should automatically go to BOOT mode when the firmware is uploaded via RAK DFU Tool or WisToolBox.

If BOOT mode is not initiated, pull to ground the RESET pin twice (or double click the reset button if available) to force BOOT mode.
:::

1.  Download the latest application firmware of the RAK3172.

    - [RAK3172 Firmware](/Product-Categories/WisDuo/RAK3172-Module/Datasheet/#firmware-os)

2.  Download the RAK Device Firmware Upgrade (DFU) tool.
    - [RAK Device Firmware Upgrade (DFU) Tool](https://downloads.rakwireless.com/LoRa/Tools/RAK_Device_Firmware_Upgrade_tool/)

3.  Connect the RAK3172 module with a computer through a USB to TTL. Refer to [Figure 35](#connect-to-the-rak3172).

4.  Open the Device Firmware Upgrade tool. Select the serial port and baud rate (115200) of the module and click the **Select Port** button.

:::tip 📝 NOTE:

If your firmware upload always fails, check your current baud rate setting using the `AT+BAUD=?` command and use that baud rate value in the RAK DFU Tool. You can also check if you selected the right COM port.

:::

![1](https://user-images.githubusercontent.com/49629370/224524567-a45a7e23-a80d-45f5-ba74-84f862ed1d4a.png)

5.  Select the application firmware file of the module with the suffix **.bin**.

![2](https://user-images.githubusercontent.com/49629370/224524563-aaa9748e-8ebf-4c80-ab10-403f0507bdd0.png)

6.  Click the **Upgrade** button to upgrade the device. After the upgrade is complete, the RAK3172 will be ready to work with the new firmware.

![3](https://user-images.githubusercontent.com/49629370/224524561-18bab9a4-22bc-40cb-8a23-c0587039b1ec.png)

![4](https://user-images.githubusercontent.com/49629370/224524551-138f31e3-ddfb-4a64-bcff-ade6563b016b.png)

### Arduino Installation

Refer to [Software section](#software).
