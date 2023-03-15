#ifndef PLUS4_HPP
#define PLUS4_HPP

#include "../command.hpp"
#include "../../Game/game.hpp"
#include "skip.hpp"
using namespace std;

class Plus4 : public Command<UnoGame>{
    public:
        /* Ctor */
        Plus4();

        /* Method */
        void executeAction(UnoGame&); // Give the next player additional four cards, skip his/her turn, and choose color
};

#endif