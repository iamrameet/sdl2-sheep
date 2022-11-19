#pragma once
#include <SDL2/SDL.h>
#include "shapes/rect_filled.hpp"
#include "color.hpp"
#include "collider.hpp"

class Sheep{
private:
  int x, y, dir;
  int weight=100;
  RectFilled rect;
public:
  // const int &y = _y;
  RectCollider collider;
  bool collided=false;
  Sheep(SDL_Renderer *renderer, int x, int y, int width, int height, int direction, int type);
  ~Sheep();
  int getX();
  int getY();
  int getWeight();
  int getDirection();
  SDL_Rect getRect();
  void move(int movementFactor);
  void update(bool invertDirection);
  void render();
  void leftShiftPathSelector();
  void rightShiftPathSelector();
  void plotSheep();
  void setColor(SDL_Color color);

public:
  static const int SIZE = 30;
};