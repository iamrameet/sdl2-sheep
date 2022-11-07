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
    if(selectedPath>0){
        paths[selectedPath]->unselectPath();
        selectedPath--;
        paths[selectedPath]->selectPath();
    }

        std::cout<<"Path selected: "<<selectedPath<<std::endl;
}
void Controller::rightShiftPathSelector(){
    if(selectedPath<paths.size()-1){
        paths[selectedPath]->unselectPath();
        selectedPath++;
        paths[selectedPath]->selectPath();

    }
        std::cout<<"Path selected: "<<selectedPath<<std::endl;
}
void Controller::plotSheep(){
    std::cout<<"Plotting sheep at "<<selectedPath<<std::endl;
    paths[selectedPath]->sheeps.push_back(Sheep(renderer, paths[selectedPath]->x, paths[selectedPath]->y,paths[selectedPath]->getWidth(),paths[selectedPath]->getWidth()));
}


