#pragma once
#include <SDL2/SDL.h>
#include<iostream>
#include "color.hpp"
#include "shape.hpp"
#include "layer.hpp"
#include "sheep.hpp"
#include "path.hpp"
#include "shapes/rect_filled.hpp"
#include "shapes/rect_bordered.hpp"
class Game{

    int screenHeight=480;
    int screenWidth=600;
    bool isRunning;

    SDL_Window *window;
    SDL_Renderer *renderer;

    RectBordered* rect=nullptr;
    Layer *defaultLayer;

    SheepPath *paths[4];

    int rectPosX=0;
    int dir=1;

    public:
        int frameTime = 0;
        Game();
        Game(int h,int w);
        ~Game();
        void init(const char* title,int x,int y);
        void update();
        void render();
        void eventHandler();
        void clean();
        bool running();
};

Game::Game(int h,int w):screenHeight(h),screenWidth(w){}
Game::~Game(){

}

void Game::init(const char* title,int x= SDL_WINDOWPOS_UNDEFINED,int y= SDL_WINDOWPOS_UNDEFINED){
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Init Success!" << std::endl;
        window = SDL_CreateWindow(title, x, y, screenWidth,screenHeight, SDL_WINDOW_SHOWN );
        if(window){
            std::cout<<"Window created!"<<std::endl;
            renderer=SDL_CreateRenderer(window,-1,0);
            if(renderer){
                defaultLayer = new Layer();
                rect = new RectBordered(renderer, 0, 0, 50, 80, COLOR_RED);
                paths[0] = new SheepPath(renderer, 100, 0);
                paths[1] = new SheepPath(renderer, 200, 0);
                paths[2] = new SheepPath(renderer, 300, 0);
                paths[3] = new SheepPath(renderer, 400, 0);
                defaultLayer->addShape(rect);
                // defaultLayer->addShape(new RectBordered(renderer, 100, 0, 100, screenHeight, Color::WHITE()));
                // defaultLayer->addShape(new RectBordered(renderer, 300, 0, 100, screenHeight, Color::WHITE()));
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

long counter = 0;

void Game::update(){
    if(counter % 500 == 0)
        paths[3]->addSheep();
    else if(counter % 400 == 0)
        paths[2]->addSheep(-1);
    else if(counter % 300 == 0)
        paths[1]->addSheep(-1);
    else if(counter % 200 == 0)
        paths[0]->addSheep();
    counter++;

    for(SheepPath *path: paths){
        path->update();
    }

    if(rectPosX<=0)
        dir=1;
    else if(rectPosX>=600)
        dir=-1;

    rectPosX+=dir;
    rect->setX(rectPosX);

    // std::cout<<rect->getX()<<std::endl;
}

void Game::render(){
    SDL_RenderClear(renderer);
    defaultLayer->render();
    for(SheepPath *path: paths){
        path->render();
    }
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderPresent(renderer);
}

void Game::eventHandler(){
     SDL_Event e;
     SDL_PollEvent( &e );
     if( e.type == SDL_QUIT ) 
        isRunning = false;
}
void Game::clean(){

    delete rect;
    delete defaultLayer;
    for(SheepPath *path: paths)
        delete path;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::running(){
    return isRunning;
}