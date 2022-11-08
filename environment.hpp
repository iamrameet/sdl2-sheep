#pragma once
#include <iostream>
#include "game.hpp"
#include "shapes/rect_filled.hpp"
#include "shapes/rect_bordered.hpp"
#include "path.hpp"
class Environment{

    SDL_Renderer* renderer;
    int windowWidth,windowHeight;
    int tileSize;
    int pathCount=5;
    int gridCellSize=windowWidth/(pathCount*2+1);

    public:
        Environment(SDL_Renderer *renderer,int windowHeight, int windowWidth,int tileSize=5)
            :renderer(renderer),windowHeight(windowHeight),windowWidth(windowWidth),tileSize(tileSize)
        {}
        Layer*  paintBg();
        Layer*  plotGrid();
        std::vector<SheepPath* > paintPaths();

};

Layer*  Environment::paintBg(){
    Layer* bgLayer=new Layer();

    RectFilled* rectBig=new RectFilled(renderer,0,0,windowWidth,windowHeight,Color::GREEN_GRASS_LIGHT());
    bgLayer->addShape(rectBig);
        for(int col=1;col<=windowWidth/tileSize;col+=2){
            RectFilled* rect=new RectFilled(renderer,(col-1)*tileSize,0,tileSize,windowHeight,Color::GREEN_GRASS_DARK());
            bgLayer->addShape(rect);
        }
    return bgLayer;
}
Layer*  Environment::plotGrid(){
    Layer* gridLayer=new Layer();
    for(int row=1;row<=windowHeight/gridCellSize;row++){
        for(int col=1;col<=gridCellSize;col++){
            RectBordered* rect=new RectBordered(renderer,(col-1)*gridCellSize,(row-1)*gridCellSize,gridCellSize,gridCellSize,Color::RED());
            gridLayer->addShape(rect);
        }
    }
    return gridLayer;
}
std::vector<SheepPath* >  Environment::paintPaths(){
    std::vector<SheepPath* >paths;
    int posX=gridCellSize,posY=0,pathWidth=gridCellSize,pathHeight=windowHeight;
    for(int i=0; i<pathCount; i++){
        paths.push_back(new SheepPath(renderer,posX,posY,pathWidth,pathHeight));
        posX+=pathWidth+gridCellSize;
    }
    return paths;

}