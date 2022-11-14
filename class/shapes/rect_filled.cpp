#include "shapes/rect_filled.hpp"

RectFilled::RectFilled(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color): Shape(renderer), color(color){
    setRect(x, y, width, height);
}

void RectFilled::setX(int x){
  rect.x = x;
}
void RectFilled::setY(int y){
  rect.y = y;
}
void RectFilled::setWidth(int width){
  rect.w = width;
}
void RectFilled::setHeight(int height){
  rect.h = height;
}
void RectFilled::setColor(SDL_Color color){
  this->color = color;
}

void RectFilled::setRect(int x, int y, int width, int height){
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;
}

void RectFilled::update(){}

void RectFilled::render(){
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(renderer, &rect);
}

// RectFilled & RectFilled::operator=(const RectFilled& rect){
//   this->_rect.x = rect.x;
//   this->_rect.y = rect.y;
//   this->_rect.w = rect.width;
//   this->_rect.h = rect.height;
//   _color = rect.color;
//   return *this;
// }