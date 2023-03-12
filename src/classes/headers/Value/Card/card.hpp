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
        bool operator> (Card&);
        bool operator< (Card&);
        virtual bool operator== (Card&);
        int getNumber();
        string getColor();
        void setNumber(int number);
        void setColor(string color);
        double value();

};

#endif