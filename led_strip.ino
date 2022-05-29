
#include <FastLED_NeoPixel.h>

// LED MAX between 0 to 255
#define MAX 50

FastLED_NeoPixel<10, 6, NEO_GRB> front;     
FastLED_NeoPixel<20, 7, NEO_GRB> left; 
FastLED_NeoPixel<20, 8, NEO_GRB> right;      
     

void setup() {
  
	front.begin();  
	front.setBrightness(MAX);

  right.begin();  
  right.setBrightness(MAX);

  left.begin(); 
  left.setBrightness(MAX);
}

float t=0;
void loop() {
  if(t<6.28)
    t+=0.01;
  else
    t=0;
 
	front.setPixelColor((int)(((sin(t)+1)*2.5)), front.Color(255, 255, 255)); 
	front.show();
  
  right.setPixelColor((int)(((sin(t)+1)*7.5)), right.Color(255, 255, 255));  
  right.show();

  left.setPixelColor((int)(((sin(t)+1)*7.5)), left.Color(255, 255, 255));  
  left.show();
 
	delay(1); //in milliseconds

  front.setPixelColor((int)(((sin(t)+1)*2.5)), front.Color(0, 0, 0));  
  front.show();
  
  right.setPixelColor((int)(((sin(t)+1)*7.5)), right.Color(0, 0, 0));  
  right.show();

  left.setPixelColor((int)(((sin(t)+1)*7.5)), left.Color(0, 0, 0)); 
  left.show();
  
}
