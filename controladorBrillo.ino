/*
  APDS9960 - Color Sensor

  This example reads Color data from the on-board APDS9960 sensor of the
  Nano 33 BLE Sense and prints the color RGB (red, green, blue) values
  to the Serial Monitor once a second.

  The circuit:
  - Arduino Nano 33 BLE Sense

  This example code is in the public domain.
*/

#include <Arduino_APDS9960.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor.");
  }
}

void loop() {

  // check if a color reading is available
  while (! APDS.colorAvailable()) {
    delay(5);
  }
  int r, g, b, a;

  // read the color
  APDS.readColor(r, g, b);
  
  a = (r + g + b) / 3;
  Serial.println(a);

  // wait a bit before reading again
  delay(3000);
}