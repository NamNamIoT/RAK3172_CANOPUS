#define VSS_PIN PB5
#define mA_PIN PB3
#define Volt_PIN PB4
#define PWR_ON LOW

void setup() {
  Serial.begin(115200);
  Serial.println("Canopus Analog Example");
  Serial.println("------------------------------------------------------");
  pinMode(VSS_PIN, OUTPUT);
  digitalWrite(VSS_PIN, PWR_ON);
  analogReadResolution(12);
}

void loop() {
  int AI = (float)analogRead(mA_PIN) * 3300 / 100 / 4096;  //Get value 4-20mA
  Serial.printf("\nAI = %dmA\r\n", AI);                   // print value 4-20mA

  int AV = (float)analogRead(Volt_PIN) * 3300 / 4096 * 4.3;  //Get value 0-10V
  Serial.printf("AV = %dmV\r\n", AV);                       // print value 0-10V
  delay(1000);
}
