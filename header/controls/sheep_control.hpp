#pragma once
#include "shapes/rect_bordered.hpp"
#include "shapes/rect_filled.hpp"
#include "util.hpp"
#include "control.hpp"

class SheepControl: public Control{
  readonly(RectBordered, outline);
  readonly(RectFilled, fillArea);
  readonly(float, level);
public:
  SheepControl(SDL_Renderer* renderer, int x, int y, SDL_Color color);
  void fill(float level);
  void update();
  void render();
};