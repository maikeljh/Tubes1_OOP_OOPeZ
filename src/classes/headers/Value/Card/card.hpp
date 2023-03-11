#ifndef CARD_HPP
#define CARD_HPP

#include "../value.hpp"
#include "../../BaseCard/baseCard.hpp"
#include <iostream>
using namespace std;

class Card : public Value, public BaseCard {
    public:
        Card();
        Card(int number, string color);
        Card& operator= (const Card&);
        bool operator> (Card&);
        bool operator< (Card&);
        bool operator== (Card&);
        double value();

};

#endif