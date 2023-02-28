#include "../../headers/Inventory/children/DeckCard/deckAbilityCard.hpp"
#include <iostream>

using namespace std;

DeckAbilityCard::DeckAbilityCard():InventoryHolder(), neff(0){

}

AbilityCard DeckAbilityCard::pop(){
    this->neff--;
    AbilityCard AC = this->deck[this->neff];
    this->deck.pop_back();
    return AC;
}

void DeckAbilityCard::push(const AbilityCard& Card){
    this->deck.push_back(Card);
    this->neff++;
}

void DeckAbilityCard::printDeckCard(){
    cout << "Isi dari deck ability sekarang :" << endl;
    for(int i = 0; i < this->neff; i++){
        cout << i+1 << ". " << this->deck[i].getType() << endl;
    }
}

DeckAbilityCard::~DeckAbilityCard(){

}