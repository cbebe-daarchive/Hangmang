#include "stickman.h"

namespace stickman_consts
{
  // coordinates of edges
  const int16_t top = 0;
  const int16_t bottom = 240;
  const int16_t left = 300;
  const int16_t right = 480;
  // gallows constants
  const XYPos pole = {left + 40, top + 20};
  const XYPos rope = {right - 80, top + 20};
  const XYPos base = {left + 20, bottom - 20};
  const int16_t base_w = 140;
  // body part constants
  const int16_t centre_x = 400;
  const int16_t head_r = 20;
  const int16_t neck_y = 80;
  const int16_t shoulder_y = 100;
  const int16_t arm_l = 30;
  const int16_t hip_y = 140;
  const int16_t feet_y = 170;
  // face constants
  const int16_t face_y = neck_y - head_r;
  const int16_t face_s = 5;
  const int16_t eye_w = 5;
  const int16_t mouth_r = 5;
}; // namespace stickman_consts

void drawX(MCUFRIEND_kbv &tft, int16_t x, int16_t y, uint16_t w, uint16_t colour)
{
  tft.drawLine(x, y, x + w, y + w, colour);
  tft.drawLine(x, y + w, x + w, y, colour);
}

void drawStickMan(int part, MCUFRIEND_kbv &tft)
{
  using namespace stickman_consts;
  // REFACTOR: use less magic numbers for later stickman configuration
  switch (part)
  {
  case 0: // gallows
    tft.drawFastHLine(base.x, base.y, base_w, TFT_WHITE);
    tft.drawFastVLine(pole.x, pole.y, 200, TFT_WHITE);
    tft.drawFastHLine(pole.x, pole.y, 60, TFT_WHITE);
    tft.drawFastVLine(rope.x, rope.y, 20, TFT_WHITE);
    break;
  case 1: // head
    tft.drawCircle(centre_x, neck_y - head_r, head_r, TFT_WHITE);
    break;
  case 2: // torso
    // draw a single line for torso
    tft.drawFastVLine(centre_x, neck_y, hip_y - neck_y, TFT_WHITE);
    break;
  case 3: // arms
    tft.drawFastHLine(centre_x - arm_l, shoulder_y, arm_l * 2, TFT_WHITE);
    break;
  case 4: // left leg
    tft.drawLine(centre_x, hip_y, centre_x - arm_l, feet_y, TFT_WHITE);
    break;
  case 5: // right leg
    tft.drawLine(centre_x, hip_y, centre_x + arm_l, feet_y, TFT_WHITE);
    break;
  case 6: // face
    drawX(tft, centre_x - face_s - eye_w, face_y - eye_w, eye_w, TFT_WHITE);
    drawX(tft, centre_x + face_s, face_y - eye_w, eye_w, TFT_WHITE);
    tft.drawCircle(centre_x, face_y + face_s + mouth_r, mouth_r, TFT_WHITE);
    break;
  default: // clear the displayed stickman
    tft.fillRect(base.x, pole.y, base_w, base.y - pole.y + 1, TFT_BLACK);
    break;
  }
}