#include <iostream>
#include "game.hpp"

Game::Game(){}
Game::Game(int h, int w): windowHeight(h), windowWidth(w){}
Game::~Game(){}

bool Game::init(const char *title, int x, int y){
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;

  std::cout << "[Game]: SDL initialised" << std::endl;
  window = SDL_CreateWindow(title, x, y, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
  if(window == NULL)
    return false;

  std::cout << "[Game]: Window created!" << std::endl;
  renderer = SDL_CreateRenderer(window, -1, 0);
  if(renderer == NULL)
    return false;

  // defaultLayer = new Layer();
  environment = new Environment(renderer, windowHeight, windowWidth);
  bgLayer = environment->paintBg();
  gridLayer = environment->plotGrid();
  paths = environment->paintPaths(&cursor);
  controller = new Controller(renderer, paths);

  // paths[0] = new SheepPath(renderer, 100, 0);
  // paths[1] = new SheepPath(renderer, 200, 0);
  // paths[2] = new SheepPath(renderer, 300, 0);
  // paths[3] = new SheepPath(renderer, 400, 0);

  // defaultLayer->addShape(new RectBordered(renderer, 100, 0, 100, windowHeight, Color::WHITE()));
  // defaultLayer->addShape(new RectBordered(renderer, 300, 0, 100, windowHeight, Color::WHITE()));
  std::cout << "[Game]: Renderer created!" << std::endl;
  isRunning = true;
  return true;
}

void Game::update(){
  // if(counter % 500 == 0)
  //    paths[3]->addSheep();
  // else if(counter % 400 == 0)
  //    paths[2]->addSheep(-1);
  // else if(counter % 300 == 0)
  //    paths[1]->addSheep(-1);
  // else if(counter % 200 == 0)
  //    paths[0]->addSheep();

  counter++;
  int p = 0;
  for(; p < paths.size(); p++){
    if(controller->getSelectedPath() != p && paths[p]->collider->withPoint(&cursor)){
      controller->selectPath(p);
      break;
    }
    paths[p]->update();
  }
  if(p == paths.size())
    controller->clearSelection();
}

void Game::render(){
  SDL_RenderClear(renderer);
  // defaultLayer->render();
  bgLayer->render();
  for(SheepPath *path: paths){
    path->render();
  }
  // gridLayer->render();
  SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
  SDL_RenderPresent(renderer);
}

void Game::eventHandler(){
  SDL_Event e;
  SDL_PollEvent( &e );
  switch (e.type){
    case SDL_QUIT:
      isRunning = false;
      break;

    case SDL_KEYDOWN:
      switch (e.key.keysym.sym){
        case SDLK_ESCAPE:
          isRunning = false;
          break;
        case SDLK_LEFT:
          controller->leftShiftPathSelector();
          break;
        case SDLK_RIGHT:
          controller->rightShiftPathSelector();
          break;
        case SDLK_SPACE:
          controller->plotSheep(1);
          break;
      }
      break;
    case SDL_MOUSEBUTTONUP:
      std::cout << "button pressed" << std::endl;
      controller->plotSheep(-1);
      break;
  }
  SDL_PumpEvents();
  SDL_GetMouseState(&cursor.x, &cursor.y);
}

void Game::clean(){
  // delete defaultLayer;
  delete gridLayer;
  delete controller;
  delete environment;
  for(SheepPath *path: paths)
    delete path;

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool Game::running(){
  return isRunning;
}

int Game::getWindowWidth(){
  return windowWidth;
}

int Game::getWindowHeight(){
  return windowHeight;
}