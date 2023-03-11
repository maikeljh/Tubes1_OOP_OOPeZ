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
    bool urutan = true;
    bool warnasama = true;
    for(int i = 1; i<LC.size();i++){
        if(LC[i].getNumber()!=LC[i-1].getNumber()-1){
            urutan = false;
        }
        if (LC[i].getColor()!=LC[i-1].getColor()){
            warnasama = false;
        }
    }

    //straight flush
    if(urutan && warnasama){
        this->combo = "Straight Flush";
        this->comboCard = LC;
        this->point= maxValue(LC).value() + 12.32; //ktnya highcardnya hrs pake maxvalue di generic
    }

    //four of a kind

    //full house

    //flush

    //straight

    //three of a kind

    //two pair

    //pair

    //highcard max value 
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

    for (int i = 0; i < CC.size(); i++) {
        
    }
}

int Combination::compareTwoCombo(vector <Card> &CC1, vector <Card> &CC2) {

}