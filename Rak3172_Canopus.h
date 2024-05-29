#ifndef RAK3172_CANOPUS_H
#define RAK3172_CANOPUS_H
#endif

#define V3
#ifdef RAK3172_CANOPUS_H

#define LED_YELLOW PB2
#define LED_RECV PB2
#define LED_BLUE PA8
#define LED_SEND PA8
#define I2C_SDA PA11
#define I2C_SCL PA12
#define Volt_PIN PB4

#ifdef V1
#define LED_RED PA0
#define LED_SYNC PA0
#define mA_PIN PB3
#define V_SS3 PB5
#define V_SS5 PB12
#endif

#ifdef V2
#define LED_RED PA10
#define LED_SYNC PA10
#define mA_PIN PB3
#define V_SS3 PB5
#define V_SS5 PA1
#endif

#ifdef V3
#define LED_RED PA9
#define LED_SYNC PA9
#define AI2_PIN PA10
#define AI1_PIN PA15
#define V_SS3 PB5
#define V_SS5 PA1
#define ABAT PB3
#endif

void init_io();
void enable_Vrs485();
void enable_Vss3();
void enable_Vss5();
#endif