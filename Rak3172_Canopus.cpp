#include <Rak3172_Canopus.h>
#include <Arduino.h>
void init_io()
{
	pinMode(LED_RECV, OUTPUT);
	pinMode(LED_SEND, OUTPUT);
	pinMode(LED_SYNC, OUTPUT);

	digitalWrite(LED_RECV, HIGH);
	digitalWrite(LED_SEND, HIGH);
	digitalWrite(LED_SYNC, HIGH);

	pinMode(V_SS3, OUTPUT);
	pinMode(V_SS5, OUTPUT);
	pinMode(V_SS12, OUTPUT);

	digitalWrite(V_SS3, HIGH); // OFF
	digitalWrite(V_SS5, LOW);  // OFF
	#ifdef V3_4
	digitalWrite(V_SS3, HIGH); // OFF
	digitalWrite(V_SS5, HIGH);  // OFF
	digitalWrite(V_SS12, HIGH); // OFF
	#else
	digitalWrite(V_SS3, HIGH); // OFF
	digitalWrite(V_SS5, LOW);  // OFF
	#endif
	delay(1000);			   // do not remove this delay, it use for detect baud upload code UART mode
}

void enable_Vss3()
{
	digitalWrite(V_SS3, LOW); // Enable 3.3V
}

void enable_Vss5()
{
	#ifdef V3_4
	digitalWrite(V_SS5, LOW); // Enable 5V
	#else
	digitalWrite(V_SS5, HIGH); // Enable 5V	
	#endif
}

void enable_Vss12()
{
	digitalWrite(V_SS12, LOW); // Enable 5V
}

void enable_Vrs485()
{
	//enable_Vss5(); // v3.1 On power module rs485
	enable_Vss3(); // V3.2 and upper On power module rs485
}

void disable_Vrs485()
{
	//disable_Vss5; // OFF power module rs485
	disable_Vss3(); // V3.2 and upper Off power module rs485
}

void disable_Vss3()
{
	digitalWrite(V_SS3, HIGH); // OFF 3.3V
}

void disable_Vss5()
{	
	#ifdef V3_4
	digitalWrite(V_SS5, HIGH); // OFF 5V
	#else
	digitalWrite(V_SS5, LOW); // OFF 5V
	#endif
}

void disable_Vss12()
{
	digitalWrite(V_SS12, HIGH); // OFF 5V
}

void save_power()
{
	disable_Vss3();
	disable_Vss5();
	disable_Vss12();
	pinMode(AI1_PIN, OUTPUT);
	pinMode(AI2_PIN, OUTPUT);
	digitalWrite(AI1_PIN, LOW);
	digitalWrite(AI2_PIN, LOW);
	pinMode(PB6, OUTPUT);
	pinMode(PB7, OUTPUT);
	digitalWrite(PB6, LOW);
	digitalWrite(PB7, LOW);
	
	pinMode(PA11, OUTPUT);
	pinMode(PA12, OUTPUT);
	digitalWrite(PA11, LOW);
	digitalWrite(PA12, LOW);
}