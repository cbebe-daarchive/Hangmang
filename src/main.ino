/*
  HangMang - A Hangman game for Arduino MEGA 2560 with touch screen
  Author: Charles Ancheta
*/
#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#include "game.h"
#include "stickman.h"
#include "Key.h"
#include <TouchPoint.h>

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
  TouchPoint touch;
  Key keys[26];
  for (int i = 0; i < 26; i++)
  {
    keys[i] = Key(i, 'A' + i);
    keys[i].update(tft);
  }

  screenPos disp = {200, 100};

  while (true)
  {
    screenPos xy = touch.process();
    if (xy.x != touch.untouched)
    {
      tft.fillRect(disp.x, disp.y, 120, 60, TFT_BLACK);
      tft.setCursor(disp.x, disp.y);
      tft.setTextSize(1);
      tft.setTextColor(TFT_WHITE);
      tft.print(xy.x);
      tft.print(" ");
      tft.print(xy.y);
      delay(200);
    }
  }

  while (true)
    for (int i = 0; i < 8; i++)
    {
      drawStickMan(i, tft);
      delay(1000);
    }

  game();
}
