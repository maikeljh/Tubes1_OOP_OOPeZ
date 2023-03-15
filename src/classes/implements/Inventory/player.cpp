#include "../../headers/Inventory/children/Player/player.hpp"
#include <iostream>

using namespace std;

template <class T>
int Player<T>::playersCreated = 0;

/* Ctor */
template <class T>
Player<T>::Player(){}

template <class T>
Player<T>::Player(string nickname):id(this->playersCreated+1){
    this->nickname = nickname;
    this->playersCreated++;
}

/* Getter */
template <class T>
string Player<T>::getNickname(){
    return this->nickname;
}

template <class T>
int Player<T>::getID(){
    return this->id;
}

template <class T>
vector<T>& Player<T>::getDeckPlayer(){
    return this->mainDeck;
}