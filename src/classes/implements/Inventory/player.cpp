#include "../../headers/Inventory/children/Player/player.hpp"
#include <iostream>

using namespace std;

int Player::playersCreated = 0;

Player::Player(){}

Player::Player(DeckCard& D, string nickname):id(this->playersCreated+1){
    this->nickname = nickname;
    this->point = 0;
    this->mainDeck = new PlayerCard[2];
    this->mainDeck[0] = D.pop();
    this->mainDeck[1] = D.pop();
    this->mainDeck[0].setOwner(this->id);
    this->mainDeck[1].setOwner(this->id);
    this->playersCreated++;
}