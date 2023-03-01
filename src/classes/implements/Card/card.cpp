#include "../../headers/Value/Card/card.hpp"
#include <iostream>

using namespace std;

Card::Card():Value(){
    this->number = 0;
    this->color = "";
}

Card::Card(int number, string color):Value(){
    this->number = number;
    this->color = color;
}


Card& Card::operator=(const Card& C) {
    this->number = C.number;
    this->color = C.color;
    return *this;
}

int Card::getNumber(){
    return this->number;
}

string Card::getColor(){
    return this->color;
}

double Card::value(){
    // Implement High Card
}