#include "TouchPoint.h"
#include <Arduino.h>

using namespace tc;

TouchScreen ts = TouchScreen(xp, yp, xm, ym, rx);

screenPos TouchPoint::process()
{
  TSPoint touch = ts.getPoint();

  pinMode(yp, OUTPUT);
  pinMode(xm, OUTPUT);
  screenPos tp;
  // checks if screen was not touched
  if (touch.z < min_pressure || touch.z > max_pressure)
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