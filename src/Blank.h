#ifndef _BLANK_H
#define _BLANK_H

#include "Object.h"

class Blank : public Object
{
public:
  Blank(int idx, char letter) : Object(idx, letter){};

  void update(MCUFRIEND_kbv &tft)
  {
    if (isActivated)
    {
      // draw letter
    }
    else
    {
      // draw blank
    }
  }
};

#endif