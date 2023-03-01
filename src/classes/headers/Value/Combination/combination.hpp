#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include "../Card/card.hpp"
#include "../Card/tableCard.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Combination {
    private:
        double point;
        string combo;
        vector<Card> comboCard;
    public:
        Combination();
        ~Combination();
        double value();
        double getValue();
        string getCombo();
        void setValue(double);
        void setCombo(string);
        vector<Card> mergeCard(vector <Card> &TC, vector <Card> &PC);
        int compareTwoCombo(vector <Card> &CC1, vector <Card> &CC2);
};

#endif