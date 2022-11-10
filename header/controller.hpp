#pragma once
#include <iostream>
#include "shapes/rect_filled.hpp"
#include "shapes/rect_bordered.hpp"
#include "path.hpp"

// #define Array(type, identifier) std::vector<type> identifier

class Controller{
    // Array(SheepPath *, paths);
    std::vector<SheepPath *> paths;
    SDL_Renderer *renderer;
    int selectedPath = 0;
    public:
        Controller(SDL_Renderer *renderer, std::vector<SheepPath *> &paths);
        int getSelectedPath();
        void clearSelection();
        void selectPath(int index);
        void leftShiftPathSelector();
        void rightShiftPathSelector();
        void plotSheep(int direction);
};