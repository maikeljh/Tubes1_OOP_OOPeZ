#include "../../headers/Inventory/children/Player/player.hpp"
#include <iostream>

using namespace std;

int Player::playersCreated = 0;

Player::Player():id(this->playersCreated+1){
    this->playersCreated++;
}