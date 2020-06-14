/*
 Created by Rui Santos
 
 All the resources for this project:
 http://randomnerdtutorials.com/
*/

#include "LedControl.h"
#include "binary.h"

/*
 DIN connects to pin 12
 CLK connects to pin 11
 CS connects to pin 10 
*/
LedControl lc = LedControl(12, 11, 10, 1);

// delay time between faces
unsigned long delaytime = 1000;

// happy face
byte hf[8] = {B00111100, B01000010, B10100101, B10000001, B10100101, B10011001, B01000010, B00111100};
// neutral face
byte nf[8] = {B00111100, B01000010, B10100101, B10000001, B10111101, B10000001, B01000010, B00111100};
// sad face
byte sf[8] = {B00111100, B01000010, B10100101, B10000001, B10011001, B10100101, B01000010, B00111100};

void setup()
{
  lc.shutdown(0, false);
  // Set brightness to a medium value
  lc.setIntensity(0, 8);
  // Clear the display
  lc.clearDisplay(0);
}

void drawFaces()
{
  // Display sad face
  for (int i = 0; i < 8; ++i)
    lc.setRow(0, i, sf[i]);

  delay(delaytime);

  // Display neutral face
  for (int i = 0; i < 8; ++i)
    lc.setRow(0, i, nf[i]);

  delay(delaytime);

  // Display happy face
  for (int i = 0; i < 8; ++i)
    lc.setRow(0, i, hf[i]);

  delay(delaytime);
}

void loop()
{
  drawFaces();
}
