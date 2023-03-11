#include "../../headers/Value/Combination/combination.hpp"
#include "../generic.cpp"
#include <iostream>

using namespace std;

Combination::Combination(){}

double Combination::getValue(){
    return this->point;
}

string Combination::getCombo() {
    return this->combo;
}

void Combination::setValue(double value) {
    this->point = value;
}

void Combination::setCombo(string combo) {
    this->combo = combo;
}

Combination::~Combination() {

}

double Combination::value(vector<Card> &LC) {

    //straight flush

    //four of a kind

    //full house

    //flush

    //straight

    //three of a kind

    //two pair

    //pair

    //highcard max value 
}

void quicksort(vector <Card>& CC, int low, int high) {
    if (low < high) {
        int pivot = CC[high].value();
        int i = low-1;
        for (int j = low; j < high; j++) {
            if (CC[j].value() <= pivot) {
                i += 1;
                Card temp = CC[i];
                CC[i] = CC[j];
                CC[j] = temp;
            }
        }
        Card temp = CC[i+1];
        CC[i+1] = CC[high];
        CC[high] = temp;
        int pi = i + 1;

        quicksort(CC, low, pi-1);
        quicksort(CC, pi+1, high);
    }

}

vector<Card> Combination::mergeCard(vector <Card> &TC, vector <Card> &PC) {
    vector <Card> CC;
    for (int i = 0; i < 5; i++) {
        Card temp = TC[i];
        CC.push_back(temp);
    }

    for (int i = 0; i < 2; i++) {
        Card temp = PC[i];
        CC.push_back(temp);
    }

    // Sorting card berdasarkan angka dan warnanya

    quicksort(CC, 0, TC.size()-1);
}

int Combination::compareTwoCombo(vector <Card> &CC1, vector <Card> &CC2) {

}