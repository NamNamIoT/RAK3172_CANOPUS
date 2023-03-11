uint8_t ledPin = PA8;		// Set any pin to test tone()
uint8_t pulsePin = 0xFF;	// Set any pin to be pulse Pin

// variable for recording the pulse status timing.
unsigned long duration;

void setup()
{
    // initialize serial communication at 115200 bits per second
    Serial.begin(115200);

    Serial.println("RAK3172_Canopus Arduino Advance IO Example");
    Serial.println("------------------------------------------------------");
    // initialize digital pin "pulsePin" as an input with the internal pull-up resistor enabled
    pinMode(pulsePin, INPUT_PULLUP);
    // initialize the LED pin as an output:
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // waits for the pin to go from HIGH to LOW, starts timing, then waits for the pin to go HIGH and stops timing.
    // read the pulsePin time value
    duration = pulseIn(pulsePin, LOW, 20000000);
    Serial.print("Pulse duration = ");
    Serial.print((float) duration / 1000000);	// convert microseconds to seconds and print it out
    Serial.println(" sec");

    if (duration >= 15000000)	// LED turns off when duration exceed 15 seconds
        noTone(ledPin);
    else if (duration >= 10000000)	// LED turns on 5 seconds when duration in 10 ~ 15 seconds
        tone(ledPin, 494, 5000);
    else if (duration >= 5000000)	// LED turns on when seconds 5 seconds and less than 10 seconds
        tone(ledPin, 494);
}
