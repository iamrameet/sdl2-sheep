#include "path.hpp"

SheepPath::SheepPath(SDL_Renderer *renderer, int x, int y):
  x(x), y(y), rect(renderer, x, y, 80, 400, Color::BROWN()){
    collider = new RectCollider(x, y, 80, 400);
  }
SheepPath::SheepPath(SDL_Renderer *renderer, int x, int y,int width, int height, SDL_Point *cursor):
  x(x), y(y), rect(renderer, x, y,width,height, Color::BROWN()), cursor(cursor){
    collider = new RectCollider(x, y, width, height);
  }
int SheepPath::getWidth(){
  return rect.getWidth();
}
int SheepPath::getHeight(){
  return rect.getHeight();
}

void SheepPath::addSheep(int direction){
  int posX = x + 10;
  int posY = direction == -1 ? rect.getHeight() - Sheep::SIZE : y;
  sheeps.push_back(Sheep(rect.renderer, posX, posY, direction));
}

void SheepPath::update(){
  if(collider->withPoint(cursor))
    selectPath();
  else
    unselectPath();

  for(std::vector<Sheep>::iterator sheep = sheeps.begin(); sheep != sheeps.end(); sheep++){
    int pos_y = sheep->getY();
    if(pos_y < 0 || pos_y > rect.getHeight())
      sheeps.erase(sheep--);
    else
      sheep->update();
  }
}

void SheepPath::render(){
  rect.render();
  for(Sheep sheep: sheeps)
    sheep.render();
}

void SheepPath::selectPath(){
  rect.setColor(Color::LIGHT_BROWN());
}
void SheepPath::unselectPath(){
  rect.setColor(Color::BROWN());
}