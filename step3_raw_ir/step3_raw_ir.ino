#include <Wire.h>
#include "MAX30105.h"

MAX30105 particleSensor;

void setup() {
  Serial.begin(115200);
  delay(1500);
  Wire.begin(21, 22);

  if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
    Serial.println("begin failed");
    for (;;);
  }

  // CHANGE 1: deleted the Part ID lines, since text confuses the plotter
  particleSensor.setup(0x3F, 4, 2, 100, 411, 4096);
}

void loop() {
  // CHANGE 2: deleted the Temp and write pointer prints
  Serial.print("IR:");                       // label for the plotter legend
  Serial.println(particleSensor.getIR());    // one number per line
  // CHANGE 3: deleted delay(500), which made the plot slow and choppy
}