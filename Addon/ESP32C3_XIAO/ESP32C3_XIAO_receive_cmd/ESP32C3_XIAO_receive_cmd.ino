#include <HardwareSerial.h>
#define LED_PIN 10

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  delay(3000);
  Serial.println("Hello");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (Serial1.available()) {
    String data = Serial1.readStringUntil('\n');
    if (data.indexOf("ON") != -1){
      Serial.println("Receive ON");
      digitalWrite(LED_PIN, HIGH);
    } else if (data.indexOf("OFF") != -1){
      Serial.println("Receive OFF");
      digitalWrite(LED_PIN, LOW);
    }
  }
}