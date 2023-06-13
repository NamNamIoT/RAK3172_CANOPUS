#include <Arduino.h>
#include <Wire.h>
#include <ArtronShop_BH1750.h>
#define VSS_PIN PB5
#define PWR_ON LOW
ArtronShop_BH1750 bh1750(0x23, &Wire); // Non Jump ADDR: 0x23, Jump ADDR: 0x5C

void setup() {
  Serial.begin(115200);
  Serial.print("\r\n************RAK3172_CANOPUS**************");
  pinMode(VSS_PIN, OUTPUT);
  digitalWrite(VSS_PIN, PWR_ON);
  Wire.begin();
  while (!bh1750.begin()) {
    Serial.println("BH1750 not found !");
    delay(1000);
  }
}

void loop() {
  Serial.print("Light: ");
  Serial.print(bh1750.light());
  Serial.print(" lx");
  Serial.println();
  delay(1000);
}
