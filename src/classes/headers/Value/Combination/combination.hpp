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
        double value(vector<Card> &LC);
        double getValue();
        string getCombo();
        void setValue(double);
        void setCombo(string);
        void setComboCard(vector <Card> &combo);
        vector<Card> mergeCard(vector <Card> &TC, vector <Card> &PC);
        int compareTwoCombo(vector <Card> &CC1, vector <Card> &CC2);
        bool isStraightFlush(vector <Card> &LC);
        bool isFourOfaKind(vector <Card> &LC);
        bool isFullHouse(vector <Card> &LC);
        bool isFlush(vector <Card> &LC);
        bool isStraight(vector <Card> &LC);
        bool isThreeOfaKind(vector <Card> &LC);
        bool isTwoPair(vector <Card> &LC);
        bool isPair(vector <Card> &LC);
        vector<Card> straightFlush(vector <Card> &LC);
        vector<Card> fourOfaKind(vector <Card> &LC);
        vector<Card> fullHouse(vector <Card> &LC);
        vector<Card> flush(vector <Card> &LC);
        vector<Card> straight(vector <Card> &LC);
        vector<Card> threeOfaKind(vector <Card> &LC);
        vector<Card> twoPair(vector <Card> &LC);
        vector<Card> pair(vector <Card> &LC);

};

#endif