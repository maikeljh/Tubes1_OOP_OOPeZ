#ifndef ABILITY_LESS_HPP
#define ABILITY_LESS_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"
#include "next.hpp"

using namespace std;

class Abilityless: public Command<CandyGame> {
    public:
        /* Ctor */
        Abilityless();

        /* Methods */
        void executeAction(CandyGame& Game); // Execute abilityless
        bool isAllAbilityUsed(vector<CandyPlayer> players); // Check if all other players have used their ability or not
};

#endif