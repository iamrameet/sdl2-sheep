#pragma once
#include <iostream>
#include <SDL2/SDL.h>


#define COLOR_RED SDL_Color{255, 0, 0, 255}

//or

class Color{
    public:
        static SDL_Color RED(){ return SDL_Color{255, 0, 0, 255}; }
        static SDL_Color GREEN(){ return SDL_Color{0, 255, 0, 255}; }
        static SDL_Color BLUE(){ return SDL_Color{0, 0, 255, 255}; }
        static SDL_Color YELLOW(){ return SDL_Color{255, 255, 0, 255}; }
        static SDL_Color BLACK(){ return SDL_Color{0, 0, 0, 255}; }
        static SDL_Color WHITE(){ return SDL_Color{255, 255, 255, 255}; }
};