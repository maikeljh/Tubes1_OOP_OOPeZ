#ifndef CARD_HPP
#define CARD_HPP

#include "../value.hpp"
#include <iostream>
using namespace std;

class Card : public Value {
    protected:
        int number;
        string color; 

    public:
        Card();
        Card(int number, string color);
        Card& operator= (const Card&);
        int getNumber();
        string getColor();
        double value();
};

#endif