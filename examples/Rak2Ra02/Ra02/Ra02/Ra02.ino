#include <LoRa.h>
#include <SPI.h>
int counter = 0;
//Ra02 - ESP32
#define SCK 18   //  SX1278's SCK
#define MISO 19  //  SX1278's MISO
#define MOSI 23  //  SX1278's MOSI
#define SS 5     //  SX1278's CS
#define RST 14   //  SX1278's RESET
#define DI0 2    //  SX1278's IRQ(Interrupt Request)
#define BAND 433E6

unsigned int counter = 0;

void setup() {
  delay(10000);

  Serial.begin(9600);
  while (!Serial) {
    delay(1);
  }

  randomSeed(analogRead(0));
  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DI0);


  if (!LoRa.begin(433000000)) {
    Serial.println("Starting LoRa-Receiver failed!");
    while (1) {
      delay(1);
    };
  } else {
    Serial.println("Starting LoRa-Receiver succeed!");
  }

  LoRa.setPreambleLength(8);
  LoRa.setSpreadingFactor(12);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setCodingRate4(5);
  LoRa.setTxPower(17);
  LoRa.onReceive(onReceive);
  LoRa.receive();
  delay(5000);
}

void loop() {
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.endPacket();
  delay(3000);
}


void onReceive(int packetSize) {
  unsigned int i = 0;

  // received a packet
  Serial.print("Received packet: ");
  Serial.print(counter++);
  Serial.print(' ');
  Serial.print("Paketgroesse: ");
  Serial.print(packetSize);  // print RSSI of packet
  Serial.print(" With RSSI: ");
  Serial.println(LoRa.packetRssi());
  Serial.print("available:");
  Serial.println(LoRa.available());

  // read packet
  for (i = 0; i < packetSize; i++) {
    Serial.print((char)LoRa.read());
  }
}