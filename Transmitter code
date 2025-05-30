#include <SPI.h>
#include <RF24.h>

RF24 radio(4, 5);  // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  String message = "Drone telemetry: Alt=320m, Spd=35km/h";
  radio.write(&message, message.length() + 1);
  Serial.println("Sent: " + message);
  delay(2000);
}
