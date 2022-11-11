#include<iostream>
#include<SDL2/SDL.h>
#include "controller.hpp"

Controller::Controller(SDL_Renderer *renderer, VectorList<SheepPath> &paths):
  renderer(renderer), paths(paths){}

int Controller::getSelectedIndex(){
  return selected;
}

SheepPath * Controller::getSelectedPath(){
  return paths[selected];
}

void Controller::selectPath(int index){
  onUnselect(paths[selected], selected, 1);
  // if(index < 0)
  //   index = paths.length() - index - 1;
  if(index >= 0 && index < paths.length()){
    selected = index % paths.length();
    onSelect(paths[selected], selected, 1);
  }
}

void Controller::selectPathRight(){
  onUnselect(paths[selected], selected, 0);
  selected++;
  if(selected >= paths.length())
    selected = 0;
  onSelect(paths[selected], selected, 0);
}
void Controller::selectPathLeft(){
  onUnselect(paths[selected], selected, 0);
  selected--;
  if(selected < 0)
    selected = paths.length() - 1;
  onSelect(paths[selected], selected, 0);
}
void Controller::clearSelection(){
  onUnselect(paths[selected], selected, 0);
  selected = -1;
}
void Controller::plotSheep(int direction = 1){
  if(selected >= 0 && selected < paths.length())
    paths[selected]->addSheep(direction);
  // sheeps.push_back(Sheep(renderer, paths[selectedPath]->x, paths[selectedPath]->y,paths[selectedPath]->getWidth(),paths[selectedPath]->getWidth()));
}

void Controller::onSelect(SheepPath *path, int index, unsigned int highlightIndex){
  if(paths[selected] != nullptr)
    paths[selected]->setHighlight(highlightIndex, true);
}
void Controller::onUnselect(SheepPath *path, int index, unsigned int highlightIndex){
  if(paths[selected] != nullptr)
    paths[selected]->setHighlight(highlightIndex, false);
}