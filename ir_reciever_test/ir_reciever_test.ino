#include <IRremote.hpp>

#define IR_RECEIVE_PIN 5
#define led1 22

#define code1 0xE916FF00
#define code2 0xB24DFF00

#define LED_OFF HIGH // active-low
#define LED_ON LOW

void setup()
{
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN); // Start the receiver
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LED_OFF);
}

void loop() {
  if (IrReceiver.decode()) {
      //int result = IrReceiver.decodedIRData.decodedRawData;
      Serial.print("Code: ");
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      
      IrReceiver.printIRResultRawFormatted(&Serial, true);
      //Serial.println("end_raw_data");
      Serial.write(13);
      Serial.write(10);

      //IrReceiver.printIRResultRawFormatted(&Serial, true);
      //IrReceiver.printIRResultShort(&Serial); // optional use new print version
      
      // if (result == code1) { // ถ้าค่าที่ส่งมาตรงกับ ค่าในตัวแปร code1 ให้ทำใน ปีกกา if
      //   Serial.println("LED ON");
      //   digitalWrite(led1, LED_ON);
      // }
      // if (result == code2) { // ถ้าค่าที่ส่งมาตรงกับ ค่าในตัวแปร code2 ให้ทำใน ปีกกา if
      //   Serial.println("LED OFF");
      //   digitalWrite(led1, LED_OFF);
      // }

      IrReceiver.resume(); // Enable receiving of the next value
  }
}