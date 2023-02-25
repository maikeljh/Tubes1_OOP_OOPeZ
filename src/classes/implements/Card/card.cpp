#include "../../headers/Card/card.hpp"
#include <iostream>

using namespace std;

Card::Card(){
    this->number = 0;
    this->color = "";
}

Card::Card(int number, string color){
    this->number = number;
    this->color = color;
}

int Card::getNumber(){
    return this->number;
}

string Card::getColor(){
    return this->color;
}