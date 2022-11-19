#include "sheep.hpp"
// #include "player.hpp"

Sheep::Sheep(SDL_Renderer *renderer, int x, int y, int width, int height, int direction, int type):
  x(x), y(y), dir(direction), weight(type * 100),
  rect(renderer, x, y, width, height, direction == 1 ? Color::GREEN() : Color::RED()),
  collider(rect.rect){
  // std::cout << "[Sheep]: created" << std::endl;
}
Sheep::~Sheep(){
  // std::cout << "[Sheep]: destroyed" << std::endl;
}
int Sheep::getX(){
  return x;
}
int Sheep::getY(){
  return y;
}
int Sheep::getDirection(){
  return dir;
}
int Sheep::getWeight(){
  return weight;
}
SDL_Rect Sheep::getRect(){
  return rect.rect;
}
void Sheep::move(int movementFactor){
  this->y += dir * movementFactor;
  rect.setY(this->y);
  collider.rect.y = this->y;
}
void Sheep::update(bool invertDirection){
  invertDirection?move(-1):move(1);
}
void Sheep::render(){
  rect.render();
  collider.render(rect.renderer);
}
void Sheep::setColor(SDL_Color color){
  this->rect.setColor(color);
}