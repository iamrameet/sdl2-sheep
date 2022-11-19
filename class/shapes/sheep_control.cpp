#include "shapes/sheep_control.hpp"

SheepControl::SheepControl(SDL_Renderer* renderer, int x, int y, SDL_Color color):
  _outline(renderer, x, y, 40, 40, color),
  _fillArea(renderer, x, y + 40, 40, 0, color),
  _level(0){}

void SheepControl::fill(float level){
    std::cout << level << std::endl;
  if(level > 1)
    level = 1;
  else if (level < 0)
    level = 0;
  _level = level;
  int height = 40 * level;
  _fillArea.setY(_outline.rect.y + 40 - height);
  _fillArea.setHeight(height);
}

void SheepControl::update(){
  // _outline.update();
  // _fillArea.update();
}

void SheepControl::render(){
  _outline.render();
  _fillArea.render();
}