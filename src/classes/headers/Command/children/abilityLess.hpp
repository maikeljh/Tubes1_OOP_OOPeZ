#ifndef ABILITY_LESS_HPP
#define ABILITY_LESS_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class Abilityless: public Command {
    public:
        Abilityless(); // ID = 10
        void offAbility(const Game& Game);
};

#endif