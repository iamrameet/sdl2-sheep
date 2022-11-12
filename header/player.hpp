#pragma once
#include "controller.hpp"

class Player{

int hitPoints=1000;
public:
  Controller controller;
  Player(Controller controller);
  int getHitPoints();
  void decrementHitPoints(int sheepWeight);
};