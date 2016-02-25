#include <Wire.h>
#include "Adafruit_TCS34725.h"
#define redpin 3
#define greenpin 5
#define bluepin 6
#define commonAnode true

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void opengatered(){}
void opengategreen(){}
void opengateblue(){}
void opengatewhite(){}

void setup() {
Serial.begin(9600);
  Serial.println("Color View Test!");

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
  
  // use these three pins to drive an LED
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  

}

void loop() {
   uint16_t r, g, b, c;
   tcs.setInterrupt(false);      // turn on LED

  delay(60);  // takes 50ms to read 
   
   tcs.getRawData(&r, &g, &b, &c);
   tcs.setInterrupt(true);  // turn off LED

   if(r > g && r > b && r > c){
      opengatered();
   }
   if(g > r && g > b && g > c){
      opengategreen();
   }
   if(b > g && b > r && b > c){
      opengateblue();
   }
   if(c > g && c > b && c > r){
      opengatewhite();
   }
}
