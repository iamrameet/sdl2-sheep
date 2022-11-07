#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "color.hpp"
#include "shape.hpp"

class Layer{
private:
  std::vector<Shape *> shapes;
public:
  void addShape(Shape *shape){
    shapes.push_back(shape);
  }
  void removeShape(uint32_t index){
    shapes.erase(shapes.begin() + index);
  }

  void update(){
    for(Shape *shape : shapes)
      shape->update();
  }

  void render(){
    for(Shape *shape : shapes)
      shape->render();
  }

};