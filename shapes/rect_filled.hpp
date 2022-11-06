#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "../color.hpp"
#include "../shape.hpp"
class RectFilled:public Shape{
    int x,y,width,height;
    SDL_Rect rect;
    Color::ColorCode colorCode;
    public:
        RectFilled(SDL_Renderer* renderer,int x,int y,int width,int height,Color::ColorCode colorCode);

        int getX(){return x;}
        int getY(){return y;}
        int getWidth(){return width;}
        int getHeight(){return height;}
        Color::ColorCode getColorCode(){return colorCode;}

        void setX(int x){
            rect.x=this->x = x;
        }
        void setY(int y){
            rect.y=this->y = y;
        }
        void setWidth(int x){
            rect.w=this->width = x;
        }
        void setHeight(int y){
            rect.h=this->height = y;
        }
        void setColor(Color::ColorCode color){
            this->colorCode =color;
        }
};

RectFilled::RectFilled(SDL_Renderer* renderer,int x,int y,int width,int height,Color::ColorCode colorCode):

x(x),y(y),width(width),height(height),colorCode(colorCode)
{
    rect.x=x;
    rect.y=y;
    rect.h=height;
    rect.w=width;
    Color::newColor(renderer,colorCode);     
    SDL_RenderFillRect( renderer, &rect );
}