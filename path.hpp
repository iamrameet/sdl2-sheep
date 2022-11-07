#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "color.hpp"
#include "sheep.hpp"
#include "shapes/rect_bordered.hpp"

class SheepPath{
private:
  RectFilled rect;
public:
  int x, y;
  std::vector<Sheep> sheeps;

  SheepPath(SDL_Renderer *renderer, int x, int y):
    x(x), y(y), rect(renderer, x, y, 80, 400, Color::BROWN()){}
  SheepPath(SDL_Renderer *renderer, int x, int y,int width, int height):
    x(x), y(y), rect(renderer, x, y,width,height, Color::BROWN()){}
  int getWidth(){
    return rect.getWidth();
  }
  int getHeight(){
    return rect.getHeight();
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

  void selectPath(){
    rect.setColor(Color::WHITE());
  }
  void unselectPath(){
    rect.setColor(Color::BROWN());
  }
};