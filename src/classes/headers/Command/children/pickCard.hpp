#ifndef PICK_CARD_HPP
#define PICK_CARD_HPP


#include "../command.hpp"
#include "../../Game/game.hpp"

using namespace std;

class PickCard: public Command {
    public:
        PickCard();
        void executeActionUNO(UnoGame&);
};

#endif