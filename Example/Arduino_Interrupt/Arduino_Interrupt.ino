/***
 *  This example reads WB_IO1 and WB_IO2 pin value for interrupt, if the pin value goes from high to low, then light the green or blue led.
***/

// set pin number
#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
uint8_t interruptPin1 = WB_IO1;	// set interrupt pin1 to IO1(J12-IO1)
uint8_t interruptPin2 = WB_IO2;	// set interrupt pin2 to IO2(J12-IO2)
uint8_t ledPin1 = GREEN_LED;
uint8_t ledPin2 = BLUE_LED;
#else
#warning Please set the right pin refer to the documentation
uint8_t interruptPin1 = 0xFF;
uint8_t interruptPin2 = 0xFF;
uint8_t ledPin1 = 0xFF;
uint8_t ledPin2 = 0xFF;
#endif
volatile byte state1 = LOW;	// set variable for green led state
volatile byte state2 = LOW;	// set variable for blue led state

void blink1()
{
    state1 = !state1;		// Invert green led state
}

void blink2()
{
    state2 = !state2;		// Invert blue led state
}

void setup()
{
    // initialize serial communcation at 115200 bits per second
    Serial.begin(115200);

    Serial.println("RAKwireless Arduino Interrupt Example");
    Serial.println("------------------------------------------------------");
    // initialize the green led and blue led pin as an output
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    // initialize interrupt pin 1 and pin 2 as an input with the internal pull-up resistor enabled
    pinMode(interruptPin1, INPUT_PULLUP);
    pinMode(interruptPin2, INPUT_PULLUP);
    // trigger interrupt execute blink1() when the pin 1 goes from high to low
    attachInterrupt(interruptPin1, blink1, FALLING);
    // trigger interrupt execute blink2() when the pin 2 goes from high to low
    attachInterrupt(interruptPin2, blink2, FALLING);
}

void loop()
{
    // set the value to control LED
    digitalWrite(ledPin1, state1);
    digitalWrite(ledPin2, state2);
}
