#pragma once
#include <SDL2/SDL.h>
#include<iostream>
#include "color.hpp"
#include "shape.hpp"
#include "shapes/rect_filled.hpp"
#include "shapes/rect_bordered.hpp"
class Game{

    int screenHeight=480;
    int screenWidth=600;
    bool isRunning;

    SDL_Window *window;
    SDL_Renderer *renderer;
    
    RectBordered* rect=nullptr;
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
};

Game::Game(int h,int w):screenHeight(h),screenWidth(w){}
Game::~Game(){

}

void Game::init(const char* title,int x= SDL_WINDOWPOS_UNDEFINED,int y= SDL_WINDOWPOS_UNDEFINED){
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout<<"Init Success!"<<std::endl;
        window=SDL_CreateWindow(title, x, y, screenWidth,screenHeight, SDL_WINDOW_SHOWN );
        if(window){
            std::cout<<"Window created!"<<std::endl;
            renderer=SDL_CreateRenderer(window,-1,0);
            if(renderer){
                Color::newColor(renderer,Color::white);
                std::cout<<"Renderer created!"<<std::endl;
                isRunning=true;
            }
        }
    }
    else{
        std::cout<<"Init Failed!"<<std::endl;
        isRunning=false;
    }
}
void Game::update(){
    if(rectPosX<=0)
        dir=1;
    else if(rectPosX>=600)
        dir=-1;

        rectPosX+=dir;
        rect->setX(rectPosX);
    
    std::cout<<rect->getX()<<std::endl;
}
void Game::render(){
    Color::newColor(renderer,Color::white);
    SDL_RenderClear(renderer);
    rect=new RectBordered(renderer,rectPosX,0,50,80,Color::green);
    SDL_RenderPresent(renderer);
}

void Game::eventHandler(){
     SDL_Event e;
     SDL_PollEvent( &e );
     if( e.type == SDL_QUIT ) 
        isRunning = false;
}
void Game::clean(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::running(){
    return isRunning;
}