#include "../../headers/Inventory/children/DeckCard/deckCard.hpp"
#include <iostream>

using namespace std;

DeckCard::DeckCard():InventoryHolder(),neff(0){
    this->deck = new Card[this->size];
}

Card DeckCard::pop(){
    this->neff--;
    return this->deck[this->neff];
}

void DeckCard::push(const Card& Card){
    this->deck[this->neff] = Card;
    this->neff++;
}

void DeckCard::printDeckCard(){
    cout << "Isi dari deck sekarang :" << endl;
    for(int i = 0; i < this->neff; i++){
        cout << i+1 << ". " << this->deck[i].getNumber() <<  " " << this->deck[i].getColor() << endl;
    }
}

int DeckCard::getNeff(){
    return this->neff;
}

DeckCard::~DeckCard(){
    delete[] this->deck;
}