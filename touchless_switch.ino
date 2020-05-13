#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 10
//#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];

const int IR = 7, relay = 9;
int sense = 0, lastSate = 0, count = 0;
bool relayState = 0;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(IR,INPUT);
  pinMode(relay,OUTPUT);
  leds[0] = CRGB(100,0,0);
  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  sense = digitalRead( IR );
  relayState = digitalRead(relay);
  if(sense == 0)
  {
    if( count < 300)
    {
      leds[0] = CRGB(0,0,100);
      FastLED.show();
      count ++;
    }
    else if( count == 300 )
    {
      digitalWrite(relay, relayState ^ 1);
      count ++;
    }
    else
    {
      if(relayState == 0)
      {
        leds[0] = CRGB(100,0,0);
        FastLED.show();
      }
      else
      {
        leds[0] = CRGB(0,100,0);
        FastLED.show();
      }
    }
  }
  else
  {
    count = 0;
    if(relayState == 0)
      {
        leds[0] = CRGB(100,0,0);
        FastLED.show();
      }
      else
      {
        leds[0] = CRGB(0,100,0);
        FastLED.show();
      }
  }
}
