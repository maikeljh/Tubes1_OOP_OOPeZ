#ifndef BASE_CARD_HPP
#define BASE_CARD_HPP
#include <iostream>
using namespace std;
class BaseCard {
    protected:
        int number;
        string color;

    public:
        BaseCard(int number, string color);
        int getNumber();
        string getColor();
        void setNumber(int number);
};

#endif