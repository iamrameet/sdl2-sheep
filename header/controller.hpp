#pragma once
#include <iostream>
#include "shapes/rect_filled.hpp"
#include "shapes/rect_bordered.hpp"
#include "path.hpp"
#include "vector-list.hpp"

// #define Array(type, identifier) std::vector<type> identifier

class Controller{
    // Array(SheepPath *, paths);
    VectorList<SheepPath> &paths;
    SDL_Renderer *renderer;
    int selected = 0;
    private:
        void onSelect(SheepPath *path, int index, unsigned int highlightIndex);
        void onUnselect(SheepPath *path, int index, unsigned int highlightIndex);
    public:
        Controller(SDL_Renderer *renderer, VectorList<SheepPath> &paths);
        int getSelectedIndex();
        SheepPath * getSelectedPath();
        void selectPath(int index);
        void selectPathRight();
        void selectPathLeft();
        void clearSelection();
        void plotSheep(int direction);
};