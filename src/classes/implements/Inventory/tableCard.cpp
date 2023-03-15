#include "../../headers/Inventory/children/TableCard/tableCard.hpp"
#include <iostream>

using namespace std;

/* Ctor */
template <class T>
TableCard<T>::TableCard(int max):neff(0),max(max){}

/* Getter */
template <class T>
vector<T>& TableCard<T>::getTableCard() {
    return this->listOfCards;
}

template <class T>
int TableCard<T>::getNeff(){
    return this->neff;
}

template <class T>
T& TableCard<T>::getTop(){
    return this->listOfCards.back();
}

/* Other Methods */
template <class T>
void TableCard<T>::push(const T& C){
    if(neff < max){
        listOfCards.push_back(C);
        neff++;
    }
}

template <class T>
T TableCard<T>::pop(){
    T C;
    if(this->neff > 0){
        this->neff--;
        C = this->listOfCards.back();
        this->listOfCards.pop_back();
        return C;
    } else {
        cout << "\nTable sudah kosong" << endl;
        return C;
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