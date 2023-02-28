#include "../../headers/Inventory/children/DeckCard/deckCard.hpp"
#include <iostream>

using namespace std;

DeckCard::DeckCard():InventoryHolder(),neff(0){

}

Card DeckCard::pop(){
    this->neff--;
    Card C = this->deck[this->neff];
    this->deck.pop_back();
    return this->deck[this->neff];
}

void DeckCard::push(const Card& Card){
    this->deck.push_back(Card);
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

}