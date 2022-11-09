#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "../color.hpp"
#include "../shape.hpp"

class RectBordered: public Shape{
    SDL_Rect rect;
    SDL_Color color;
    public:
        RectBordered(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Color color);

        int getX();
        int getY();
        int getWidth();
        int getHeight();
        SDL_Color getColorCode();

        void setX(int x);
        void setY(int y);
        void setWidth(int width);
        void setHeight(int height);
        void setColor(SDL_Color color);
        void setRect(int x, int y, int width, int height);
        void update() override;
        void render() override;
};