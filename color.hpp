#pragma once
#include <iostream>
#include <SDL2/SDL.h>


#define COLOR_RED SDL_Color{255, 0, 0, 255}
#define COLOR_GREEN SDL_Color{0, 255, 0, 255}
#define COLOR_BLUE SDL_Color{0, 0, 255, 255}
#define COLOR_YELLOW SDL_Color{255, 255, 0, 255}
#define COLOR_BLACK SDL_Color{0, 0, 0, 255}
#define COLOR_WHITE SDL_Color{255, 255, 255, 255}
#define COLOR_GREEN_GRASS_LIGHT SDL_Color{161, 223, 80, 255}
#define COLOR_GREEN_GRASS_DARK SDL_Color{95, 195, 20, 255}
#define COLOR_BROWN SDL_Color{172, 98, 56, 255}
//or

class Color{
    public:
        static SDL_Color RED(){ return SDL_Color{255, 0, 0, 255}; }
        static SDL_Color GREEN(){ return SDL_Color{0, 255, 0, 255}; }
        static SDL_Color BLUE(){ return SDL_Color{0, 0, 255, 255}; }
        static SDL_Color YELLOW(){ return SDL_Color{255, 255, 0, 255}; }
        static SDL_Color BLACK(){ return SDL_Color{0, 0, 0, 255}; }
        static SDL_Color WHITE(){ return SDL_Color{255, 255, 255, 255}; }
        static SDL_Color GREEN_GRASS_LIGHT(){ return SDL_Color{161, 223, 80, 255}; }
        static SDL_Color GREEN_GRASS_DARK(){ return SDL_Color{95, 195, 20, 255}; }
        static SDL_Color BROWN(){ return SDL_Color{172, 98, 56, 255}; }
};
