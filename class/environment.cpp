#include "environment.hpp"

Environment::Environment(SDL_Renderer *renderer, int windowHeight, int windowWidth, int tileSize) : renderer(renderer), windowHeight(windowHeight), windowWidth(windowWidth), tileSize(tileSize){
  // Constructor
}

Layer * Environment::createBackground(){
  Layer *bgLayer = new Layer();
  int matchAreaWidth = windowWidth - marginLR * 2;

  RectFilled *rectBig = new RectFilled(renderer, marginLR, 0, matchAreaWidth, windowHeight, Color::GREEN_GRASS_LIGHT());
  bgLayer->addShape(rectBig);

  for (int col = 1; col <= matchAreaWidth / tileSize; col += 2){
    RectFilled *rect = new RectFilled(renderer,
      (col - 1) * tileSize + marginLR,
      0,
      tileSize,
      windowHeight,
      Color::GREEN_GRASS_DARK());
    bgLayer->addShape(rect);
  }
  RectFilled *left = new RectFilled(renderer, 0, 0, marginLR, windowHeight, Color::BLUE()),
    *right = new RectFilled(renderer, windowWidth - marginLR, 0, marginLR, windowHeight, Color::BLUE());
  bgLayer->addShape(left);
  bgLayer->addShape(right);
  return bgLayer;
}

void Environment::createPaths(VectorList<SheepPath> *paths, SDL_Point *cursor){
  int posX = gridCellSize + marginLR,
    posY = 0,
    pathWidth = gridCellSize,
    pathHeight = windowHeight;

  for (int i = 0; i < pathCount; i++){
    paths->addItem(SheepPath(renderer, posX, posY, pathWidth, pathHeight, cursor));
    posX += pathWidth + gridCellSize;
  }
}

Layer * Environment::createUIComponents(){
  Layer *layer = new Layer();
  layer->addShape(new RectBordered(renderer, 30, windowHeight * 0.8f, 40, 40, Color::BLACK()));
  layer->addShape(new RectBordered(renderer, 30, windowHeight * 0.7f, 40, 40, Color::BLACK()));
  layer->addShape(new RectBordered(renderer, 30, windowHeight * 0.6f, 40, 40, Color::BLACK()));
  return layer;
}