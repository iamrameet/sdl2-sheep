#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "color.hpp"
#include "sheep.hpp"
#include "shapes/rect_bordered.hpp"

class SheepPath{
private:
  RectBordered rect;
public:
  int x, y;
  std::vector<Sheep> sheeps;

  SheepPath(SDL_Renderer *renderer, int x, int y):
    x(x), y(y), rect(renderer, x, y, 80, 400, Color::WHITE()){}

  int getWidth(){
    return rect.getWidth();
  }
  int getHeight(){
    return rect.getHeight();
  }

  void addSheep(int direction = 1){
    int posX = x + 15;
    int posY = direction == 1 ? rect.getHeight() - Sheep::SIZE : y;
    sheeps.push_back(Sheep(rect.renderer, posX, posY, direction));
  }

  void update(){
    for(std::vector<Sheep>::iterator sheep = sheeps.begin(); sheep != sheeps.end(); sheep++){
      int pos_y = sheep->getY();
      if(pos_y < 0 || pos_y > rect.getHeight())
        sheeps.erase(sheep--);
      else
        sheep->update();
    }
  }

  void render(){
    rect.render();
    for(Sheep sheep: sheeps)
      sheep.render();
  }

};