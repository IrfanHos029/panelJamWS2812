#include <Adafruit_NeoPixel.h>
#define pin D6

const int led_row=5;
const int led_col=20;
const int module=led_col*led_row;

Adafruit_NeoPixel strip(module, pin, NEO_GRB + NEO_KHZ800);

byte data_col[led_col];
void setup() {
   strip.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void led_from_pixel(byte row,byte col)
{
  int a=0;

  if(row%2==0)
  {
    a = ((row+1)*led_col)-1-col;
  }
  else
  {
    a = (row*led_col)+col;
  }
}





void pixel_build(String s)
{
  int c=0;
  for(int a=0;a<s.length();a++)
  {
    int idx_char = s[a] - 32;
    int idx_col=4;
    for(int i=0;i<8;i++)
    {
      byte b = pgm_read_byte(&kata[idx_char*8+1]);
      data_col[c]=b;
      c++;
      if(b==0&&i>2)
      {
        break;
      }
    }
  }
}



void pixel_show(byte red,byte green,byte blue)
{
  for(byte a=0;a<8;a++)
  {
    for(int c=0;c<led_col;c++)
    {
      byte b = bitRead(data_col[c],a);
      byte r=7-a;
      int index_led=led_from_pixel(r,c);
      if(b==1)
      {
        strip.setPixelColor(index_led,red,green,blue);
      }
      else
      {
        strip.setPixelColor(index_led,red,green,blue);
      }
    }
  }
  strip.show();
}
