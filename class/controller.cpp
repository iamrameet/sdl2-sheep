#include<iostream>
#include<SDL2/SDL.h>
#include "controller.hpp"

Controller::Controller(SDL_Renderer *renderer, std::vector<SheepPath *> &paths): renderer(renderer), paths(paths) {
  paths[selectedPath]->selectPath();
}

void Controller::leftShiftPathSelector(){
  paths[selectedPath]->unselectPath();
  selectedPath--;
  if (selectedPath < 0)
    selectedPath = paths.size() - 1;
  paths[selectedPath]->selectPath();
}
void Controller::rightShiftPathSelector(){
  paths[selectedPath]->unselectPath();
  selectedPath = (selectedPath + 1) % paths.size();
  paths[selectedPath]->selectPath();
}
void Controller::plotSheep(){
  paths[selectedPath]->addSheep(selectedPath % 2 == 0 ? 1 : -1);
  // sheeps.push_back(Sheep(renderer, paths[selectedPath]->x, paths[selectedPath]->y,paths[selectedPath]->getWidth(),paths[selectedPath]->getWidth()));
}