/***
 *  This example read WB_A1 pin in analog signal.
***/
//Set pin number
#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
uint8_t analogPin = WB_A1;
#else
#warning Please set the right pin refer to the documentation
uint8_t analogPin = 0xFF;	//analog Pins 
#endif

void setup()
{
    // initialize serial communication at 115200 bits per second
    Serial.begin(115200);
    Serial.println("RAKwireless Arduino Analog Example");
    Serial.println("------------------------------------------------------");

    //Assume RAK5811 is plugged, so turn on RAK5811 first.
    pinMode(WB_IO1, OUTPUT);
    digitalWrite(WB_IO1, HIGH);

    analogReadResolution(14);
}

void loop()
{
    float max, ref;

    switch (udrv_adc_get_resolution()) {
        case UDRV_ADC_RESOLUTION_6BIT:
        {
            max = 64.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_8BIT:
        {
            max = 256.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_10BIT:
        default:
        {
            max = 1024.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_12BIT:
        {
            max = 4096.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_14BIT:
        {
            max = 16384.0;
            break;
        }
    }

    switch (udrv_adc_get_mode()) {
        case UDRV_ADC_MODE_DEFAULT:
        default:
        {
            #ifdef rak11720
            ref = 2.0;
            #else
            ref = 3.6;
            #endif
            break;
        }
        #ifdef rak11720
        case UDRV_ADC_MODE_1_5:
        {
            ref = 1.5;
            break;
        }
        #else
        case UDRV_ADC_MODE_3_3:
        {
            ref = 3.3;
            break;
        }
        case UDRV_ADC_MODE_3_0:
        {
            ref = 3.0;
            break;
        }
        case UDRV_ADC_MODE_2_4:
        {
            ref = 2.4;
            break;
        }
        case UDRV_ADC_MODE_1_8:
        {
            ref = 1.8;
            break;
        }
        case UDRV_ADC_MODE_1_2:
        {
            ref = 1.2;
            break;
        }
        #endif
    }
    int adc_value = analogRead(analogPin);
    Serial.printf("ADC pin value = %d\r\n", adc_value);	// print analogPin adc value 
    // This is the formula to get the input voltage of RAK5811:
    Serial.printf("Voltage value = %f V\r\n", ref*(((float)adc_value)/max)*(5.0f)/(3.0f));
    delay(1000);
}
