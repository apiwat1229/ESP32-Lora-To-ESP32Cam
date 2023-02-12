#include <SPI.h>
#include <LoRa.h> //https://github.com/sandeepmistry/arduino-LoRa


void setup() {
  Serial.begin(115200);
  Serial.println("LoRa Receiver");
  pinMode(22, OUTPUT);
  LoRa.setPins(18, 14, 26);
  if (!LoRa.begin(863E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    digitalWrite(22, HIGH);
    // received a packet
    // Serial.print("Received packet ");

    // read packet
    while (LoRa.available()) {
      Serial.println((char)LoRa.read());
    }
  digitalWrite(22, LOW);
    // print RSSI of packets
    // Serial.print(" RSSI was: ");
    // Serial.println(LoRa.packetRssi());
  }
  delay(1000);
}