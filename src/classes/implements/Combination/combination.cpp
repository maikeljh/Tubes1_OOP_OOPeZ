#include "../../headers/Value/Combination/combination.hpp"
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

double Combination::value() {

}

void quicksort(vector <Card>& CC, int low, int high) {
    if (low < high) {
        int pivot = CC[high].getNumber();
        int i = low-1;
        for (int j = low; j < high; j++) {
            if (CC[j].getNumber() <= pivot) {
                i += 1;
                int temp = CC[i].getNumber();
                CC[i].setNumber(CC[j].getNumber());
                CC[j].setNumber(temp);
            }
        }
        int temp = CC[i+1].getNumber();
        CC[i+1].setNumber(CC[high].getNumber());
        CC[high].setNumber(temp);
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