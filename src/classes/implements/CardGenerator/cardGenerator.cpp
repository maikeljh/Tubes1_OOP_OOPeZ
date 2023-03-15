#include "../../headers/CardGenerator/cardGenerator.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

CardGenerator::CardGenerator(){}

/* Randomize cards with rand() function */
DeckCard<Card> CardGenerator::randomizeCard(){
    // Initialize srand with time
    srand(time(0));

    // Initialize Variables and Objects
    DeckCard<Card> DC;
    vector<Card> temp, randomize;
    string colors[4] = {"Green", "Blue", "Yellow", "Red"};
    int numbers[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    // Create all cards based on colors and numbers that are defined
    for(string color : colors){
        for(int number : numbers){
            temp.push_back(Card(number, color));
        }
    }

    // Pick random index to push to final deck
    for(int i = 0 ; i < 52; i++){
        int randomIndex = rand() % (52-i);
        randomize.push_back(temp[randomIndex]);
        temp.erase(temp.begin() + randomIndex);
    }

    // Push randomize cards to deck card
    for(int i = 0 ; i < 52; i++){
        DC = DC + randomize[i];
    }
    
    return DC;
}

/* Generate ability deck */
DeckCard<AbilityCard> CardGenerator::generateAbilityDeck(){
    // Initialize Variables and Object
    DeckCard<AbilityCard> DAC;
    vector<AbilityCard> temp;
    string abilities[7] = {"RE-ROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAPCARD", "SWITCH", "ABILITYLESS"};
    
    // Push ability cards to array
    for(string ability : abilities){
        temp.push_back(AbilityCard(ability));
    }

    // Pick random index and push to final deck
    for(int i = 0 ; i < 7; i++){
        int randomIndex = rand() % (7-i);
        DAC = DAC + temp[randomIndex];
        temp.erase(temp.begin() + randomIndex);
    }

    return DAC;
}

/* Read order cards .txt file */
DeckCard<Card> CardGenerator::readFile(string pathfile){
    // Initialize variables and object
    string line;
    ifstream Read(pathfile);
    DeckCard<Card> DC;

    // Throw exception if read file failed
    if(!Read.good()){
        throw FileInvalidExc();
    }

    // Read .txt file per line
    while(getline(Read, line)){
        // Initialize variables to create card
        int number;
        string sNumber = "";
        string color = "";
        int idx = 0;

        // Read and Validate Number
        while(idx < line.length()){
            if(line[idx] - '0' >= 0 && line[idx] - '0' < 10){
                sNumber += line[idx];
            } else {
                if(atoi(sNumber.c_str())){
                    number = atoi(sNumber.c_str());
                    if(number < 1 || number > 13){
                        // Throw error if number out of range
                        throw ConfigInvalidExc();
                    }
                } else {
                    // Throw if its not a number
                    throw ConfigInvalidExc();
                }
                break;
            }
            idx++;
        }

        // Read and Validate Color
        idx++;
        while(idx < line.length() && line[idx] != '\n' && line[idx] != '\r'){
            color += line[idx];
            idx++;
        }

        // Throw error if color unrecognized
        if(color != "Red" && color != "Yellow" && color != "Blue" && color != "Green"){
            throw ConfigInvalidExc();
        } else {
            // Push new card to deck
            DC = DC + Card(number, color);
        }
    }

    Read.close();

    return DC;
}

/* Randomize Uno Cards */
DeckCard<UnoCard> CardGenerator::randomizeUnoCard(){
    // Initialize srand with time
    srand(time(0));

    // Initialize object and variables
    DeckCard<UnoCard> DC;
    vector<UnoCard> temp, randomize;
    string colors[4] = {"Green", "Blue", "Yellow", "Red"};
    int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string typesWithColor[3] = {"PLUS2", "SKIP", "UNOREVERSE"};
    string typesWithoutColor[2] = {"PLUS4", "CHANGECOLOR"};
    
    // Create UNO Basic Cards
    for(string color : colors){
        for(int number : numbers){
            if(number != 0){
                temp.push_back(UnoCard(number, color, "NONE"));
            }
            temp.push_back(UnoCard(number, color, "NONE"));
        }
    }

    // Create Ability Uno Cards With Color
    for(string color : colors){
        for(string type : typesWithColor){
            temp.push_back(UnoCard(10, color, type));
            temp.push_back(UnoCard(10, color, type));
        }
    }

    // Create Ability Uno Cards Without Color (Wild Cards)
    for(string type : typesWithoutColor){
        for(int i = 0; i < 4; i++){
            temp.push_back(UnoCard(10, "Black", type));
        }
    }

    // Pick random index to push to final deck
    for(int i = 0 ; i < 108; i++){
        int randomIndex = rand() % (108-i);
        randomize.push_back(temp[randomIndex]);
        temp.erase(temp.begin() + randomIndex);
    }

    // Push new cards to deck
    while(randomize.size() != 0){
        DC = DC + randomize.back();
        randomize.pop_back();
    }

    return DC;
}

/* Read order UNO cards .txt file */
DeckCard<UnoCard> CardGenerator::readUnoFile(string pathfile){
    // Initialize object and variables
    string line;
    ifstream Read(pathfile);
    DeckCard<UnoCard> DC;

    // Throw exception if read file failed
    if(!Read.good()){
        throw FileInvalidExc();
    }
    
    // Read file per line
    while(getline(Read, line)){
        // Initialize variables
        int number;
        string sNumber = "";
        string color = "";
        string type = "";
        int idx = 0;

        // Read and Validate Number
        while(idx < line.length()){
            if(line[idx] - '0' >= 0 && line[idx] - '0' < 10){
                sNumber += line[idx];
            } else {
                if(atoi(sNumber.c_str()) || sNumber == "0"){
                    number = atoi(sNumber.c_str());
                    if(number < 0 || number > 10){
                        // Throw error if number out of range
                        throw ConfigInvalidExc();
                    }
                } else {
                    // Throw error if config file format invalid
                    throw ConfigInvalidExc();
                }
                break;
            }
            idx++;
        }

        // Read and Validate Color
        idx++;
        while(idx < line.length() && line[idx] != ' '){
            color += line[idx];
            idx++;
        }

        if(color != "Red" && color != "Yellow" && color != "Blue" && color != "Green" && color != "Black"){
            // Throw error if color unrecognized
            throw ConfigInvalidExc();
        }

        // Read and Validate Type
        idx++;
        while(idx < line.length() && line[idx] != '\n' && line[idx] != '\r'){
            type += line[idx];
            idx++;
        }

        if(type != "PLUS2" && type != "PLUS4" && type != "SKIP" && type != "UNOREVERSE" && type != "CHANGECOLOR" && type != "NONE"){
            // Throw error if type unrecognized
            throw ConfigInvalidExc();
        }

        // Push UNO cards to deck
        DC = DC + UnoCard(number, color, type);
    }

    Read.close();

    return DC;
}