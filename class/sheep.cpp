#include "sheep.hpp"

Sheep::Sheep(SDL_Renderer *renderer, int x, int y, int width, int height, int direction):
  x(x), y(y), dir(direction), rect(renderer, x, y,width, height, direction == 1 ? Color::GREEN() : Color::RED()){
  // std::cout << "[Sheep]: created" << std::endl;
}
Sheep::~Sheep(){
  // std::cout << "[Sheep]: destroyed" << std::endl;
}
int Sheep::getY(){
  return y;
}
void Sheep::move(int movementFactor){
  this->y += dir * movementFactor;
  rect.setY(this->y);
}
void Sheep::update(){
  move(1);
}
void Sheep::render(){
  rect.render();
}
void Sheep::setColor(SDL_Color color){
  this->rect.setColor(color);
}