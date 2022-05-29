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
  if(t<6.28)
    t+=0.01;
  else
    t=0;
 
  io.setPixelColor((int)(((sin(t)+1)*2.5)), io.Color(255, 255, 255)); 
  io.show();
  
  right.setPixelColor((int)(((sin(t)+1)*7.5)), right.Color(255, 255, 255));  
  right.show();

  left.setPixelColor((int)(((sin(t)+1)*7.5)), left.Color(255, 255, 255));  
  left.show();

  skull.setPixelColor((int)(((sin(t)+1)*5)), skull.Color(255, 255, 255));  
  skull.show();
 
  delay(1); //in milliseconds

  io.setPixelColor((int)(((sin(t)+1)*2.5)), io.Color(0, 0, 0));  
  io.show();
  
  right.setPixelColor((int)(((sin(t)+1)*7.5)), right.Color(0, 0, 0));  
  right.show();

  left.setPixelColor((int)(((sin(t)+1)*7.5)), left.Color(0, 0, 0)); 
  left.show();

  skull.setPixelColor((int)(((sin(t)+1)*5)), skull.Color(0, 0, 0));  
  skull.show();
  
}
