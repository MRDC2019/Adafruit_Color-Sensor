#ifndef SENSOR_H
#define SENSOR_H

#include "Adafruit_TCS34725.h"
#include <Wire.h>
#include "Adafruit_VCNL4010.h"

#include "Arduino.h"

class Sensor{
  public:
    void initialize();
  private:
    -uint16_t r,g,b,c,colorTemp,lux;
    -Adafruit_VCNL4010 vcnl;
    -Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
  };

#endif
