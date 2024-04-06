#include <Rak3172_Canopus.h>  // Include the Rak3172_Canopus library header file.
#define V3  // Define macro V3.

void setup()
{
    Serial.begin(115200);  // Initialize serial communication at 115200 baud rate.
    Serial.println("Canopus Digital Example");  // Print a message indicating the start of the program.
    Serial.println("------------------------------------------------------");  // Print a separator line.
    pinMode(LED_SEND, OUTPUT);  // Set pin LED_SEND as an output.
}

void loop()
{
    digitalWrite(LED_SEND, HIGH);  // Turn on the LED connected to pin LED_SEND.
    delay(1000);  // Wait for 1 second.
    digitalWrite(LED_SEND, LOW);  // Turn off the LED connected to pin LED_SEND.
    delay(1000);  // Wait for 1 second before the next iteration of the loop.
}
