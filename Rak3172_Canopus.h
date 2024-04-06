#ifndef RAK3172_CANOPUS_H
#define RAK3172_CANOPUS_H
#endif
#define V3
#ifdef RAK3172_CANOPUS_H


#define	LED_YELLOW PB2
#define	LED_BLUE PA8
#define	LED_SEND PA8
#define LED_RECV PB2
#define VSS_PIN PB5
#define I2C_SDA PA11
#define I2C_SCL PA12
#define PWR_ON LOW
#define PWR_OFF HIGH
#define Volt_PIN PB4

#ifdef V1
#define	LED_RED PA0
#define LED_SYNC PA0
#define mA_PIN PB3
#define V_RS485 PB12
#define V_SS5 PB12
#endif

#ifdef V2
#define	LED_RED PA10
#define LED_SYNC PA10
#define mA_PIN PB3
#define V_RS485 PA1
#define V_SS5 PA1
#endif

#ifdef V3
#define	LED_RED PA9
#define LED_SYNC PA9
#define AI2_PIN PA10
#define AI1_PIN PA15
#define V_SS3 PB5
#define V_SS5 PA1
#define V_RS485 PA1
#define ABAT PB3
#endif

#endif
