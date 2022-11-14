#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "color.hpp"
#include "shape.hpp"
#include "shapes/sheep_control.hpp"

class Layer{
private:
  std::vector<Shape *> shapes;
  std::vector<SheepControl *> controls;
public:
  // ~Layer();
  void addShape(Shape *shape);
  void removeShape(unsigned int index);
  void addControl(SheepControl *control);
  void removeControl(unsigned int index);
  void update();
  void render();
};