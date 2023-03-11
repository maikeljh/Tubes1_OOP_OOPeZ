#include "../../headers/Value/Combination/combination.hpp"
#include "../generic.cpp"
#include <iostream>
#include <map>

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

bool Combination::isStraightFlush(vector <Card> &LC) {
    bool temp;
    for (int i = LC.size()-1 ; i >= 4; i--) {
        temp = true;
        for (int j = i; j > i-4; j--) {
            if (LC[j].getNumber()-1 != LC[j-1].getNumber()-1 || LC[j].getColor() != LC[j-1].getColor()) {
                temp = false;
            }
        }
        if (temp == true) {
            break;
        }
    }
    return temp;
}

bool Combination::isStraight(vector <Card> &LC) {
    bool temp;
    for (int i = LC.size()-1 ; i >= 4; i--) {
        temp = true;
        for (int j = i; j > i-4; j--) {
            if (LC[j].getNumber()-1 != LC[j-1].getNumber()) {
                temp = false;
            }
        }
        if (temp == true) {
            break;
        }
    }
    return temp;
}

bool Combination::isFlush(vector <Card> &LC) {
    map<string, int> dictWarna;
    map<string,int>::iterator itr;
    dictWarna["Green"] = 0;
    dictWarna["Red"] = 0;
    dictWarna["Yellow"] = 0;
    dictWarna["Blue"] = 0;

    for (int i = 0; i < LC.size(); i++) {
        if (LC[i].getColor() == "Green") {
            dictWarna["Green"]++;
        }
        else if (LC[i].getColor() == "Blue") {
            dictWarna["Blue"]++;
        }
        else if (LC[i].getColor() == "Yellow") {
            dictWarna["Yellow"]++;
        }
        else {
            dictWarna["Red"]++;
        }
    }

    for (itr = dictWarna.begin(); itr != dictWarna.end(); itr++) {
        if (itr->second == 5) {
            return true;
        }
    }
    return false;
}

vector<Card> Combination::straightFlush(vector<Card> &LC) {
    vector <Card> combo;
    int index;
    for (int i = LC.size()-1 ; i >= 4; i--) {
        bool temp = true;
        for (int j = i; j > i-4; j--) {
            if (LC[j].getNumber()-1 != LC[j-1].getNumber()-1 || LC[j].getColor() != LC[j-1].getColor()) {
                temp = false;
            }
        }
        if (temp == true) {
            index = i;
            break;
        }
    }

    for (int i = index-4; i < index+1; i++) {
        combo.push_back(LC[i]);
    }

    return combo;
}

vector<Card> Combination::straight(vector<Card> &LC) {
    int index;
    vector <Card> combo;
    for (int i = LC.size()-1 ; i >= 4; i--) {
        bool temp = true;
        for (int j = i; j > i-4; j--) {
            if (LC[j].getNumber()-1 != LC[j-1].getNumber()) {
                temp = false;
            }
        }
        if (temp == true) {
            break;
        }
    }

    for (int i = index-4; i < index+1; i++) {
        combo.push_back(LC[i]);
    }

    return combo;
}

vector<Card> Combination::flush(vector<Card> &LC) {
    map<string, int> dictWarna;
    map<string,int>::iterator itr;
    string warna;
    dictWarna["Green"] = 0;
    dictWarna["Red"] = 0;
    dictWarna["Yellow"] = 0;
    dictWarna["Blue"] = 0;

    for (int i = 0; i < LC.size(); i++) {
        if (LC[i].getColor() == "Green") {
            dictWarna["Green"]++;
        }
        else if (LC[i].getColor() == "Blue") {
            dictWarna["Blue"]++;
        }
        else if (LC[i].getColor() == "Yellow") {
            dictWarna["Yellow"]++;
        }
        else {
            dictWarna["Red"]++;
        }
    }

    for (itr = dictWarna.begin(); itr != dictWarna.end(); itr++) {
        if (itr->second == 5) {
            warna = itr->first;
        }
    }

    vector<Card> combo;
    for (int i = 0; i < LC.size(); i++) {
        if (LC[i].getColor() == warna) {
            combo.push_back(LC[i]);
        }
    }

    return combo;
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