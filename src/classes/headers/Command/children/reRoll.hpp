#ifndef RE_ROLL_HPP
#define RE_ROLL_HPP

#include <iostream>
#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class ReRoll: public Command {
    public:
        ReRoll(); // ID = 2
        void useAbility(DeckCard<AbilityCard>& DeckCard, Game& Game);
};

#endif