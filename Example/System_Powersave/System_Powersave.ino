/***
 *  This example shows powersave function.
***/

void setup()
{
    Serial.begin(115200);
  
    Serial.println("RAKwireless System Powersave Example");
    Serial.println("------------------------------------------------------");
  
#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
    api.system.sleep.setup(RUI_WAKEUP_FALLING_EDGE, WB_IO1);	// Set a pin to be wake up pin
#else
#warning Please set the right pin refer to the documentation
    api.system.sleep.setup(RUI_WAKEUP_FALLING_EDGE, 0xFF);
#endif
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
