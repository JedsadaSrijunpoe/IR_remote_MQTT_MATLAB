#include <IRremote.hpp>

#define IR_RECEIVE_PIN 5

void setup()
{
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN); // Start the receiver
}

void loop() {
  if (IrReceiver.decode()) {

      Serial.print("Code: ");
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Decoded to HEX
      
      IrReceiver.printIRResultRawFormatted(&Serial, true); // Print raw timing data

      Serial.write(13); // CR
      Serial.write(10); // LF

      IrReceiver.resume(); // Enable receiving of the next value
  }
}