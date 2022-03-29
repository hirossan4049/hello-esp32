#include <Adafruit_NeoPixel.h>

#define LEDPIN 2
#define NUMLED 2
#define POWERPIN 4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMLED, LEDPIN, NEO_RGB + NEO_KHZ800);

typedef struct {
  int r;
  int g;
  int b;
} RGB;

RGB rgb_hex2dec(String hexstr){
  RGB rgb;
  long val = strtol(&hexstr[1], NULL, 16);
  rgb.r = (int) (val >> 16 & 0xff);
  rgb.g = (int) (val >> 8 & 0xff);
  rgb.b = (int) (val & 0xff);

  return rgb;
}

void setLED(RGB rgb) {
  strip.setPixelColor(0, strip.Color(rgb.r, rgb.g, rgb.b));
  strip.show();
}

void setup() {
  Serial.begin(115200);
  
  pinMode(POWERPIN, OUTPUT);
  digitalWrite(POWERPIN, HIGH);
  strip.begin();
  strip.setBrightness(255);
}

void loop() {
  strip.setPixelColor(0, strip.Color(255, 0, 0));
  strip.show(); 
  delay(100);
  strip.setPixelColor(0, strip.Color(0, 255, 0));
  strip.show();
  Serial.println("show");
  delay(100);

}
