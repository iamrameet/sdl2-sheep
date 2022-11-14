#include <iostream>
#include "game.hpp"
#include "timer.hpp"
#include "util.hpp"

void Game::layer::render(){
  background->render();
  UIComponents->render();
}
void Game::layer::clean(){
  delete background;
  delete UIComponents;
}

Game::Game(){}
Game::Game(int h, int w): windowHeight(h), windowWidth(w){}
Game::~Game(){}

bool Game::init(const char *title, int x, int y){
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;

  std::cout << "[Game]: SDL initialised" << std::endl;
  window = SDL_CreateWindow(title, x, y, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
  if(window == nullptr)
    return false;

  std::cout << "[Game]: Window created!" << std::endl;
  renderer = SDL_CreateRenderer(window, -1, 0);
  if(renderer == nullptr)
    return false;

  environment = new Environment(renderer, windowHeight, windowWidth);
  layer.background = environment->createBackground();
  layer.UIComponents = environment->createUIComponents();
  environment->createPaths(&paths, &cursor);

  player[0] = new Player(Controller(renderer, paths));
  player[1] = new Player(Controller(renderer, paths));

  std::cout << "[Game]: Renderer created!" << std::endl;
  isRunning = true;

  Timer::setInterval(sheepWait, 2000);

  return true;
}

void Game::sheepWait(){
  std::cout << "counter" << std::endl;
}

void Game::update(){

  Timer::call();

  counter++;
  int p = 0;
  for(; p < paths.length(); p++){
    paths[p]->update(player);

    if(player[1]->controller.getSelectedIndex() != p && paths[p]->collider->withPoint(&cursor)){
      player[1]->controller.selectPath(p);
      break;
    }
  }
  // if(p == paths.length())
  //   paths.clearSelection();
}

void Game::render(){
  SDL_RenderClear(renderer);
  // defaultLayer->render();
  layer.render();
  for(SheepPath path: paths){
    path.render();
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
          player[0]->controller.selectPathLeft();
          break;
        case SDLK_RIGHT:
          player[0]->controller.selectPathRight();
          break;
        case SDLK_SPACE:
          player[0]->controller.plotSheep(1);
          break;
      }
      break;
    case SDL_MOUSEBUTTONUP:
      player[1]->controller.plotSheep(-1);
      break;
  }
  SDL_PumpEvents();
  SDL_GetMouseState(&cursor.x, &cursor.y);
}

void Game::clean(){
  // delete defaultLayer;
  layer.clean();
  delete environment;
  // for(SheepPath path: paths)
  //   delete &path;

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