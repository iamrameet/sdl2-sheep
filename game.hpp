#pragma once
#include <SDL2/SDL.h>
#include<vector>
#include<iostream>
#include "color.hpp"
#include "shape.hpp"
#include "layer.hpp"
#include "environment.hpp"
#include "sheep.hpp"
#include "path.hpp"
#include "shapes/rect_filled.hpp"
#include "shapes/rect_bordered.hpp"
#include "controller.hpp"
class Game{


    int windowHeight=650;
    int windowWidth=500;
    bool isRunning;
    std::vector<SheepPath* >paths;

    SDL_Window *window;
    SDL_Renderer *renderer;
    Environment* environment;
    RectBordered* rect;
    Layer *defaultLayer,*bgLayer,*gridLayer;
    Controller *controller;

    int rectPosX=0;
    int dir=1;

    public:
        Game();
        Game(int h,int w);
        ~Game();
        void init(const char* title,int x,int y);
        void update();
        void render();
        void eventHandler();
        void clean();
        bool running();
        int getWindowHeight();
        int getWindowWidth();
};
Game::Game(){}
Game::Game(int h,int w):windowHeight(h),windowWidth(w){}
Game::~Game(){

}

void Game::init(const char* title,int x= SDL_WINDOWPOS_UNDEFINED,int y= SDL_WINDOWPOS_UNDEFINED){
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Init Success!" << std::endl;
        window = SDL_CreateWindow(title, x, y, windowWidth,windowHeight, SDL_WINDOW_SHOWN );
        if(window){
            std::cout<<"Window created!"<<std::endl;
            renderer=SDL_CreateRenderer(window,-1,0);
            if(renderer){
                // defaultLayer = new Layer();
                environment=new Environment(renderer,windowHeight,windowWidth);
                bgLayer=environment->paintBg();
                gridLayer=environment->plotGrid();
                paths=environment->paintPaths();
                controller=new Controller(renderer,paths);
                

                // paths[0] = new SheepPath(renderer, 100, 0);
                // paths[1] = new SheepPath(renderer, 200, 0);
                // paths[2] = new SheepPath(renderer, 300, 0);
                // paths[3] = new SheepPath(renderer, 400, 0);
                
                // defaultLayer->addShape(new RectBordered(renderer, 100, 0, 100, windowHeight, Color::WHITE()));
                // defaultLayer->addShape(new RectBordered(renderer, 300, 0, 100, windowHeight, Color::WHITE()));
                std::cout<<"Renderer created!"<<std::endl;
                isRunning=true;
            }
        }
    }
    else{
        std::cout << "Init Failed!" << std::endl;
        isRunning=false;
    }
}

int counter = 0;

void Game::update(){
    // if(counter % 500 == 0)
    //     paths[3]->sheeps.push_back(Sheep(renderer, paths[3]->x + 15, paths[3]->y));
    // else if(counter % 400 == 0)
    //     paths[2]->sheeps.push_back(Sheep(renderer, paths[2]->x + 15, paths[2]->getHeight() - Sheep::SIZE, -1));
    // else if(counter % 300 == 0)
    //     paths[1]->sheeps.push_back(Sheep(renderer, paths[1]->x + 15, paths[1]->getHeight() - Sheep::SIZE, -1));
    // else if(counter % 200 == 0)
    //     paths[0]->sheeps.push_back(Sheep(renderer, paths[0]->x + 15, paths[0]->y));
    counter++;

    for(SheepPath *path: paths){
        path->update();
    }
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
                    controller->plotSheep();
                    break;
            }
            break;
        }
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