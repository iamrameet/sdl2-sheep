#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "../color.hpp"
#include "../shape.hpp"

class RectBordered: public Shape{
    SDL_Rect rect;
    SDL_Color color;
    public:
        RectBordered(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color);

        int getX(){return rect.x;}
        int getY(){return rect.y;}
        int getWidth(){return rect.w;}
        int getHeight(){return rect.h;}
        SDL_Color getColorCode(){return color;}

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
        void setRect(int x, int y, int width, int height){
            rect.x = x;
            rect.y = y;
            rect.w = width;
            rect.h = height;
        }
        void update() override;
        void render() override;
};

RectBordered::RectBordered(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color): Shape(renderer), color(color){
    setRect(x, y, width, height);
}

void RectBordered::update(){}

void RectBordered::render(){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer, &rect);
}