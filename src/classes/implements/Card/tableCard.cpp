#include "../../headers/Value/Card/tableCard.hpp"
#include <iostream>

using namespace std;

TableCard::TableCard(int max):neff(0),max(max){}

void TableCard::addCard(const Card& C){
    if(neff < max){
        listOfCards.push_back(C);
        neff++;
    }
}

void TableCard::clearTable(){
    for(int i = 0; i < this->neff; i++){
        listOfCards.pop_back();
    }
    this->neff = 0;
}

void TableCard::printTable(){
    cout << "Isi dari table card sekarang :" << endl;
    for(int i = 0; i < this->neff; i++){
        cout << i+1 << ". " << this->listOfCards[i].getNumber() <<  " " << this->listOfCards[i].getColor() << endl;
    }
}

vector<Card>& TableCard::getTableCard() {
    return this->listOfCards;
}

TableCard::~TableCard(){}

int TableCard::getNeff(){
    return this->neff;
}