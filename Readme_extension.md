- Download and install the [Arduino IDE](https://www.arduino.cc/en/Main/Software).

warning ⚠️ WARNING
_**If you are using Windows 10**_.
Do _**NOT**_ install the Arduino IDE from the Microsoft App Store. Instead, install the original Arduino IDE from the Arduino official website. The Arduino app from the Microsoft App Store has problems using third-party Board Support Packages.
:::

- Add RAK3172_Canopus as a supported board in Arduino IDE by updating Board Manager URLs in **Preferences** settings of Arduino IDE with the JSON URL below.
```json
https://raw.githubusercontent.com/RAKWireless/RAKwireless-Arduino-BSP-Index/main/package_rakwireless.com_rui_index.json
```
After that, you can then add **RAKwireless RUI STM32 Boards** via Arduino board manager.

#### Software

The default firmware of RAK3172_Canopus is based on RUI3, which allows you to develop your own custom firmware to connect sensors and other peripherals to it. To develop using your custom firmware using the Arduino IDE, you need to first add RAKwireless RUI STM32 boards to the Arduino board manager, which will be discussed in this guide. You can then use [RUI3 APIs] (https://docs.rakwireless.com/RUI3/Arduino-API/) for your intended application.

##### RAK3172_Canopus board Support Package in Arduino IDE

If you don't have an Arduino IDE yet, you can download it on the [Arduino official website](https://www.arduino.cc/en/Main/Software) and follow the installation procedure in the [miscellaneous section](/Product-Categories/wisduo/RAK3172-Module/Quickstart/#arduino-installation) of this document.

:::tip 📝 NOTE:
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

8. Once the BSP is installed, select  **Tools** > **Boards Manager** > **RAKWireless RUI STM32 Modules** > **WisDuo RAK3172 Evaluation Board**. 

The RAK3172_Canopus board uses the RAK3172 WisDuo module.
![rui-stm32](https://user-images.githubusercontent.com/49629370/224521144-d1ec1a5f-5c67-46f1-8f99-5da1b4b57a23.png)

9. Install RAK3172_Canopus library

⚠️ WARNING
**_Both RAK Wisblock Examples_** and **_RAK3172_Canopus Examples_** support for RAK3172_Canopus board

Download https://github.com/NamNamIoT/RAK3172_CANOPUS and Extract to Arduino\libraries
![Extra](https://user-images.githubusercontent.com/49629370/224536933-6abbdef3-832f-401c-98c7-cdeeca470cff.PNG)


Find RAK3172_Canopus library:


![Canopus_example](https://user-images.githubusercontent.com/49629370/224537325-ce897674-e104-43c6-900c-542c1bdc90f9.PNG)

##### RAK3172 COM Port on Device Manager

Connect the RAK3172 via USB type C and check COM Port using Windows **Device Manager**. Double-click the reset button if the module is not detected.

![rui-port](https://user-images.githubusercontent.com/49629370/224521157-ca08067c-cce1-434d-bd27-10ac67277c7b.png)
