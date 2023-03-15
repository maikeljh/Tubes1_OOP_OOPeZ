#include "../../headers/Inventory/children/DeckCard/deckCard.hpp"
#include <iostream>

using namespace std;

template <class T>
DeckCard<T>::DeckCard():DeckCard(0, 108){}

template <class T>
DeckCard<T>::DeckCard(int neff, int size):neff(neff), size(size){}

template <class T>
DeckCard<T>& DeckCard<T>::operator=(const DeckCard& dc){
    if(this != &dc){
        this->deck = dc.deck;
        this->neff = dc.neff;
        this->size = dc.size;
    }
    return *this;
}

template <class T>
T DeckCard<T>::pop(){
    this->neff--;
    T C = this->deck[this->neff];
    this->deck.pop_back();
    return this->deck[this->neff];
}

template <class T>
void DeckCard<T>::push(const T& Card){
    this->deck.push_back(Card);
    this->neff++;
}

template <class T>
int DeckCard<T>::getNeff(){
    return this->neff;
}

template <class T>
int DeckCard<T>::getSize(){
    return this->size;
}

template<>
void DeckCard<Card>::printCard(){
    cout << "Isi dari deck sekarang :" << endl;
    for(int i = 0; i < this->neff; i++){
        cout << i+1 << ". " << this->deck[i].getNumber() <<  " " << this->deck[i].getColor() << endl;
    }
}

template<>
void DeckCard<AbilityCard>::printCard(){
    cout << "Isi dari deck sekarang :" << endl;
    for(int i = 0; i < this->neff; i++){
        cout << i+1 << ". " << this->deck[i].getType() << endl;
    }
}

template<>
void DeckCard<UnoCard>::printCard(){
    cout << this->neff << endl;
    cout << "Isi dari deck sekarang :" << endl;
    for(int i = 0; i < this->neff; i++){
        cout << i+1 << ". " << this->deck[i].getNumber() <<  " " << this->deck[i].getColor() << " " << this->deck[i].getType() << endl;
    }
}

template <class T>
T& DeckCard<T>::getCard(int i){
    return this->deck[i];
}

template <class T>
void DeckCard<T>::setCard(const T &card, int i){
    this->deck[i] = card;
}

template <class T>
DeckCard<T>& DeckCard<T>::operator+(const T& add){
    this->push(add);
    return *this;
}

template <class T>
DeckCard<T>& DeckCard<T>::operator-(const T& min){
    for(int i = 0; i < this->deck.size(); i++){
        if(this->deck[i] == min){
            this->deck.erase(this->deck.begin() + i);
            this->neff--;
            break;
        }
    }
    return *this;
}

template <class T>
DeckCard<T>& DeckCard<T>::operator--(){
    this->pop();
    return *this;
}

template class DeckCard<Card>;
template class DeckCard<AbilityCard>;
template class DeckCard<UnoCard>;