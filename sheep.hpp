#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "color.hpp"
#include "shapes/rect_filled.hpp"

class Sheep{
private:
  int x, y, dir;
  RectBordered rect;
public:
  Sheep(SDL_Renderer *renderer, int x, int y, int direction = 1):
    x(x), y(y), dir(direction), rect(renderer, x, y, SIZE, SIZE, Color::GREEN()){
    // std::cout << "[Sheep]: created" << std::endl;
  }
  Sheep(SDL_Renderer *renderer, int x, int y,int width,int height, int direction = 1):
    x(x), y(y), dir(direction), rect(renderer, x, y,width, height, Color::GREEN()){
  }
  ~Sheep(){
    // std::cout << "[Sheep]: destroyed" << std::endl;
  }
  int getY(){
    return y;
  }
  void move(int movementFactor){
    this->y += dir * movementFactor;
    rect.setY(this->y);
  }
  void update(){
    move(1);
  }
  void render(){
    rect.render();
  }

public:
  static const int SIZE = 50;

};