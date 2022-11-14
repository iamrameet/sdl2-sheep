#pragma once
#include "controller.hpp"
#include "util.hpp"

class Player{

readonly(int, hitPoints);
public:
  Controller controller;
  Player(Controller controller);
  int getHitPoints();
  void decrementHitPoints(int sheepWeight);
};