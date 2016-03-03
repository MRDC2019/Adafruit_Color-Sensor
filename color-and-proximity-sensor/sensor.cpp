#include "Sensor.h"
#include "Aduino.h"

#include "Adafruit_TCS34725.h"
#include <Wire.h>
#include "Adafruit_VCNL4010.h"

Sensor :: initialize() {
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);

  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - "); //alternative color measurement
  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
  Serial.print("Ambient: "); Serial.println(vcnl.readAmbient()); //nears a value of 0 with an object that's close
  Serial.print("Proimity: "); Serial.println(vcnl.readProximity()); //increases exponentially when an object nears sensor
  delay(100);
}
