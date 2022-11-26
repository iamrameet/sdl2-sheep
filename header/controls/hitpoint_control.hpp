#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "util.hpp"
#include "shapes/rect_bordered.hpp"
#include "control.hpp"

class HitpointControl: public Control{
  readonly(RectBordered, outline);
  TTF_Font *font = TTF_OpenFont("../fonts/lazy.ttf", 18);
  SDL_Texture *textTexture = nullptr;
public:
  HitpointControl(SDL_Renderer *renderer, int x, int y): Control(renderer), _outline(renderer, x, y, 40, 40, Color::YELLOW()){}
  bool updateText(int text){
    if(textTexture)
      SDL_DestroyTexture(textTexture);

    SDL_Surface *surface = TTF_RenderText(font, std::to_string(text).c_str(), Color::BLACK(), Color::TRANSPARENT());
    if(surface == nullptr){
      log("Unable to load text " << text << "! SDL_ttf Error: " << TTF_GetError());
      return false;
    }

    textTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if(textTexture == nullptr){
      log("Unable to load text " << text << "! SDL_ttf Error: " << SDL_GetError());
      return false;
    }

    _outline.rect.w = surface->w;
    _outline.rect.h = surface->h;
    SDL_FreeSurface(surface);
    return true;
  }
  void update(){}
  void render(){
    _outline.render();
    if(textTexture)
      SDL_RenderCopy(renderer, textTexture, nullptr, &_outline.rect);
  }
};