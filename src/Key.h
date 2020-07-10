#ifndef _KEY_H
#define _KEY_H

#include "DispObject.h"
#include "xypos.h"

namespace key_consts
{
  const uint16_t key_width = 40;
  const XYPos first_row = {240, 240};
  const XYPos last_rows = {80, 280};
}; // namespace key_consts

// Key class for user input

class Key : public DispObject
{
public:
  Key() {} // empty constructor

  Key(int idx, char letter) : DispObject(idx, letter) {}

  void update(MCUFRIEND_kbv &tft)
  {
    using namespace key_consts;
    XYPos pos;
    if (idx <= 6)
      pos = {first_row.x + idx * 40, first_row.y};
    else
      pos = {last_rows.x + idx * 40,
             last_rows.y + ((idx - 7) % 10) * 40};

    int half = key_width / 2;

    tft.fillRect(pos.x, pos.y, key_width, key_width, TFT_WHITE);

    if (isActivated)
      // Letter will now be blurred out
      tft.fillRect(pos.x + half / 2, pos.y + half / 2, half, half, TFT_LIGHTGREY);
    else
    {
      tft.setCursor(pos.x + half, pos.y + half);
      tft.setTextSize(2);
      tft.setTextColor(TFT_BLACK);
      tft.print(letter);
    }
  }
};

#endif