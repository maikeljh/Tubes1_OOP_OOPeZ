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

class PickCard: public Command<UnoGame> {
    public:
        /* Ctor */
        PickCard();

        /* Methods */
        void executeAction(UnoGame&); // Choose card to use
        bool checkValid(UnoGame&); // Check if the current player can use one of their cards or not
};

#endif