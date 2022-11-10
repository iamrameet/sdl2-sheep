#include "shapes/rect_bordered.hpp"

int RectBordered::getX(){return rect.x;}
int RectBordered::getY(){return rect.y;}
int RectBordered::getWidth(){return rect.w;}
int RectBordered::getHeight(){return rect.h;}
SDL_Color RectBordered::getColorCode(){return color;}

void RectBordered::setX(int x){
  rect.x = x;
}
void RectBordered::setY(int y){
  rect.y = y;
}
void RectBordered::setWidth(int width){
  rect.w = width;
}
void RectBordered::setHeight(int height){
  rect.h = height;
}
void RectBordered::setColor(SDL_Color color){
  this->color = color;
}
void RectBordered::setRect(int x, int y, int width, int height){
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;
}

RectBordered::RectBordered(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color):
  Shape(renderer), color(color){
    setRect(x, y, width, height);
}

void RectBordered::update(){}

void RectBordered::render(){
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawRect(renderer, &rect);
}