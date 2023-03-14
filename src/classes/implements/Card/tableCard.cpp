#include "../../headers/Value/Card/tableCard.hpp"
#include <iostream>

using namespace std;

template <class T>
TableCard<T>::TableCard(int max):neff(0),max(max){}

template <class T>
void TableCard<T>::push(const T& C){
    if(neff < max){
        listOfCards.push_back(C);
        neff++;
    }
}

template <class T>
void TableCard<T>::clearTable(){
    for(int i = 0; i < this->neff; i++){
        listOfCards.pop_back();
    }
    this->neff = 0;
}

template <>
void TableCard<Card>::printCard(){
    cout << "Isi dari table card sekarang :" << endl;
    for(int i = 0; i < this->neff; i++){
        cout << i+1 << ". " << this->listOfCards[i].getNumber() <<  " " << this->listOfCards[i].getColor() << endl;
    }
}

template <>
void TableCard<UnoCard>::printCard(){
    cout << "Isi dari table card sekarang :" << endl;
    for(int i = 0; i < this->neff; i++){
        cout << i+1 << ". " << this->listOfCards[i].getNumber() <<  " " << this->listOfCards[i].getColor() << " " << this->listOfCards[i].getType()  << endl;
    }
}

template <class T>
vector<T>& TableCard<T>::getTableCard() {
    return this->listOfCards;
}

template <class T>
TableCard<T>::~TableCard(){}

template <class T>
int TableCard<T>::getNeff(){
    return this->neff;
}

template <class T>
T& TableCard<T>::getTop(){
    return this->listOfCards.back();
}

template <class T>
T TableCard<T>::pop(){
    return this->listOfCards.back();
}