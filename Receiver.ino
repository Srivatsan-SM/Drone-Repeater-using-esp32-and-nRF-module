#include <SPI.h>
#include <RF24.h>

RF24 radio(4, 5);  // CE, CSN
const byte address[6] = "00002";  // Must match repeater's forwardAddress

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char buffer[64] = {0};
    radio.read(&buffer, sizeof(buffer));
    Serial.print("Base Station Received: ");
    Serial.println(buffer);
  }
}
