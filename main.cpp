#include "game.hpp"

int main(int argc, char *args[]){

    const int FPS = 60;
    const int frameDelay = 1000 / 60; // 1s / 60fps = 16ms
    uint32_t frameStart;              // time (in ms) on start of every frame

    Game *game = new Game();

    game->init("Sheep Game");

    while (game->running()){

        frameStart = SDL_GetTicks(); // eg. 1000
        game->eventHandler();
        game->update();
        game->render();

        game->frameTime = SDL_GetTicks() - frameStart; // time taken by a frame. eg. 1010 - 1000 = 10
        if (frameDelay > game->frameTime)              // eg. 16 > 10
            SDL_Delay(frameDelay - game->frameTime);   // eg. Delay(6)
        // else no delay
    }
    
    game->clean();
    return 0;
}