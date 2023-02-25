#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
using namespace std;

class Card {
    protected:
        int number;
        string color;
    public:
        Card();
        Card(int number, string color);
        //Card(const Card& other);
        //~Card();
};

#endif