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

Player& Player::operator=(const Player& other){
    this->id = other.id;
    this->nickname = other.nickname;
    this->point = other.point;
    this->mainDeck = new PlayerCard[2];
    this->mainDeck[0] = other.mainDeck[0];
    this->mainDeck[1] = other.mainDeck[1];
    this->mainDeck[0].setOwner(this->id);
    this->mainDeck[1].setOwner(this->id);
    return *this;
}

void Player::printPlayerCard(){
    cout << "1. " << this->mainDeck[0].getNumber() << " " << this->mainDeck[0].getColor() << endl;
    cout << "2. " << this->mainDeck[1].getNumber() << " " << this->mainDeck[1].getColor() << endl;
}

string Player::getNickname(){
    return this->nickname;
}

Combination Player::getCombo(){
    return this->kombo;
}