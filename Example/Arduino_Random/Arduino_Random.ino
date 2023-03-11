/***
 *  This example shows random function, it reads WB_A0 as random seed.
***/

#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
uint8_t inputPin = WB_A0;
#else
uint8_t inputPin = 0xFF;
#endif

void setup()
{
    // initialize serial communication at 115200 bits per second
    Serial.begin(115200);
    Serial.println("RAKwireless Arduino Random Example");
    Serial.println("------------------------------------------------------");
    // initializes the pseudo-random number generator
    randomSeed(analogRead(WB_A0));
}

void loop()
{
    Serial.print("Random number(0 ~ 999) : ");
    uint32_t l = random(1000);	// generate a random number between 0 and 999
    Serial.println(l);
    delay(1000);
}
