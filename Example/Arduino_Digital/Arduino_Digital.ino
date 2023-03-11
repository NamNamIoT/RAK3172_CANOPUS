/***
 *  This example reads WB_IO1 pin value, if the pin value is LOW then light the blue led.
***/

// set pin number
#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
uint8_t ledPin = WB_LED2;	// set ledpin to Blue Led
uint8_t inputPin = WB_IO1;	// set inputPin to IO1
#else
#warning please set the right pin refer to the documentation.
uint8_t ledPin = 0xFF;		// Set any pin to test digitalRead()
uint8_t inputPin = 0xFF;	// Set any pin to be input Pin
#endif

void setup()
{
    // initialize serial communication at 115200 bits per second
    Serial.begin(115200);
  
    Serial.println("RAKwireless Arduino Digital Example");
    Serial.println("------------------------------------------------------");
    // initialize the LED pin as an output  
    pinMode(ledPin, OUTPUT);
    // initialize digital pin "inputPin" as an input with the internal pull-up resistor enabled
    pinMode(inputPin, INPUT_PULLUP);
}

void loop()
{
    int val = digitalRead(inputPin);	// read input pin value (HIGH or LOW)
  
    if (val == LOW)
        digitalWrite(ledPin, HIGH);	// LED turn on when input pin value is LOW
    else
        digitalWrite(ledPin, LOW);	// LED turn off when input pin value is HIGH 

}
