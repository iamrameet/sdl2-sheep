#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "../color.hpp"
#include "../shape.hpp"
class RectFilled:public Shape{
    SDL_Rect rect;
    SDL_Color color;
    public:
        RectFilled(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color);

        int getX(){return rect.x;}
        int getY(){return rect.y;}
        int getWidth(){return rect.w;}
        int getHeight(){return rect.h;}
        SDL_Color getColor(){return color;}

        void setX(int x){
            rect.x = x;
        }
        void setY(int y){
            rect.y = y;
        }
        void setWidth(int width){
            rect.w = width;
        }
        void setHeight(int height){
            rect.h = height;
        }
        void setColor(SDL_Color color){
            this->color = color;
        }
        void update() override;
        void render() override;
};

RectFilled::RectFilled(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color): Shape(renderer), color(color){
    rect.x=x;
    rect.y=y;
    rect.h=height;
    rect.w=width;
}

void RectFilled::update(){}

void RectFilled::render(){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}