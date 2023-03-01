#ifndef RE_ROLL_HPP
#define RE_ROLL_HPP

#include <iostream>
#include "../command.hpp"
#include "next.hpp"
#include "../../Game/game.hpp"

using namespace std;

class ReRoll: public Command {
    public:
        ReRoll(); // ID = 2
        void useAbility(DeckCard<Card>& DeckCard, Game& Game);
};

#endif