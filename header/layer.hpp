#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "color.hpp"
#include "shape.hpp"
#include "control.hpp"
#include "texture.hpp"

class Layer{
private:
  std::vector<Shape *> shapes;
  std::vector<Control *> controls;
public:
  Texture *texture = nullptr;
  // ~Layer();
  void addShape(Shape *shape);
  void removeShape(unsigned int index);
  void addControl(Control *control);
  void removeControl(unsigned int index);
  void update();
  void render();
};