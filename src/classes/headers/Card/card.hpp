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
        int getNumber();
        string getColor();
};

#endif