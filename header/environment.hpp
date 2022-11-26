#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "layer.hpp"
#include "path.hpp"
#include "vector-list.hpp"

class Environment{

    SDL_Renderer *renderer;
    int windowWidth, windowHeight;
    int tileSize;
    int pathCount = 4;
    int marginLR = 100;
    int pathGap = 20;
    int pathSizeW = (windowWidth - marginLR * 2) / pathCount - pathGap;

    public:
        Environment(SDL_Renderer *renderer, int windowHeight, int windowWidth,int tileSize = 5);
        Layer * createBackground();
        Layer * createUIComponents();
        void createPaths(VectorList<SheepPath *> *paths, SDL_Point *cursor);

};