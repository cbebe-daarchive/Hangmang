#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include "../game.h"

MCUFRIEND_kbv tft;

void setup()
{
  // set up TFT
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
}

void loop()
{
  tft.fillScreen(TFT_BLACK);
  game();
}
