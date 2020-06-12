#ifndef TOUCHPOINT_H
#define TOUCHPOINT_H

#include <TouchScreen.h>

struct screenPos
{
  int16_t x;
  int16_t y;
};

// wrapper class for touchscreen
class TouchPoint
{
public:
  TouchPoint(uint16_t width = 480, uint16_t height = 320);
  // get x and y coordinates of the touched point in screen
  screenPos process();
  // wait until the screen is touched
  void wait();
  // wait until the screen is released
  void hold();
  const uint16_t untouched = -100; // assigned if not touched
private:
  TouchScreen *ts;
  uint16_t _width;
  uint16_t _height;
};

#endif
