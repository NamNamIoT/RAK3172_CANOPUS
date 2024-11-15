void setup() {
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {
  Serial1.println("ON");
  Serial.println("send on");
  delay(1000);


  Serial1.println("OFF");
  Serial.println("send off");
  delay(1000);
}