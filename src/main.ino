/*
  HangMang - A Hangman game for Arduino MEGA 2560 with touch screen
  Author: Charles Ancheta
*/
#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#include "game.h"
#include "stickman.h"

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
  for (int i = 0; i < 8; i++)
  {
    drawStickMan(i, tft);
    delay(1000);
  }

  game();
}
