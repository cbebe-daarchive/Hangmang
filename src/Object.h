#ifndef _OBJECT_H
#define _OBJECT_H

#include <MCUFRIEND_kbv.h>

class Object
{
public:
  Object(int idx, char letter) : idx{idx}, letter{letter}
  {
    isActivated = false;
  }

  void update(MCUFRIEND_kbv &tft);

  void activate(MCUFRIEND_kbv &tft)
  {
    isActivated = true;
    update(tft);
  };

protected:
  int idx;
  char letter;
  bool isActivated;
};
#endif