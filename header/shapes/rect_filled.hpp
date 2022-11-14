#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "../color.hpp"
#include "../shape.hpp"
#include "util.hpp"

class RectFilled: public Shape{
public:
  SDL_Rect rect;
  SDL_Color color;
public:
  // const int &x = rect.x;
  // const int &y = rect.y;
  // const int &width = rect.w;
  // const int &height = rect.h;

  RectFilled(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color);

  void setX(int x);
  void setY(int y);
  void setWidth(int width);
  void setHeight(int height);
  void setColor(SDL_Color color);
  void setRect(int x, int y, int width, int height);
  void update() override;
  void render() override;
  // RectFilled & operator=(const RectFilled& rect);
};