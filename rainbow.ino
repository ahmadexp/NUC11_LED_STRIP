#include <FastLED_NeoPixel.h>

// LED MAX between 0 to 255
#define STRIP_MAX 100
#define SKULL_MAX 255

FastLED_NeoPixel<10, 6, NEO_GRB> io;     
FastLED_NeoPixel<20, 7, NEO_GRB> left; 
FastLED_NeoPixel<20, 8, NEO_GRB> right;
FastLED_NeoPixel<15, 9, NEO_GRB> skull;      
     

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
    t+=1000;
  else
    t=1;
 
  for (unsigned int i = 0; i < io.numPixels(); i++) {
      unsigned long pixelHue = (t*io.numPixels()/10)+(i * 65536UL / io.numPixels()); 
      io.setPixelColor(i, io.gamma32(io.ColorHSV(pixelHue))); 
      io.show();
    }
  for (unsigned int i = 0; i < left.numPixels(); i++) {
      unsigned long pixelHue = (t*left.numPixels()/10)+(i * 65536UL / left.numPixels()); 
      left.setPixelColor(i, left.gamma32(left.ColorHSV(pixelHue))); 
      left.show();
    }
  for (unsigned int i = 0; i < skull.numPixels(); i++) {
      unsigned long pixelHue = (t*right.numPixels()/10)+(i * 65536UL / right.numPixels()); 
      right.setPixelColor(i, right.gamma32(right.ColorHSV(pixelHue))); 
      right.show();
    }
  for (unsigned int i = 0; i < skull.numPixels(); i++) {
      unsigned long pixelHue = (t*skull.numPixels()/10)+(i * 65536UL / skull.numPixels()); 
      skull.setPixelColor(i, skull.gamma32(skull.ColorHSV(pixelHue))); 
      skull.show();
    }
 
  delay(1); //in milliseconds

}
