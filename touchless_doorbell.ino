#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 10
//#define CLOCK_PIN 13

CRGB leds[NUM_LEDS];

const int IR = 7, relay = 9;
int sense = 0, lastSate = 0, count = 0;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(IR,INPUT);
  pinMode(relay,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sense = digitalRead( IR );
  Serial.println(count);
  if(sense == 0)
  {
    
    if( count > 300)
    {
      //count = 0;
      leds[0] = CRGB(0,100,0);
      FastLED.show();
      digitalWrite(relay, HIGH);
    }
    else
    {
      leds[0] = CRGB(0,0,100);
      FastLED.show();
      count ++;
    }
  }
  else
  {
    count = 0;
    digitalWrite(relay, LOW);
    leds[0] = CRGB(0,0,0);
    FastLED.show();
  }
  

}
