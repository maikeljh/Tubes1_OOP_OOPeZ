#include "../../headers/BaseCard/baseCard.hpp"
#include <iostream>

using namespace std;

BaseCard::BaseCard(){}

BaseCard::BaseCard(int number, string color){
    this->number = number;
    this->color = color;
}

int BaseCard::getNumber(){
    return this->number;
}

string BaseCard::getColor(){
    return this->color;
}

void BaseCard::setNumber(int number) {
    this->number = number;
}