#include <Adafruit_NeoPixel.h>
 
 /////////////////インクルードファイル/////////////////////
 #ifdef __AVR__
   #include <avr/power.h>
 #endif
 
 /////////////////定義/////////////////////
 #define LEDLINE1     5
 #define LEDLINE2     6
 #define LEDLINE3     10
 #define DEBUG_LED    2
 #define PSW1         11
 #define PSW2         12

 #define LEDLINE1_NUM 75
 #define LEDLINE2_NUM 100
 #define LEDLINE3_NUM 125
 
Adafruit_NeoPixel ledline1 = Adafruit_NeoPixel(LEDLINE1_NUM, LEDLINE1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledline2 = Adafruit_NeoPixel(LEDLINE2_NUM, LEDLINE2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledline3 = Adafruit_NeoPixel(LEDLINE3_NUM, LEDLINE3, NEO_GRB + NEO_KHZ800);
void ledShow( void ){
   ledline1.show();
   ledline2.show();
   ledline3.show();
 }
void colorWipe(uint32_t c,uint16_t wait) {
   for(uint16_t i=0; i<ledline1.numPixels(); i++) {
     ledline1.setPixelColor(i, c);
     ledline1.show();
     delay(wait);
   }
   for(uint16_t i=0; i<ledline2.numPixels(); i++) {
    ledline2.setPixelColor(i, c);
    ledline2.show();
    delay(wait);
  }
  for(uint16_t i=0; i<ledline3.numPixels(); i++) {
    ledline3.setPixelColor(i, c);
    ledline3.show();
    delay(wait);
  }
 }
void fadeChange(uint8_t R, uint8_t G, uint8_t B, uint16_t wait){
   boolean R_flg = true, G_flg = true, B_flg = true;
   ledline1.setBrightness(255);
   ledline2.setBrightness(255);
   ledline3.setBrightness(255);
 
   while( (R_flg==true) || (G_flg==true) || (B_flg==true) ){//全ての値が目標値に到達していなかったら
      uint32_t color = ledline1.getPixelColor(0);
      
      uint8_t now_R1 = ( color >> 16 );
      uint8_t now_G1 = ( color >> 8 );
      uint8_t now_B1 = ( color );

      uint8_t now_R2 = ( color >> 16 );
      uint8_t now_G2 = ( color >> 8 );
      uint8_t now_B2 = ( color );

      uint8_t now_R3 = ( color >> 16 );
      uint8_t now_G3 = ( color >> 8 );
      uint8_t now_B3 = ( color );

      int16_t diff_R1;
      int16_t diff_G1;
      int16_t diff_B1;

      int16_t diff_R2;
      int16_t diff_G2;
      int16_t diff_B2;

      int16_t diff_R3;
      int16_t diff_G3;
      int16_t diff_B3;
      for(int16_t i = 0; i < ledline1.numPixels(); i++ ){//するまでやる

        diff_R1 = R - now_R1;
        diff_G1 = G - now_G1;
        diff_B1 = B - now_B1;
        
        if( diff_R1 > 0 ){//目標値のほうがが大きいので明るさを増やす
          now_R1++;
        }
        else if( diff_R1 < 0 ){//目標値の方が小さいので明るさを減らす
          now_R1--;
        }
        else if( diff_R1 == 0 ){//目標値と現在の明るさが一致しているのでOK
          R_flg = false;

        }
    
        if( diff_G1 > 0 ){
          now_G1++;
        }
        else if( diff_G1 < 0 ){
          now_G1--;
        }
        else if( diff_G1 == 0 ){
          G_flg = false;
        }
    
        if( diff_B1 > 0 ){
          now_B1++;
        }
        else if( diff_B1 < 0 ){
          now_B1--;
        }
        else if( diff_B1 == 0 ){
          B_flg = false;
        }
        ledline1.setPixelColor(i, now_R1, now_G1, now_B1);
      }
      for(int16_t i = 0; i < ledline2.numPixels(); i++ ){//するまでやる
        diff_R2 = R - now_R2;
        diff_G2 = G - now_G2;
        diff_B2 = B - now_B2;
        
        if( diff_R2 > 0 ){//目標値のほうがが大きいので明るさを増やす
          now_R2++;
        }
        else if( diff_R2 < 0 ){//目標値の方が小さいので明るさを減らす
          now_R2--;
        }
        else if( diff_R2 == 0 ){//目標値と現在の明るさが一致しているのでOK
          R_flg = false;

        }
    
        if( diff_G2 > 0 ){
          now_G2++;
        }
        else if( diff_G2 < 0 ){
          now_G2--;
        }
        else if( diff_G2 == 0 ){
          G_flg = false;
        }
    
        if( diff_B2 > 0 ){
          now_B2++;
        }
        else if( diff_B2 < 0 ){
          now_B2--;
        }
        else if( diff_B2 == 0 ){
          B_flg = false;
        }
        ledline2.setPixelColor(i, now_R2, now_G2, now_B2);
      }
      for(int16_t i = 0; i < ledline3.numPixels(); i++ ){//するまでやる
        
        diff_R3 = R - now_R3;
        diff_G3 = G - now_G3;
        diff_B3 = B - now_B3;
        
        if( diff_R3 > 0 ){//目標値のほうがが大きいので明るさを増やす
          now_R3++;
        }
        else if( diff_R3 < 0 ){//目標値の方が小さいので明るさを減らす
          now_R3--;
        }
        else if( diff_R3 == 0 ){//目標値と現在の明るさが一致しているのでOK
          R_flg = false;

        }
    
        if( diff_G3 > 0 ){
          now_G3++;
        }
        else if( diff_G3 < 0 ){
          now_G3--;
        }
        else if( diff_G3 == 0 ){
          G_flg = false;
        }
    
        if( diff_B3 > 0 ){
          now_B3++;
        }
        else if( diff_B3 < 0 ){
          now_B3--;
        }
        else if( diff_B3 == 0 ){
          B_flg = false;
        }
        ledline3.setPixelColor(i, now_R3, now_G3, now_B3);
      }
     ledline1.show();
     ledline2.show();
     ledline3.show();
     delay(wait);
   }
 }
void fadeAllOff(uint16_t wait){
   for(signed int k=255; k>=0; k=k-10){
     ledline1.setBrightness(k);
     ledline2.setBrightness(k);
     ledline3.setBrightness(k);
     ledline1.show();
     ledline2.show();
     ledline3.show();
     delay(wait);
   }
   for(signed int i=0; i<ledline1.numPixels(); i++){
     ledline1.setPixelColor(i, 0, 0, 0);
   }
   for(signed int i=0; i<ledline2.numPixels(); i++){
    ledline2.setPixelColor(i, 0, 0, 0);
  }
  for(signed int i=0; i<ledline3.numPixels(); i++){
    ledline3.setPixelColor(i, 0, 0, 0);
  }
   ledline1.setBrightness(255);
   ledline2.setBrightness(255);
   ledline3.setBrightness(255);
   ledline1.show();
   ledline2.show();
   ledline3.show();
 }
void patAllOn(uint8_t r, uint8_t g, uint8_t b){
  for(uint16_t a=0; a<ledline1.numPixels(); a++){
    ledline1.setPixelColor(a, r, g, b);
  }
  for(uint16_t a=0; a<ledline2.numPixels(); a++){
    ledline2.setPixelColor(a, r, g, b);
  }
  for(uint16_t a=0; a<ledline3.numPixels(); a++){
    ledline3.setPixelColor(a, r, g, b);
  }
  Serial.println("patAllOn");
  ledline1.setBrightness(255);
  ledline2.setBrightness(255);
  ledline3.setBrightness(255);
  ledShow();
}
void patAllOff( void ){
  for(int a=0; a<ledline1.numPixels(); a++){
    ledline1.setPixelColor(a, 0, 0, 0);
  }
  for(int a=0; a<ledline2.numPixels(); a++){
    ledline2.setPixelColor(a, 0, 0, 0);
  }
  for(int a=0; a<ledline3.numPixels(); a++){
    ledline3.setPixelColor(a, 0, 0, 0);
  }
  ledShow();
}
void patOffLine(uint8_t line_num){//列単位で消灯します
  int16_t i = 0;
  if(line_num==1){
    for(i=0; i<ledline1.numPixels(); i++){
      ledline1.setPixelColor(i, 0, 0, 0);
    }
  }
  else if(line_num==2){
    for(i=0; i<ledline2.numPixels(); i++){
      ledline2.setPixelColor(i, 0, 0, 0);
    }
  }
  else if(line_num==3){
    for(i=0; i<ledline3.numPixels(); i++){
      ledline3.setPixelColor(i, 0, 0, 0);
    }
  }
  ledShow();
}
void patOnLine(uint8_t r, uint8_t g, uint8_t b, uint8_t column_num){//列単位で点灯します。
  int16_t i = 0;
  if(column_num==1){
    for(i=0; i<ledline1.numPixels(); i++){
      ledline1.setPixelColor(i, r, g, b);
    }
  }
  else if(column_num==2){
    for(i=0; i<ledline2.numPixels(); i++){
      ledline2.setPixelColor(i, r, g, b);
    }
  }
  else if(column_num==3){
    for(i=0; i<ledline3.numPixels(); i++){
      ledline3.setPixelColor(i, r, g, b);
    }
  }
  ledShow();
}
void fadeChangeBrightness(uint8_t now_brightness, uint8_t brightness, uint16_t wait){
  if( (brightness - now_brightness) > 0 ){
    for(int i=now_brightness+1; i <= brightness; i++){
      ledline1.setBrightness(i);
      ledline2.setBrightness(i);
      ledline3.setBrightness(i);
      ledShow();
      delay(wait);
    }
  }
  else if( (brightness - now_brightness) < 0 ){
    for(int i=now_brightness; i >= brightness; i--){
      ledline1.setBrightness(i);
      ledline2.setBrightness(i);
      ledline3.setBrightness(i);
      ledShow();
      delay(wait);
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  pinMode(PSW1, INPUT_PULLUP);
   pinMode(PSW2, INPUT_PULLUP);
   pinMode(DEBUG_LED, OUTPUT);
   Serial.begin(115200);
   ledline1.begin();
   ledline2.begin();
   ledline3.begin();
   ledline1.show(); // Initialize all pixels to 'off'
   ledline2.show(); // Initialize all pixels to 'off'
   ledline3.show(); // Initialize all pixels to 'off'
   Serial.println("ok");
   fadeChange(255,0,0,5);
   fadeAllOff(10);
   patAllOn(255,255,255);
   delay(500);
   patAllOff();
   patOnLine(255,0,0,1);
   patOnLine(0,255,0,2);
   patOnLine(0,0,255,3);
   delay(500);
   patOffLine(3);
   delay(500);
   patOffLine(2);
   delay(500);
   fadeChangeBrightness(255,10,1);
   delay(500);
   fadeChangeBrightness(10,255,1);
   delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:

}
