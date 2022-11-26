#include "player.hpp"

Player::Player(Controller controller): controller(controller), _hitPoints(1000){
    controller.hitpointControl->updateText(_hitPoints);
}

int Player::getHitPoints(){
    return _hitPoints;
}
void Player::decrementHitPoints(int sheepWeight){
    _hitPoints -= sheepWeight;
    controller.hitpointControl->updateText(_hitPoints);
    std::cout<<"["<<_hitPoints<<"]"<<"decreasing HP by "<<sheepWeight<<std::endl;
}