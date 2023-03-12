/***
 *  This example shows led breathing by analog.
***/

#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
uint8_t ledPin1 = LED_GREEN;
uint8_t ledPin2 = LED_BLUE;
#else
#warning please set the right pin refer to the documentation.
uint8_t ledPin1 = 0xFF;
uint8_t ledPin2 = 0xFF;
#endif

int val = 0;			// variable for LED brightness value
bool state = false;		// variable for control led brightness status
bool ledSwitch = false;		// variable for switch led

void valChage()
{
    state = !state;		// invert led control brightness status
    if (val == 0)
        ledSwitch = !ledSwitch;	// switch led when one of the led is darkest
}

void setup()
{
    //initialize serial communcation at 115200 bits per second
    Serial.begin(115200);

    Serial.println("RAKwireless Arduino LED Breathing Example");
    Serial.println("------------------------------------------------------");
    // initialize the LED pin as an output
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
}

void loop()
{
    // call function when led is brightest or darkest
    if (val == 0 || val == 255)
        valChage();

    // determine to make the led lighter or darker
    if (state)
        val++;
    else
        val--;
    // To switch the lighting led
    if (ledSwitch)
        analogWrite(ledPin1, val);	// Light the green led
    else
        analogWrite(ledPin2, val);	// Light the blue led
}
