#ifndef _BLANK_H
#define _BLANK_H

#include "DispObject.h"

class Blank : public DispObject
{
public:
  Blank(int idx, char letter) : DispObject(idx, letter){};

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

#endif //_BLANK_H