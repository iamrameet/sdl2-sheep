#include "game.hpp"

int main( int argc, char* args[] ){

    Game * game=new Game(480,600);
    game->init("Sheep Game");
    while(game->running()){
        game->render();
        game->eventHandler();
        game->update();
        SDL_Delay(20);
    }
    game->clean();
    return 0;
}