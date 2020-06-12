#include "TouchPoint.h"
#include <Arduino.h>

// touch screen pins, obtained from the documentation
const uint8_t yp = A3;
const uint8_t xm = A2;
const uint8_t ym = 9;
const uint8_t xp = 8;
// calibration data for the touch screen, obtained from documentation
// the minimum/maximum possible readings from the touch point
const uint16_t ts_minx = 100;
const uint16_t ts_miny = 120;
const uint16_t ts_maxx = 940;
const uint16_t ts_maxy = 920;

// thresholds to determine if there was a touch
const uint16_t minpr = 10;
const uint16_t maxpr = 1000;

TouchPoint::TouchPoint(uint16_t width, uint16_t height)
{
  *ts = TouchScreen(xp, yp, xm, ym, 300);
  _width = width;
  _height = height;
}

screenPos TouchPoint::process()
{
  TSPoint touch = ts->getPoint();
  pinMode(yp, OUTPUT);
  pinMode(xm, OUTPUT);
  screenPos tp;
  // checks if screen was not touched
  if (touch.z < minpr || touch.z > maxpr)
  {
    // return an arbitrarily large negative number
    tp.x = untouched;
    tp.y = untouched;
    return tp;
  }
  tp.x = map(touch.y, ts_minx, ts_maxx, _width - 1, 0);
  tp.y = map(touch.x, ts_miny, ts_maxy, _height - 1, 0);
  return tp;
}

void TouchPoint::wait()
{
  while (process().x == untouched)
    ;
}

void TouchPoint::hold()
{
  while (process().x != untouched)
    ;
}