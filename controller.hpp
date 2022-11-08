#pragma once
#include <iostream>
#include "game.hpp"
#include "shapes/rect_filled.hpp"
#include "shapes/rect_bordered.hpp"
#include "path.hpp"

class Controller{
    std::vector<SheepPath*> paths;
    SDL_Renderer *renderer;
    int selectedPath=0;
    public:
        Controller(SDL_Renderer *renderer,std::vector<SheepPath*>& paths):renderer(renderer),paths(paths) {
            paths[selectedPath]->selectPath();
        }
        void leftShiftPathSelector();
        void rightShiftPathSelector();
        void plotSheep();
};

void Controller::leftShiftPathSelector(){
        paths[selectedPath]->unselectPath();
        selectedPath--;
        if(selectedPath<0)
            selectedPath=paths.size()-1;
        paths[selectedPath]->selectPath();
}
void Controller::rightShiftPathSelector(){
        paths[selectedPath]->unselectPath();
        selectedPath=(selectedPath+1)%paths.size();
        paths[selectedPath]->selectPath();
}
void Controller::plotSheep(){
    paths[selectedPath]->sheeps.push_back(Sheep(renderer, paths[selectedPath]->x, paths[selectedPath]->y,paths[selectedPath]->getWidth(),paths[selectedPath]->getWidth()));
}


