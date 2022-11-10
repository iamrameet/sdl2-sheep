#pragma once
#include <iostream>
#include "SDL2/SDL.h"
#include "layer.hpp"
#include "path.hpp"

class Environment{

    SDL_Renderer *renderer;
    int windowWidth, windowHeight;
    int tileSize;
    int pathCount = 5;
    int gridCellSize = windowWidth / (pathCount * 2 + 1);

    public:
        Environment(SDL_Renderer *renderer, int windowHeight, int windowWidth,int tileSize = 5);
        Layer * paintBg();
        Layer * plotGrid();
        std::vector<SheepPath *> paintPaths(SDL_Point *cursor);

};