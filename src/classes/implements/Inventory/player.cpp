#include "../../headers/Inventory/children/Player/player.hpp"
#include <iostream>

using namespace std;

int Player::playersCreated = 0;

Player::Player(){}

Player::Player(DeckCard<Card> &D, string nickname):InventoryHolder(), id(this->playersCreated+1){
    this->nickname = nickname;
    this->point = 0;
    this->mainDeck.push_back(D.pop());
    this->mainDeck.push_back(D.pop());
    this->playersCreated++;
}

Player& Player::operator=(const Player& other){
    this->id = other.id;
    this->nickname = other.nickname;
    this->point = other.point;
    this->mainDeck.push_back(other.mainDeck[0]);
    this->mainDeck.push_back(other.mainDeck[1]);
    return *this;
}
Player& Player::operator+(const Card& add){
    this->mainDeck.push_back(add);
    return *this;
}

Player& Player::operator-(){
    this->mainDeck.pop_back();
    return *this;
}

bool Player::operator>(const Player& other){
    return this->point > other.point;
}

bool Player::operator<(const Player& other){
    return this->point < other.point;
}
bool Player::operator==(const Player& other){
    return (this->point == other.point);
    
}
Player::~Player(){

}

void Player::useAbilityCard(){
    this->ability.setUseable(false);
}

bool Player::checkValidAbilityCard(string ability){
    return this->ability.getType() == ability && this->ability.getUseable();
}
void Player::addAbilityCard(const AbilityCard& AC){
    this->ability = AC;
}
void Player::addPoint(long long int round_points){
    this->point += round_points;
}

Card Player::getCard(int idx){
    return this->mainDeck[idx];
}

void Player::push(const Card& PC){
   this->mainDeck.push_back(PC);
}

Card Player::pop(){
    Card PCx = this->mainDeck.back();
    this->mainDeck.pop_back();
    return PCx;
}
void Player::printCard(){
    cout << "1. " << this->mainDeck[0].getNumber() << " " << this->mainDeck[0].getColor() << endl;
    cout << "2. " << this->mainDeck[1].getNumber() << " " << this->mainDeck[1].getColor() << endl;
}

string Player::getNickname(){
    return this->nickname;
}

Combination& Player::getCombo(){
    return this->kombo;
}

long long int Player::getPoint(){
    return this->point;
}

vector<Card>& Player::getDeckPlayer(){
    return this->mainDeck;
}

AbilityCard& Player::getAbilityCard(){
    return this->ability;
}