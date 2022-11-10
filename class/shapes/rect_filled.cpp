#include "shapes/rect_filled.hpp"

RectFilled::RectFilled(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color): Shape(renderer), color(color){
    rect.x=x;
    rect.y=y;
    rect.h=height;
    rect.w=width;
}

int RectFilled::getX(){return rect.x;}
int RectFilled::getY(){return rect.y;}
int RectFilled::getWidth(){return rect.w;}
int RectFilled::getHeight(){return rect.h;}
SDL_Color RectFilled::getColor(){return color;}

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

void RectFilled::update(){}

void RectFilled::render(){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}