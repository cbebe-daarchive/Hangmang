#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

MCUFRIEND_kbv tft;

void setup()
{

  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
}

void loop() {}
