#include "../../headers/Card/children/playerCard.hpp"
#include <iostream>

using namespace std;

PlayerCard::PlayerCard():Card(){}

PlayerCard::PlayerCard(const Card& C):Card(C),owner(0){}

PlayerCard::PlayerCard(const Card& C, int owner):Card(C),owner(owner){}

PlayerCard::PlayerCard(const PlayerCard& other):Card(other.number, other.color),owner(other.owner){}

PlayerCard& PlayerCard::operator=(Card& C){
    this->color = C.getColor();
    this->number = C.getNumber();

    return *this;
}

void PlayerCard::setOwner(int id){
    this->owner = id;
}
