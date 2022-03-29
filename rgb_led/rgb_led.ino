#include <Adafruit_NeoPixel.h>
 
#define LEDPIN 2
#define NUMLED 1
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMLED, LEDPIN, NEO_RGB + NEO_KHZ800);
 
typedef struct {
 int r;
 int g;
 int b;
} RGB;

void setLED(RGB rgb) {
  strip.setPixelColor(0, strip.Color(rgb.r, rgb.g, rgb.b));
  strip.show();
}

void setup() {
  strip.begin();
}

void loop() {
  setLED(RGB{0, 255, 0});
  delay(100);
  setLED(RGB{255, 0, 0});
  delay(100);
}
