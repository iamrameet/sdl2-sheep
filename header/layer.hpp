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
  void addShape(Shape *shape);
  void removeShape(uint32_t index);
  void update();
  void render();
};