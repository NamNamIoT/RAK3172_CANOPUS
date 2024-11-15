#ifndef RAK3172_CANOPUS_H
#define RAK3172_CANOPUS_H
#endif

#define V3_4

#ifdef RAK3172_CANOPUS_H

/* COMMON */
#define LED_RECV PB2 //LED_BLUE
#define LED_SEND PA8 //LED_YELLOW
#define I2C_SDA PA11
#define I2C_SCL PA12
#define Volt_PIN PB4

/* V1 */
#ifdef V1
#define LED_SYNC PA0 //LED_RED
#define mA_PIN PB3
#define V_SS3 PB5
#define V_SS5 PB12
#endif

/* V2 */
#ifdef V2
#define LED_SYNC PA10 //LED_RED
#define mA_PIN PB3
#define V_SS3 PB5
#define V_SS5 PA1
#endif

/* V3 */
#ifdef V3
#define LED_SYNC PA9 //LED_RED
#define AI2_PIN PA10
#define AI1_PIN PA15
#define V_SS3 PB5
#define V_SS5 PA1
#define ABAT PB3
#endif

/* V3_4 */
#ifdef V3_4
#define LED_SYNC PA9 //LED_RED
#define AI2_PIN PA10
#define AI1_PIN PA15
#define V_SS3 PB5
#define V_SS5 PA1
#define V_SS12 PA0
#define ABAT PB3
#endif

void init_io();
void enable_Vrs485();
void enable_Vss3();
void enable_Vss5();
void enable_Vss12();
void disable_Vrs485();
void disable_Vss3();
void disable_Vss5();
void disable_Vss12();
void save_power();
#endif