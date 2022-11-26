#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "color.hpp"
#include "collider.hpp"
#include "sheep.hpp"
#include "shapes/rect_filled.hpp"
#include "shapes/rect_bordered.hpp"
#include "texture.hpp"

class Player;
class SheepPath{
private:
  Player *player;
  RectBordered rect;
  RectFilled highlight[2];
  SDL_Point *cursor;
  Texture texture;
public:
  int collidedWeight=0;
  int x, y;
  RectCollider *collider;
  std::vector<Sheep *> sheeps;
  SheepPath(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Point *cursor);
  int getWidth();
  int getHeight();
  void addSheep(int direction, int type);
  void update(Player** player);
  void render();
  void selectPath();
  void unselectPath();
  void setHighlight(unsigned int index, bool show);
};