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
  if(window == nullptr)
    return false;

  std::cout << "[Game]: Window created!" << std::endl;
  renderer = SDL_CreateRenderer(window, -1, 0);
  if(renderer == nullptr)
    return false;

  // defaultLayer = new Layer();
  environment = new Environment(renderer, windowHeight, windowWidth);
  bgLayer = environment->paintBg();
  gridLayer = environment->plotGrid();
  environment->paintPaths(&paths, &cursor);
  player[0] = new Player(Controller(renderer, paths));
  player[1] = new Player(Controller(renderer, paths));

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
  for(; p < paths.length(); p++){
    paths[p]->update();
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
  bgLayer->render();
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
  delete gridLayer;
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