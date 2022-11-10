#pragma once
#include "SDL2/SDL.h"

class RectCollider{
public:
  SDL_Rect rect;
  RectCollider(int x, int y, int width, int height): rect{x, y, width, height}{}
  bool withPoint(SDL_Point *point){
    return SDL_PointInRect(point, &rect);
  }
  void render(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 200);
    SDL_RenderDrawRect(renderer, &rect);
  }
};

class CircleCollider{
public:
  int x, y;
  float radius;
  CircleCollider(int x, int y, float radius): x(x), y(y), radius(radius){}
  bool withPoint(SDL_Point *point){
    return false;
  }
  void render(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 200);
    // Circle Rendering Algorithm
  }
};