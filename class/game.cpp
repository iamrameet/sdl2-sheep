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

SheepControl *control[3];

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

  for(int i = 0; i < 3; i++){
    control[i] = new SheepControl(renderer, 30, windowHeight * (i + 6) / 10, Color::BLACK());
    layer.UIComponents->addControl(control[i]);
  }

  environment->createPaths(&paths, &cursor);

  player[0] = new Player(Controller(renderer, paths));
  player[1] = new Player(Controller(renderer, paths));

  std::cout << "[Game]: Renderer created!" << std::endl;
  isRunning = true;

  Timer::setInterval(sheepWait, 100);

  return true;
}

void Game::sheepWait(){
  control[0]->fill(control[0]->level + 0.01f);
  control[1]->fill(control[1]->level + 0.02f);
  control[2]->fill(control[2]->level + 0.03f);
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
          if(control[0]->level == 1){
            player[0]->controller.plotSheep(1);
            control[0]->fill(0);
          }
          break;
      }
      break;
    case SDL_MOUSEBUTTONUP:
      if(control[1]->level == 1){
        player[1]->controller.plotSheep(-1);
        control[1]->fill(0);
      }
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