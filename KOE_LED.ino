#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PWMPIN        10
#define NUMPIXELS     19
#define DEBUG_LED      2
#define PSW1          11
#define PSW2          12



Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS,PWMPIN, NEO_GRB + NEO_KHZ800);

int delayval = 10;
int red=255, blue=255, green=255;

void ifendif(){
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
}

void setup() {
  pinMode(PSW1,INPUT_PULLUP);
  pinMode(PSW2,INPUT_PULLUP);
  pinMode(DEBUG_LED,OUTPUT);
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.setPixelColor(, pixels.Color(0,0,0)); // Moderately bright green color.
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(1000);
}

void loop() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
    
    for(green; green>0; green--){//only red
      blue--;
      pixels.setPixelColor(0, pixels.Color(red,blue,green)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
    for(red; red>0; red--){//only blue
      blue++;
      pixels.setPixelColor(0, pixels.Color(red,blue,green)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
    for(blue; blue>0; blue--){//only green
      green++;
      pixels.setPixelColor(0, pixels.Color(red,blue,green)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
    for(red; red<255; red++){//green+red
      pixels.setPixelColor(0, pixels.Color(red,blue,green)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
    for(blue; blue<255; blue++){//red+blue
      green--;
      pixels.setPixelColor(0, pixels.Color(red,blue,green)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
    for(red; red>0; red--){//blue+green
      blue++;
      pixels.setPixelColor(0, pixels.Color(red,blue,green)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
    for(red; red<255; red++){//white
      pixels.setPixelColor(0, pixels.Color(red,blue,green)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
    delay(delayval); // Delay for a period of time (in milliseconds).
}
