#include "path.hpp"

SheepPath::SheepPath(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Point *cursor):
  x(x), y(y),
  rect(renderer, x, y, width,height, Color::BROWN()),
  highlight{
    RectFilled(rect),
    RectFilled(rect)
  },
  cursor(cursor)
{
  collider = new RectCollider(x, y, width, height);
  highlight[0].setHeight(40);
  highlight[1].setHeight(40);
  highlight[1].setY(rect.getHeight() - 40);
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
  sheeps.push_back(Sheep(rect.renderer, posX, posY, Sheep::SIZE, Sheep::SIZE, direction));
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
  highlight[0].render();
  highlight[1].render();
  for(Sheep sheep: sheeps)
    sheep.render();
}

void SheepPath::selectPath(){
  rect.setColor(Color::LIGHT_BROWN());
}
void SheepPath::unselectPath(){
  rect.setColor(Color::BROWN());
}

void SheepPath::setHighlight(unsigned int index, bool show){
  if(show)
    highlight[index % 2].setColor(index == 0 ? Color::GREEN_GRASS_DARK() : Color::GREEN_GRASS_LIGHT());
  else
    highlight[index % 2].setColor(Color::BROWN());
}