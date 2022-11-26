#pragma once

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "util.hpp"

class Texture{
private:
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Rect *source, *destination;
public:
  Texture(SDL_Renderer *renderer, std::string path, SDL_Rect *destination, SDL_Rect *source = nullptr):
    renderer(renderer), source(source), destination(destination){
    texture = loadFromPath(renderer, path);
  }
  SDL_Texture * getTexture(){
    return texture;
  }
  SDL_Rect *dest(){
    return destination;
  }
  void render(){
    SDL_RenderCopy(renderer, texture, source, destination);
  }
  static SDL_Texture* loadFromPath(SDL_Renderer *renderer, std::string path){
	  SDL_Texture *texture = nullptr;

    SDL_Surface *surface = IMG_Load(path.c_str());
    if(surface == nullptr){
      log("Unable to load image " << path << "! SDL_image Error: " << IMG_GetError());
      return nullptr;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == nullptr){
			log("Unable to create texture from " << path << "! SDL Error: " << SDL_GetError());
      return nullptr;
    }

    SDL_FreeSurface(surface);
    return texture;
  }
};