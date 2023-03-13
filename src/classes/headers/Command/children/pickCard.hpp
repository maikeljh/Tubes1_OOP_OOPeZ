#ifndef PICK_CARD_HPP
#define PICK_CARD_HPP


#include "../command.hpp"
#include "../../Game/game.hpp"
#include "plus2.hpp"
#include "plus4.hpp"
#include "skip.hpp"
#include "unoReverse.hpp"
#include "changeColor.hpp"
#include "pass.hpp"

using namespace std;

class PickCard: public Command {
    public:
        PickCard();
        void executeActionUNO(UnoGame&);
        bool checkValid(UnoGame&);
};

#endif