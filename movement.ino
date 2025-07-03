#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_FAST | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_DEV_0);

int x=0,y=2;
int xPin = A1;
int yPin = A0;
int xVal, yVal;

void setup() {

  u8g.setFont(u8g_font_unifont);
  u8g.setColorIndex(1);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  Serial.begin(9600);
}

void loop() {
 xVal =analogRead(xPin);
 yVal = analogRead(yPin);

// 500-700


 u8g.firstPage();
 do{
    inputSys();
      draw();
 } while( u8g.nextPage() );

}
void inputSys(){
  if(xVal > 700 && x !=124){
    x++;
  }
  if(xVal < 500 && x !=0){
    x--;
  }
  if(yVal > 700 && y !=62){
    y++;
  }
  if(yVal < 500 && y !=2){
    y--;
  }
}

void draw(){
  u8g.drawStr(x,y,".");
}