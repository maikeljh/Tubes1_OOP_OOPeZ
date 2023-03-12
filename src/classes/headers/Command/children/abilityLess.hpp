#ifndef ABILITY_LESS_HPP
#define ABILITY_LESS_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"
#include "next.hpp"

using namespace std;

class Abilityless: public Command {
    public:
        Abilityless(); // ID = 10
        void executeAction(CandyGame& Game);
        bool isAllAbilityUsed(vector<CandyPlayer> players);
};

#endif