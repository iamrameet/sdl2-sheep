#include "player.hpp"

Player::Player(Controller controller): controller(controller){}

int Player::getHitPoints(){
    return hitPoints;
}
void Player::decrementHitPoints(int sheepWeight){
    hitPoints -=sheepWeight;
    std::cout<<"["<<hitPoints<<"]"<<"decreasing HP by "<<sheepWeight<<std::endl;
}