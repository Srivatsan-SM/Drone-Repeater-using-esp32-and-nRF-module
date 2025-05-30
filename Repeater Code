#include <SPI.h>
#include <RF24.h>

RF24 radio(4, 5);  // CE, CSN
const byte repeaterAddress[6] = "00001";
const byte forwardAddress[6] = "00002";  // Destination address

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, repeaterAddress);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char received[64] = {0};
    radio.read(&received, sizeof(received));
    Serial.print("Received and forwarding: ");
    Serial.println(received);

    // Switch to TX to forward
    radio.stopListening();
    radio.openWritingPipe(forwardAddress);
    radio.write(&received, strlen(received) + 1);
    radio.startListening();
  }
}
