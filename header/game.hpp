#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "color.hpp"
#include "shape.hpp"
#include "layer.hpp"
#include "environment.hpp"
#include "sheep.hpp"
#include "path.hpp"
#include "shapes/rect_filled.hpp"
#include "shapes/rect_bordered.hpp"
#include "player.hpp"
#include "vector-list.hpp"

// class Controller;

class Game{

    int windowHeight=650;
    int windowWidth=500;
    bool isRunning = false;
    VectorList<SheepPath> paths;
    Player *player[2];

    SDL_Window *window;
    Environment *environment;
    RectBordered *rect;
    Controller *controller;
    SDL_Point cursor;

    public:
        struct layer{
            Layer *background,
                *UIComponents;
            void render();
            void clean();
        } layer;
        SDL_Renderer *renderer;
        long counter = 0;
        int frameTime = 0;
        Game();
        Game(int h, int w);
        ~Game();
        bool init(const char *title, int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED);
        void update();
        void render();
        void eventHandler();
        void clean();
        bool running();
        int getWindowHeight();
        int getWindowWidth();
};