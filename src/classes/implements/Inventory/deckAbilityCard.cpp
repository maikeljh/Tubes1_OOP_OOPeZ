#include "../../headers/Inventory/children/DeckCard/deckAbilityCard.hpp"
#include <iostream>

using namespace std;

DeckAbilityCard::DeckAbilityCard():InventoryHolder(), neff(0){
    this->deck = new AbilityCard[this->size];
}

AbilityCard DeckAbilityCard::pop(){
    this->neff--;
    return this->deck[this->neff];
}

void DeckAbilityCard::push(const AbilityCard& Card){
    this->deck[this->neff] = Card;
    this->neff++;
}

void DeckAbilityCard::printDeckCard(){
    cout << "Isi dari deck ability sekarang :" << endl;
    for(int i = 0; i < this->neff; i++){
        cout << i+1 << ". " << this->deck[i].getType() << endl;
    }
}

DeckAbilityCard::~DeckAbilityCard(){
    delete[] this->deck;
}