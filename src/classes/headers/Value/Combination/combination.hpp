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
        void setComboCard(vector <Card> &combo);
        void clearCombo();
        void mergeCard(vector <Card> &TC, vector <Card> &PC);
        void makeCombo();
        void printCombo();
        bool operator> (Combination&);
        bool operator< (Combination&);
        bool operator== (Combination&);
        bool isStraightFlush();
        bool isFourOfaKind();
        bool isFullHouse();
        bool isFlush();
        bool isStraight();
        bool isThreeOfaKind();
        bool isTwoPair();
        bool isPair();
        void straightFlush();
        void fourOfaKind();
        void fullHouse();
        void flush();
        void straight();
        void threeOfaKind();
        void twoPair();
        void pair();
        void quicksort(vector <Card>& CC, int low, int high);

};

#endif