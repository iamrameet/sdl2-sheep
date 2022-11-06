#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class Color{
    public:
        enum ColorCode{
            red,
            green,
            blue,
            yellow,
            black,
            white,
        };
        static ColorCode colorCode;
        static void newColor(SDL_Renderer* renderer,ColorCode code){
            switch (code)
            {
            case red:
                SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255);
                break;
            case green:
                SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255);
                break;
            case blue:
                SDL_SetRenderDrawColor(renderer,0,0,255,255);
                break;
            case yellow:
                SDL_SetRenderDrawColor(renderer,255,255,0,255);
                break;
            case black:
                SDL_SetRenderDrawColor(renderer,0,0,0,255);
                break;
            case white:
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                break;
            default:
                break;
            }
        }
};
