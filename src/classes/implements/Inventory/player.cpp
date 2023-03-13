#include "../../headers/Inventory/children/Player/player.hpp"
#include <iostream>

using namespace std;

template <class T>
int Player<T>::playersCreated = 0;

template <class T>
Player<T>::Player(){}

template <class T>
Player<T>::Player(string nickname):InventoryHolder<T>(), id(this->playersCreated+1){
    this->nickname = nickname;
    // this->point = 0;
    // this->mainDeck.push_back(D.pop());
    // this->mainDeck.push_back(D.pop());
    this->playersCreated++;
}

template <class T>
Player<T>::~Player(){

}

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