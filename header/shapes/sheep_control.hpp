#pragma once
#include "rect_bordered.hpp"
#include "rect_filled.hpp"
#include "util.hpp"

class SheepControl{
  readonly(RectBordered, outline);
  readonly(RectFilled, fillArea);
  readonly(float, level);
public:
  SheepControl(SDL_Renderer* renderer, int x, int y, SDL_Color color);
  void fill(float level);
  void update();
  void render();
};