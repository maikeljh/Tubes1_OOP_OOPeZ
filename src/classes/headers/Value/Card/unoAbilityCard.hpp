#ifndef UNO_ABILITY_CARD_HPP
#define UNO_ABILITY_CARD_HPP

#include "abilityCard.hpp"

class UnoAbilityCard: public AbilityCard{
    private:
        string color;
    public:
        UnoAbilityCard();
        UnoAbilityCard(string color);
        UnoAbilityCard(const UnoAbilityCard& other);
};

#endif