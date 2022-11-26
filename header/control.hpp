#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class Control{
    public:
        SDL_Renderer *renderer;
        Control(SDL_Renderer *renderer): renderer(renderer){}
        virtual void update(){};
        virtual void render(){};
};