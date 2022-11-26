#include "path.hpp"
#include "player.hpp"

SheepPath::SheepPath(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Point *cursor):
  x(x), y(y),
  rect(renderer, x, y, width, height, Color::BROWN()),
  texture(renderer, "../assets/sheep-path.png", &rect.rect),
  highlight{
    RectFilled(renderer, x, y, width, height, Color::BROWN()),
    RectFilled(renderer, x, y, width, height, Color::BROWN())
  },
  cursor(cursor)
{
  collider = new RectCollider(x, y, width, height);
  highlight[0].setHeight(40);
  highlight[1].setHeight(40);
  highlight[1].setY(rect.rect.h - 40);
}
int SheepPath::getWidth(){
  return rect.rect.w;
}
int SheepPath::getHeight(){
  return rect.rect.h;
}

void SheepPath::addSheep(int direction, int type){
  int margin = rect.rect.w * 0.2f;
  int minWidth = rect.rect.w * 0.3f;
  int maxWidth = rect.rect.w - margin * 2;
  int size = (maxWidth - minWidth) * type / 3 + minWidth;
  int posX = x + (maxWidth - size) / 2 + margin;
  int posY = direction == -1 ? rect.rect.h - size : y;
  sheeps.push_back(new Sheep(rect.renderer, posX, posY, size, size, direction, type));
}

void SheepPath::update(Player** player){
  for(std::vector<Sheep *>::iterator sheep = sheeps.begin(); sheep != sheeps.end(); sheep++){

    int pos_y = (*sheep)->getY();
    
    if(pos_y < 0 || pos_y > rect.rect.h){
      if((*sheep)->collided)
        collidedWeight-=(*sheep)->getWeight()*(*sheep)->getDirection();
      if(pos_y < 0&&(*sheep)->getDirection()==-1){
        player[0]->decrementHitPoints((*sheep)->getWeight());
      }
      else if(pos_y > rect.rect.h&&(*sheep)->getDirection()==1){
        player[1]->decrementHitPoints((*sheep)->getWeight());
      }
      delete *sheep;
      sheeps.erase(sheep--);
    }
    else{
      
      if(!(*sheep)->collided){
        for(std::vector<Sheep *>::iterator currentSheep = sheeps.begin(); currentSheep != sheep; currentSheep++){

          if((*currentSheep)->collider.withRectCollider(&(*sheep)->collider)){
            (*sheep)->collided=true;
            collidedWeight+=(*sheep)->getWeight()*(*sheep)->getDirection();
            if(!(*currentSheep)->collided){
              collidedWeight+=(*currentSheep)->getWeight()*(*currentSheep)->getDirection();
              (*currentSheep)->collided=true;
            }
            break;
          }
        }
      }
      
      if((*sheep)->collided){
        if(collidedWeight>0){
          (*sheep)->update((*sheep)->getDirection() == 1 ? false : true);
        }
        else if(collidedWeight<0){
          (*sheep)->update((*sheep)->getDirection() == -1 ? false : true);
        }
      }
      else{
        (*sheep)->update(false);
      }      
    }
  }
}

void SheepPath::render(){
  // rect.render();
  texture.render();
  highlight[0].render();
  highlight[1].render();
  for(Sheep *sheep: sheeps)
    sheep->render();
}


void SheepPath::setHighlight(unsigned int index, bool show){
  if(show)
    highlight[index % 2].setColor(index == 0 ? Color::GREEN_GRASS_DARK() : Color::GREEN_GRASS_LIGHT());
  else
    highlight[index % 2].setColor(Color::BROWN());
}