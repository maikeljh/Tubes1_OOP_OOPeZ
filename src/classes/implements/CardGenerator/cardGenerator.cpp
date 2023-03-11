#include "../../headers/CardGenerator/cardGenerator.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

CardGenerator::CardGenerator(){}

DeckCard<Card> CardGenerator::randomizeCard(){
    srand(time(0));
    DeckCard<Card> DC;
    vector<Card> temp, randomize;
    string colors[4] = {"Green", "Blue", "Yellow", "Red"};
    int numbers[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    for(string color : colors){
        for(int number : numbers){
            temp.push_back(Card(number, color));
        }
    }

    for(int i = 0 ; i < 52; i++){
        int randomIndex = rand() % (52-i);
        randomize.push_back(temp[randomIndex]);
        temp.erase(temp.begin() + randomIndex);
    }

    for(int i = 0 ; i < 52; i++){
        DC.push(randomize[i]);
    }

    return DC;
}

DeckCard<AbilityCard> CardGenerator::generateAbilityDeck(){
    DeckCard<AbilityCard> DAC;
    vector<AbilityCard> temp;
    string abilities[7] = {"Re-Roll", "Quadruple", "Quarter", "Reverse Direction", "Swap Card", "Switch", "Abilityless"};
    
    for(string ability : abilities){
        temp.push_back(AbilityCard(ability));
    }

    for(int i = 0 ; i < 7; i++){
        int randomIndex = rand() % (7-i);
        DAC.push(temp[randomIndex]);
        temp.erase(temp.begin() + randomIndex);
    }

    return DAC;
}

DeckCard<Card> CardGenerator::readFile(string pathfile){
    string line;
    ifstream Read(pathfile);
    DeckCard<Card> DC;

    // FORMAT YANG BENAR = ANGKA WARNA
    while(getline(Read, line)){
        int number;
        string sNumber = "";
        string color = "";
        int idx = 0;

        // READ NUMBER
        while(idx < line.length()){
            if(line[idx] - '0' >= 0 && line[idx] - '0' < 10){
                sNumber += line[idx];
            } else {
                if(atoi(sNumber.c_str())){
                    number = atoi(sNumber.c_str());
                    if(number < 1 || number > 13){
                        cout << "Out of range gan";
                        throw "Out of range gan";
                    }
                } else {
                    cout << "Bukan angka bang";
                    throw "Bukan angka bang";
                }
                break;
            }
            idx++;
        }

        // READ COLOR
        idx++;
        while(idx < line.length()){
            color += line[idx];
            idx++;
        }

        if(color != "Red" && color != "Yellow" && color != "Blue" && color != "Green"){
            cout << "Bukan warna yang valid say";
            throw "Bukan warna yang valid say";
        } else {
            DC.push(Card(number, color));
        }
    }

    Read.close();
    //DC.printDeckCard();

    return DC;
}

// Testing
// g++ cardGenerator.cpp ../Inventory/deckCard.cpp ../Card/card.cpp ../Inventory/inventoryHolder.cpp ../Inventory/deckAbilityCard.cpp ../Card/abilityCard.cpp -o tes
/*
int main(){
    CardGenerator CG;
    DeckCard<Card> DC = CG.randomizeCard();
    DeckCard<AbilityCard> DAC = CG.generateAbilityDeck();
    DeckCard DCFile = CG.readFile("../../../../config/orderCards.txt");
}
*/