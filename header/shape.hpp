#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "color.hpp"
class Shape{
    public:
        SDL_Renderer *renderer;
        Shape(SDL_Renderer *renderer): renderer(renderer){}
        virtual void update(){};
        virtual void render(){};
};