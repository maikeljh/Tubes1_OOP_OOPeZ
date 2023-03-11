#include "../../headers/Value/Card/card.hpp"
#include <iostream>

using namespace std;

Card::Card():Value(),BaseCard(){}

Card::Card(int number, string color):Value(),BaseCard(number, color){}

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

double Card::value(){
    // Implement High Card
    if(this->color == "Green"){
        return ((1.0 * this->number) /10)+(0*0.03);
    }
    else if (this->color == "Blue"){
        return ((1.0 * this->number)/10)+(1*0.03);
    }
    else if (this->color == "Yellow"){
        return ((1.0 * this->number)/10)+(2*0.03);
    }
    else if (this->color == "Red"){
        return ((1.0 * this->number)/10)+(3*0.03);
    }
}