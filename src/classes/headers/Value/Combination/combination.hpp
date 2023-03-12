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
        vector<Card> playerCard;
        vector<Card> tableCard;
    public:
        Combination();
        ~Combination();
        double value();
        double getValue();
        string getCombo();
        void setValue(double);
        void setCombo(string);
        void setComboCard(vector <Card> &combo);
        void setPlayerCard(vector<Card> &PC);
        void setTableCard(vector<Card> &TC);
        void clearCombo();
        void mergeCard(vector <Card> &TC, vector <Card> &PC);
        void makeCombo();
        void printCombo();
        bool existPlayerCard();
        bool operator> (Combination&);
        bool operator< (Combination&);
        bool operator== (Combination&);
        bool isPlayerCard(Card &);
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