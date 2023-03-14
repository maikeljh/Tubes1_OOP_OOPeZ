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
        DC = DC + randomize[i];
    }
    
    return DC;
}

DeckCard<AbilityCard> CardGenerator::generateAbilityDeck(){
    DeckCard<AbilityCard> DAC;
    vector<AbilityCard> temp;
    string abilities[7] = {"RE-ROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAPCARD", "SWITCH", "ABILITYLESS"};
    
    for(string ability : abilities){
        temp.push_back(AbilityCard(ability));
    }

    for(int i = 0 ; i < 7; i++){
        int randomIndex = rand() % (7-i);
        DAC = DAC + temp[randomIndex];
        temp.erase(temp.begin() + randomIndex);
    }

    return DAC;
}

DeckCard<Card> CardGenerator::readFile(string pathfile){
    string line;
    ifstream Read(pathfile);
    DeckCard<Card> DC;

    // Throw exception
    if(!Read.good()){
        throw FileInvalidExc();
    }

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
                        throw ConfigInvalidExc();
                    }
                } else {
                    throw ConfigInvalidExc();
                }
                break;
            }
            idx++;
        }

        // READ COLOR
        idx++;
        while(idx < line.length() && line[idx] != '\n' && line[idx] != '\r'){
            color += line[idx];
            idx++;
        }

        if(color != "Red" && color != "Yellow" && color != "Blue" && color != "Green"){
            throw ConfigInvalidExc();
        } else {
            DC = DC + Card(number, color);
        }
    }

    Read.close();

    return DC;
}

DeckCard<UnoCard> CardGenerator::randomizeUnoCard(){
    srand(time(0));
    DeckCard<UnoCard> DC;
    vector<UnoCard> temp, randomize;
    string colors[4] = {"Green", "Blue", "Yellow", "Red"};
    int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string typesWithColor[3] = {"PLUS2", "SKIP", "UNOREVERSE"};
    string typesWithoutColor[2] = {"PLUS4", "CHANGECOLOR"};
    
    for(string color : colors){
        for(int number : numbers){
            if(number != 0){
                temp.push_back(UnoCard(number, color, "NONE"));
            }
            temp.push_back(UnoCard(number, color, "NONE"));
        }
    }

    for(string color : colors){
        for(string type : typesWithColor){
            temp.push_back(UnoCard(10, color, type));
            temp.push_back(UnoCard(10, color, type));
        }
    }

    for(string type : typesWithoutColor){
        for(int i = 0; i < 4; i++){
            temp.push_back(UnoCard(10, "Black", type));
        }
    }

    for(int i = 0 ; i < 108; i++){
        int randomIndex = rand() % (108-i);
        randomize.push_back(temp[randomIndex]);
        temp.erase(temp.begin() + randomIndex);
    }

    while(randomize.size() != 0){
        DC = DC + randomize.back();
        randomize.pop_back();
    }

    return DC;
}

DeckCard<UnoCard> CardGenerator::readUnoFile(string pathfile){
    string line;
    ifstream Read(pathfile);
    DeckCard<UnoCard> DC;

    // Throw exception
    if(!Read.good()){
        throw FileInvalidExc();
    }
    
    // FORMAT YANG BENAR = ANGKA WARNA
    while(getline(Read, line)){
        int number;
        string sNumber = "";
        string color = "";
        string type = "";
        int idx = 0;

        // READ NUMBER
        while(idx < line.length()){
            if(line[idx] - '0' >= 0 && line[idx] - '0' < 10){
                sNumber += line[idx];
            } else {
                if(atoi(sNumber.c_str()) || sNumber == "0"){
                    number = atoi(sNumber.c_str());
                    if(number < 0 || number > 10){
                        throw ConfigInvalidExc();
                    }
                } else {
                    throw ConfigInvalidExc();
                }
                break;
            }
            idx++;
        }

        // READ COLOR
        idx++;
        while(idx < line.length() && line[idx] != ' '){
            color += line[idx];
            idx++;
        }

        if(color != "Red" && color != "Yellow" && color != "Blue" && color != "Green" && color != "Black"){
            throw ConfigInvalidExc();
        }

        // READ TYPE
        idx++;
        while(idx < line.length() && line[idx] != '\n' && line[idx] != '\r'){
            type += line[idx];
            idx++;
        }

        if(type != "PLUS2" && type != "PLUS4" && type != "SKIP" && type != "UNOREVERSE" && type != "CHANGECOLOR" && type != "NONE"){
            throw ConfigInvalidExc();
        }

        DC = DC + UnoCard(number, color, type);
    }

    Read.close();

    return DC;
}