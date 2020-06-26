#ifndef _KEY_H
#define _KEY_H

#include "Object.h"

#define KEY_WIDTH 35

typedef struct
{
  int16_t x;
  int16_t y;
} XYPos;

class Key : public Object
{
public:
  Key(int idx, char letter) : Object(idx, letter){};

  void update(MCUFRIEND_kbv &tft)
  {
    XYPos pos = {idx * KEY_WIDTH, 290 + (idx % 13) * KEY_WIDTH};
    int half = KEY_WIDTH / 2;

    tft.fillRect(pos.x, pos.y, KEY_WIDTH, KEY_WIDTH, TFT_WHITE);
    if (isActivated)
      tft.fillRect(pos.x + half / 2, pos.y + half / 2, half, half, TFT_LIGHTGREY);
    else
    {
      tft.setCursor(pos.x + half, pos.y + half);
      tft.print(letter);
    }
  }
};

#endif