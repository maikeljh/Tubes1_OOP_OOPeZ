#include "../../headers/Inventory/children/DeckCard/deckCard.hpp"
#include <iostream>

using namespace std;

DeckCard::DeckCard():DeckCard(0, 52){

}

DeckCard::DeckCard(int neff, int size): InventoryHolder(), neff(neff), size(size){
}

DeckCard::DeckCard(const DeckCard& dc){
    this->deck = dc.deck;
    this->neff = dc.neff;
    this->size = dc.size;
}

DeckCard::~DeckCard(){

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

int DeckCard::getNeff(){
    return this->neff;
}

int DeckCard::getSize(){
    return this->size;
}
void DeckCard::printDeckCard(){
    cout << "Isi dari deck sekarang :" << endl;
    for(int i = 0; i < this->neff; i++){
        cout << i+1 << ". " << this->deck[i].getNumber() <<  " " << this->deck[i].getColor() << endl;
    }
}

