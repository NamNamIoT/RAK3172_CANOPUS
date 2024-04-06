#include <Rak3172_Canopus.h>  // Include the Rak3172_Canopus library header file.

#define V3  // Define macro V3.

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud rate.
  Serial.println("Canopus Analog Example");  // Print a message indicating the start of the program.
  Serial.println("------------------------------------------------------");  // Print a separator line.
  pinMode(V_SS5, OUTPUT);  // Set pin V_SS5 as an output.
  digitalWrite(V_SS5, PWR_ON);  // Turn on the V_SS5 pin.
  analogReadResolution(12);  // Set analog read resolution to 12 bits.
}

void loop() {
  float AI1 = analogRead(AI1_PIN)*2.58;         // Read analog voltage from pin AI1_PIN and store it in AI1.
  Serial.printf("AI1 = %0.0fmV\r\n", AI1); // Print the analog voltage value of AI1 in millivolts.

  float AI2 = analogRead(AI2_PIN)*2.58;         // Read analog voltage from pin AI2_PIN and store it in AI2.
  Serial.printf("AI2 = %0.0fmV\r\n", AI2); // Print the analog voltage value of AI2 in millivolts.

  delay(1000);  // Wait for 1 second before the next iteration of the loop.
}
