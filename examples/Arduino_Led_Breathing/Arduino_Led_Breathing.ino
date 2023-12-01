#include <Rak3172_Canopus.h>
#define V3

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
    pinMode(LED_SYNC, OUTPUT);
    pinMode(LED_SEND, OUTPUT);
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
        analogWrite(LED_SYNC, val);	// Light the green led
    else
        analogWrite(LED_SEND, val);	// Light the blue led
}
