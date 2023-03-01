#include "../../headers/Value/Card/abilityCard.hpp"
#include <iostream>

using namespace std;

AbilityCard::AbilityCard(){
    this->owner = -1;
    this->type = "";
    this->useable = false;
}

AbilityCard::AbilityCard(string type){
    this->owner = -1;
    this->type = type;
    this->useable = false;
}

AbilityCard::AbilityCard(int owner, string type){
    this->owner = owner;
    this->type = type;
    this->useable = true;
}

AbilityCard::AbilityCard(const AbilityCard& other){
    this->owner = other.owner;
    this->type = other.type;
    this->useable = other.useable;
}

int AbilityCard::getOwner(){
    return this->owner;
}

string AbilityCard::getType(){
    return this->type;
}

bool AbilityCard::getUseable(){
    return this->useable;
}