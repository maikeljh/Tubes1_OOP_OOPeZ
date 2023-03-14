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
        /* ctor */
        Card();
        Card(int number, string color);

        /* operators */
        Card& operator= (const Card&);
        bool operator> (Card&);
        bool operator< (Card&);
        virtual bool operator== (const Card&);

        /* getter */
        int getNumber();
        string getColor();

        /* setter */
        void setNumber(int number);
        void setColor(string color);

        /* other functions */
        double value();

};

#endif