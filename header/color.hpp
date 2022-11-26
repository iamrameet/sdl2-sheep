#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class Color{
    public:
        static SDL_Color TRANSPARENT(){ return SDL_Color{0, 0, 0, 1}; }
        static SDL_Color RED(){ return SDL_Color{255, 0, 0, 255}; }
        static SDL_Color GREEN(){ return SDL_Color{0, 255, 0, 255}; }
        static SDL_Color BLUE(){ return SDL_Color{0, 0, 255, 255}; }
        static SDL_Color YELLOW(){ return SDL_Color{255, 255, 0, 255}; }
        static SDL_Color BLACK(){ return SDL_Color{0, 0, 0, 255}; }
        static SDL_Color WHITE(){ return SDL_Color{255, 255, 255, 255}; }
        static SDL_Color GREEN_GRASS_LIGHT(){ return SDL_Color{161, 223, 80, 255}; }
        static SDL_Color GREEN_GRASS_DARK(){ return SDL_Color{95, 195, 20, 255}; }
        static SDL_Color BROWN(){ return SDL_Color{172, 98, 56, 255}; }
        static SDL_Color LIGHT_BROWN(){ return SDL_Color{192,127,69};}
};
