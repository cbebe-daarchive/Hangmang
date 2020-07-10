/* 
  DispObject.h

  General Object class for displaying letters
*/
#ifndef _DISP_OBJECT_H
#define _DISP_OBJECT_H

#include <MCUFRIEND_kbv.h>

class DispObject
{
public:
  DispObject() {} // empty constructor

  DispObject(int idx, char letter) : idx{idx}, letter{letter}
  {
    isActivated = false;
  }

  // Displays the object on the screen depending on activation
  // Subclasses should override this function
  void update(MCUFRIEND_kbv &tft) {}

  void activate(MCUFRIEND_kbv &tft)
  {
    isActivated = true;
    update(tft);
  }

protected:
  int idx;
  char letter;
  bool isActivated;
};

#endif // _DISP_OBJECT_H