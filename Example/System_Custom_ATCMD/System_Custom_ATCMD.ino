/***
 *  This example shows custom AT command with led control.
***/

uint32_t led_status;

int led_handle(SERIAL_PORT port, char *cmd, stParam * param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        Serial.print(cmd);
        Serial.print("=");
        Serial.println(led_status ? "HIGH" : "LOW");
    } else if (param->argc == 1) {
        for (int i = 0; i < strlen(param->argv[0]); i++) {
            if (!isdigit(*(param->argv[0] + i))) {
  	            return AT_PARAM_ERROR;
            }
        }
  
        led_status = strtoul(param->argv[0], NULL, 10);
        if (led_status != 0 && led_status != 1) {
            return AT_PARAM_ERROR;
        }
  
        pinMode(GREEN_LED, OUTPUT);
        pinMode(BLUE_LED, OUTPUT);
        digitalWrite(GREEN_LED, (led_status == 1) ? HIGH : LOW);
        digitalWrite(BLUE_LED, (led_status == 1) ? HIGH : LOW);
    } else {
        return AT_PARAM_ERROR;
    }
  
    return AT_OK;
}

void setup()
{
    Serial.begin(115200);
    Serial.println("RAKwireless Custom ATCMD Example");
    Serial.println("------------------------------------------------------");
    api.system.atMode.add("LED", "This controls both green and blue LEDs.",
			"LED", led_handle);
}

void loop()
{
}
