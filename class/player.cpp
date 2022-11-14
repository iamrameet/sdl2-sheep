#include "player.hpp"

Player::Player(Controller controller): controller(controller), _hitPoints(1000){}

int Player::getHitPoints(){
    return _hitPoints;
}
void Player::decrementHitPoints(int sheepWeight){
    _hitPoints -=sheepWeight;
    std::cout<<"["<<_hitPoints<<"]"<<"decreasing HP by "<<sheepWeight<<std::endl;
}