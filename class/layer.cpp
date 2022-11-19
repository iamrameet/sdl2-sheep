#include "layer.hpp"

// Layer::~Layer(){
//   for(Shape *shape: shapes)
//     delete shape;
//   shapes.clear();
// }

void Layer::addShape(Shape *shape){
  shapes.push_back(shape);
}
void Layer::removeShape(uint32_t index){
  delete shapes[index];
  shapes.erase(shapes.begin() + index);
}

void Layer::addControl(SheepControl *control){
  controls.push_back(control);
}
void Layer::removeControl(unsigned int index){
  delete controls[index];
  controls.erase(controls.begin() + index);
}

void Layer::update(){
  for(Shape *shape : shapes)
    shape->update();
  for(SheepControl *control : controls)
    control->update();
}

void Layer::render(){
  for(Shape *shape : shapes)
    shape->render();
  for(SheepControl *control : controls)
    control->render();
}