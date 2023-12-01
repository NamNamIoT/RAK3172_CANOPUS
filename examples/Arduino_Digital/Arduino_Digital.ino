#include <Rak3172_Canopus.h>
#define V3

void setup()
{
    // initialize serial communication at 115200 bits per second
    Serial.begin(115200);
    Serial.println("Canopus Digital Example");
    Serial.println("------------------------------------------------------");
    // initialize the LED pin as an output  
    pinMode(LED_SEND, OUTPUT);
}

void loop()
{

    digitalWrite(LED_SEND, HIGH);	// LED turn on when input pin value is LOW
    delay(1000);
    digitalWrite(LED_SEND, LOW);	// LED turn off when input pin value is HIGH 
    delay(1000);
}
