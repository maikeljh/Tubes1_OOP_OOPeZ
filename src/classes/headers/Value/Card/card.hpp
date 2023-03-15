#ifndef CARD_HPP
#define CARD_HPP

#include "../value.hpp"
#include <iostream>
using namespace std;

class Card : public Value {
    protected:
        int number; // The number of the card
        string color; // The color of the card

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

        /* other methods */
        double value();

};

#endif