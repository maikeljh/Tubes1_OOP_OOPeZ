#include "../../../headers/Value/Card/card.hpp"
#include <iostream>

using namespace std;

/* ctor */
Card::Card():Value(){}

Card::Card(int number, string color):Value(){
    this->number = number;
    this->color = color;
}

/* operators */
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
bool Card::operator== (const Card& c){
    return (this->number == c.number && this->color == c.color);
}

/* getter */
int Card::getNumber(){
    return this->number;
}
string Card::getColor(){
    return this->color;
}

/* setter */
void Card::setNumber(int number) {
    this->number = number;
}
void Card::setColor(string color){
    this->color = color;
}

/* other functions */
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
    } else {
        return -1;
    }
}