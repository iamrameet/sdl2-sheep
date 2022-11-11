#include "environment.hpp"

Environment::Environment(SDL_Renderer *renderer, int windowHeight, int windowWidth, int tileSize):
  renderer(renderer), windowHeight(windowHeight), windowWidth(windowWidth), tileSize(tileSize){
    // Constructor
}

Layer * Environment::paintBg(){
    Layer *bgLayer = new Layer();

    RectFilled* rectBig = new RectFilled(renderer, 0, 0, windowWidth, windowHeight, Color::GREEN_GRASS_LIGHT());
    bgLayer->addShape(rectBig);
        for(int col = 1; col <= windowWidth / tileSize; col += 2){
            RectFilled *rect = new RectFilled(renderer,
                (col - 1) * tileSize,
                0, tileSize, windowHeight,
                Color::GREEN_GRASS_DARK()
            );
            bgLayer->addShape(rect);
        }
    return bgLayer;
}

Layer * Environment::plotGrid(){
    Layer *gridLayer = new Layer();
    for(int row = 1; row <= windowHeight / gridCellSize; row++){
        for(int col = 1; col <= gridCellSize; col++){
            RectBordered *rect = new RectBordered(renderer,
                (col - 1) * gridCellSize,
                (row - 1) * gridCellSize,
                gridCellSize, gridCellSize, Color::RED()
            );
            gridLayer->addShape(rect);
        }
    }
    return gridLayer;
}

void Environment::paintPaths(VectorList<SheepPath> *paths, SDL_Point *cursor){
    int posX = gridCellSize,
        posY = 0,
        pathWidth = gridCellSize,
        pathHeight = windowHeight;

    for(int i = 0; i < pathCount; i++){
        paths->addItem(SheepPath(renderer, posX, posY, pathWidth, pathHeight, cursor));
        posX += pathWidth + gridCellSize;
    }
}