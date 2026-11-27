#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
}

void loop() {
  Serial.println("Scanning...");
  for (byte addr = 1; addr < 127; addr++) {   // first address, then the stop value
    Wire.beginTransmission(addr);              // which address are we trying?
    byte result = Wire.endTransmission();               // returns 0 when a device answers
    if (result == 0) {
      Serial.print("Found device at 0x");
      Serial.println(addr, HEX);               // print the address in hex
    }
  }
  Serial.println("Done");
  Serial.println("Done");
  delay(3000);
}