#ifndef RAK3172_CANOPUS_H
#define RAK3172_CANOPUS_H

#ifdef RAK3172_CANOPUS_H

#define	LED_SEND PA8
#define LED_RECV PB2
#define VSS_PIN PB5
#define I2C_SDA PA11
#define I2C_SCL PA12
#define PWR_ON LOW
#define PWR_OFF HIGH
#define Volt_PIN PB4
#ifdef V1
#define LED_SYNC PA0
#define mA_PIN PB3
#define VRS_485 PB12
#endif

#ifdef V2
#define LED_SYNC PA10
#define mA_PIN PB3
#define VRS_485 PA1
#endif

#ifdef V3
#define LED_SYNC PA10
#define mA_PIN PA15
#define VRS_485 PA1
#endif

#endif
