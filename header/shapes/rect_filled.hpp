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

        int getX();
        int getY();
        int getWidth();
        int getHeight();
        SDL_Color getColor();

        void setX(int x);
        void setY(int y);
        void setWidth(int width);
        void setHeight(int height);
        void setColor(SDL_Color color);
        void update() override;
        void render() override;
};