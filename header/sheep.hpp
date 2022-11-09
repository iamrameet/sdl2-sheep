#pragma once
#include <SDL2/SDL.h>
#include "shapes/rect_filled.hpp"

class Sheep{
private:
  int x, y, dir;
  RectFilled rect;
public:
  Sheep(SDL_Renderer *renderer, int x, int y, int direction = 1);
  Sheep(SDL_Renderer *renderer, int x, int y,int width,int height, int direction = 1);
  ~Sheep();
  int getY();
  void move(int movementFactor);
  void update();
  void render();
public:
  static const int SIZE = 30;
};