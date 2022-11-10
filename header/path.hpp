#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "color.hpp"
#include "collider.hpp"
#include "sheep.hpp"
#include "shapes/rect_bordered.hpp"

class SheepPath{
private:
  RectFilled rect;
  SDL_Point *cursor;
public:
  int x, y;
  RectCollider *collider;
  std::vector<Sheep> sheeps;
  SheepPath(SDL_Renderer *renderer, int x, int y);
  SheepPath(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Point *cursor);
  int getWidth();
  int getHeight();
  void addSheep(int direction = 1);
  void update();
  void render();
  void selectPath();
  void unselectPath();
};