#include<iostream>
#include<SDL2/SDL.h>
#include "controller.hpp"

Controller::Controller(SDL_Renderer *renderer, std::vector<SheepPath *> &paths):
  renderer(renderer), paths(paths){}

int Controller::getSelectedPath(){
  return selectedPath;
}

void Controller::clearSelection(){
  if(selectedPath < 0 || selectedPath >= paths.size())
    return;
  paths[selectedPath]->unselectPath();
}

void Controller::selectPath(int index){
  clearSelection();
  selectedPath = index % paths.size();
  paths[selectedPath]->selectPath();
  std::cout << "[Controller]: Path [" << selectedPath << "] selected" << std::endl;
}

void Controller::leftShiftPathSelector(){
  clearSelection();
  selectedPath--;
  if (selectedPath < 0)
    selectedPath = paths.size() - 1;
  paths[selectedPath]->selectPath();
  std::cout << "[Controller]: Path [" << selectedPath << "] selected" << std::endl;
}

void Controller::rightShiftPathSelector(){
  clearSelection();
  selectedPath = (selectedPath + 1) % paths.size();
  paths[selectedPath]->selectPath();
  std::cout << "[Controller]: Path [" << selectedPath << "] selected" << std::endl;
}
void Controller::plotSheep(int direction = 1){
  if(selectedPath >= 0 && selectedPath < paths.size())
    paths[selectedPath]->addSheep(direction);
  // sheeps.push_back(Sheep(renderer, paths[selectedPath]->x, paths[selectedPath]->y,paths[selectedPath]->getWidth(),paths[selectedPath]->getWidth()));
}