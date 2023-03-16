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

template <class T>
T Player<T>::getCard(int index){
    return this->mainDeck[index];
}

template <class T>
void Player<T>::push(const T& PC){
   this->mainDeck.push_back(PC);
}

template <class T>
void Player<T>::push(DeckCard<T>& DC, int count){
    if(DC.getNeff() >= count){
        for(int i = 0; i < count; i++){
            this->mainDeck.push_back(DC.pop());
        }
    }
}

template <class T>
T Player<T>::pop(){
    T PCx;
    if(this->mainDeck.size() > 0){
        PCx = this->mainDeck.back();
        this->mainDeck.pop_back();
        return PCx;
    } else {
        cout << "\nKartu player sudah kosong" << endl;
        return PCx;
    }
}