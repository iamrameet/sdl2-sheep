#include <iostream>
#include "SDL2/SDL_ttf.h"
#include "game.hpp"
#include "controller.hpp"
#include "util.hpp"

Controller::Controller(Game *game, VectorList<SheepPath *> &paths, int playerId):
  game(game), paths(paths), playerId(playerId){

    int posX = playerId == 0 ? 30 : game->getWindowWidth() - 40 - 30;

    for(int i = 0; i < 3; i++){
      control[i] = new SheepControl(
        game->renderer,
        posX,
        game->getWindowHeight() * (i + 6) / 10,
        Color::WHITE()
      );
      game->layer.UIComponents->addControl(control[i]);
    }
    hitpointControl = new HitpointControl(game->renderer, posX, 30);
    game->layer.UIComponents->addControl(hitpointControl);
  }

int Controller::getSelectedIndex(){
  return selected;
}

SheepPath * Controller::getSelectedPath(){
  return *paths[selected];
}

void Controller::selectPath(int index){
  onUnselect(*paths[selected], selected, 1);
  // if(index < 0)
  //   index = paths.length() - index - 1;
  if(index >= 0 && index < paths.length()){
    selected = index % paths.length();
    onSelect(*paths[selected], selected, 1);
  }
}

void Controller::selectPathRight(){
  onUnselect(*paths[selected], selected, 0);
  selected++;
  if(selected >= paths.length())
    selected = 0;
  onSelect(*paths[selected], selected, 0);
}
void Controller::selectPathLeft(){
  onUnselect(*paths[selected], selected, 0);
  selected--;
  if(selected < 0)
    selected = paths.length() - 1;
  onSelect(*paths[selected], selected, 0);
}
void Controller::clearSelection(){
  onUnselect(*paths[selected], selected, 0);
  selected = -1;
}
void Controller::plotSheep(int direction = 1){
  for(int i = 0; i < 3 ; i++){
    if(control[i]->level == 1){
      if(selected >= 0 && selected < paths.length())
        (*paths[selected])->addSheep(direction, 3 - i);
      control[0]->fill(0);
      control[1]->fill(0);
      control[2]->fill(0);
      break;
    }
  }
  // sheeps.push_back(Sheep(renderer, paths[selectedPath]->x, paths[selectedPath]->y,paths[selectedPath]->getWidth(),paths[selectedPath]->getWidth()));
}

void Controller::onSelect(SheepPath *path, int index, unsigned int highlightIndex){
  if(paths[selected] != nullptr)
    (*paths[selected])->setHighlight(highlightIndex, true);
}
void Controller::onUnselect(SheepPath *path, int index, unsigned int highlightIndex){
  if(paths[selected] != nullptr)
    (*paths[selected])->setHighlight(highlightIndex, false);
}