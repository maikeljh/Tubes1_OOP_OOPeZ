#include "../../headers/Value/Card/abilityCard.hpp"
#include <iostream>

using namespace std;

/* ctor */
AbilityCard::AbilityCard(){
    this->type = "";
    this->useable = false;
}

AbilityCard::AbilityCard(string type){
    this->type = type;
    this->useable = true;
}

AbilityCard::AbilityCard(const AbilityCard& other){
    this->type = other.type;
    this->useable = other.useable;
}

/* getter */
string AbilityCard::getType(){
    return this->type;
}
bool AbilityCard::getUseable(){
    return this->useable;
}

/* setter */
void AbilityCard::setUseable(bool isUsable){
    useable = isUsable;
}
void AbilityCard::setType(string type){
    this->type = type;
}

bool AbilityCard::operator==(const AbilityCard& other){
    bool valid = other.type == this->type;
    return valid;
}