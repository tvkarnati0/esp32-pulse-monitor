#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println("Display failed");
    for (;;);
  }
  // step 3: wipe the screen's memory
  display.clearDisplay();

  // step 4: big white text at the top left
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  // step 5: write the first line
  display.println("HELLO");

  // step 6: smaller text, lower on the screen
  display.setTextSize(1);
  display.setCursor(0, 30);
  display.println("Pulse monitor");

  // step 7: send everything to the screen
  display.display();
}



void loop() {

}