#ifndef TOUCHPOINT_H
#define TOUCHPOINT_H

#include <TouchScreen.h>

struct screenPos
{
  int16_t x;
  int16_t y;
};

namespace tc
{
  // touch screen pins, obtained from the documentation
  const uint8_t yp = A3;
  const uint8_t xm = A2;
  const uint8_t ym = 9;
  const uint8_t xp = 8;
  const uint8_t rx = 300;
  // calibration data for the touch screen, obtained from documentation
  // the minimum/maximum possible readings from the touch point
  const uint16_t ts_minx = 100;
  const uint16_t ts_miny = 120;
  const uint16_t ts_maxx = 940;
  const uint16_t ts_maxy = 920;

  // thresholds to determine if there was a touch
  const uint16_t min_pressure = 10;
  const uint16_t max_pressure = 1000;

}; // namespace tc

// wrapper class for touchscreen
class TouchPoint
{
public:
  TouchPoint(uint16_t width = 480, uint16_t height = 320) : _width(width), _height(height) {}

  // get x and y coordinates of the touched point in screen
  screenPos process();
  // wait until the screen is touched
  void wait();
  // wait until the screen is released
  void hold();

  const uint16_t untouched = -100; // assigned if not touched

private:
  uint16_t _width;
  uint16_t _height;
};

#endif
