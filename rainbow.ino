
#include <FastLED_NeoPixel.h>

// LED MAX between 0 to 255
#define STRIP_MAX 20
#define SKULL_MAX 255

#define DATA_PIN_IO 6
#define DATA_PIN_LEFT 7
#define DATA_PIN_RIGHT 8
#define DATA_PIN_SKULL 9

#define NUM_LEDS_IO 10
#define NUM_LEDS_LEFT 20
#define NUM_LEDS_RIGHT 20
#define NUM_LEDS_SKULL 15

FastLED_NeoPixel<NUM_LEDS_IO, DATA_PIN_IO, NEO_GRB> io;     
FastLED_NeoPixel<NUM_LEDS_LEFT, DATA_PIN_LEFT, NEO_GRB> left; 
FastLED_NeoPixel<NUM_LEDS_RIGHT, DATA_PIN_RIGHT, NEO_GRB> right;
FastLED_NeoPixel<NUM_LEDS_SKULL, DATA_PIN_SKULL, NEO_GRB> skull;
     

void setup() {
  
  io.begin();  
  io.setBrightness(STRIP_MAX);

  right.begin();  
  right.setBrightness(STRIP_MAX);

  left.begin(); 
  left.setBrightness(STRIP_MAX);

  skull.begin(); 
  skull.setBrightness(SKULL_MAX);

}

float t=0;
void loop() {
  if(t<65536)
    t+=2000;
  else
    t=1;
 
  for (unsigned int i = 0; i < io.numPixels(); i++) {
      unsigned long pixelHue = (t*io.numPixels()/NUM_LEDS_IO)+(i * 65536UL / io.numPixels()); 
      io.setPixelColor(i, io.gamma32(io.ColorHSV(pixelHue))); 
      io.show();
    }
  for (unsigned int i = 0; i < left.numPixels(); i++) {
      unsigned long pixelHue = (t*left.numPixels()/NUM_LEDS_LEFT)+(i * 65536UL / left.numPixels()); 
      left.setPixelColor(i, left.gamma32(left.ColorHSV(pixelHue))); 
      left.show();
    }
  for (unsigned int i = 0; i < skull.numPixels(); i++) {
      unsigned long pixelHue = (t*right.numPixels()/NUM_LEDS_RIGHT)+(i * 65536UL / right.numPixels()); 
      right.setPixelColor(i, right.gamma32(right.ColorHSV(pixelHue))); 
      right.show();
    }
  for (unsigned int i = 0; i < skull.numPixels(); i++) {
      unsigned long pixelHue = (t*skull.numPixels()/NUM_LEDS_SKULL)+(i * 65536UL / skull.numPixels()); 
      skull.setPixelColor(i, skull.gamma32(skull.ColorHSV(pixelHue))); 
      skull.show();
    }
 
  delay(1); //in milliseconds

}
