#include <Rak3172_Canopus.h>

void init_io()
{
	pinMode(LED_YELLOW, OUTPUT);
	pinMode(LED_BLUE, OUTPUT);
	pinMode(LED_RED, OUTPUT);
	// pinMode(LED_SEND, OUTPUT);
	// pinMode(LED_RECV, OUTPUT);
	// pinMode(LED_SYNC, OUTPUT);
	digitalWrite(LED_YELLOW, HIGH);
	digitalWrite(LED_BLUE, LOW);
	digitalWrite(LED_RED, LOW);

	pinMode(V_SS3, OUTPUT);
	pinMode(V_SS5, OUTPUT);

	digitalWrite(V_SS3, HIGH); // OFF
	digitalWrite(V_SS5, LOW);  // OFF
	delay(1000);			   // do not remove this delay, it use for detect baud upload code UART mode
}

void enable_Vrs485()
{
	digitalWrite(V_SS5, HIGH); // On power module rs485
}

void enable_Vss3()
{
	digitalWrite(V_SS3, LOW); // Enable 3.3V
}

void enable_Vss5()
{
	digitalWrite(V_SS5, HIGH); // Enable 5V
}