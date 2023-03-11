#include "../../headers/Value/Card/unoAbilityCard.hpp"
#include <iostream>

using namespace std;

UnoAbilityCard::UnoAbilityCard(): AbilityCard(){
    this->color = "";
}

UnoAbilityCard::UnoAbilityCard(string color): AbilityCard(){
    this->color = color;
}

UnoAbilityCard::UnoAbilityCard(const UnoAbilityCard& other){
    this->color = other.color;
}