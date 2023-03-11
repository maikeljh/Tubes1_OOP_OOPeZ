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

bool Card::operator> (Card& c){
    return this->value() > c.value();
}
bool Card::operator< (Card& c){
    return this->value() < c.value();
}
bool Card::operator== (Card& c){
    return this->value() == c.value();
}
int Card::getNumber(){
    return this->number;
}

string Card::getColor(){
    return this->color;
}

void Card::setNumber(int number) {
    this->number = number;
}

double Card::value(){
    // Implement High Card
    if(this->color == "Green"){
        return (this->number/10)+(0*0.03);
    }
    else if (this->color == "Blue"){
        return (this->number/10)+(1*0.03);
    }
    else if (this->color == "Yellow"){
        return (this->number/10)+(2*0.03);
    }
    else if (this->color == "Red"){
        return (this->number/10)+(3*0.03);
    }
}