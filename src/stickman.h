/* 
  stickman.h

  For drawing stickman on screen

  0-6 incrementally draws the stickman
  else it clears the display
*/

#ifndef _STICKMAN_H
#define _STICKMAN_H

#include <MCUFRIEND_kbv.h>
#include "xypos.h"

void drawStickMan(int part, MCUFRIEND_kbv &tft);

#endif
