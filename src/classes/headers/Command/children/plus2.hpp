#ifndef PLUS2_HPP
#define PLUS2_HPP

#include "../command.hpp"
#include "../../Game/unoGame.hpp"
#include "skip.hpp"
using namespace std;

class Plus2 : public Command<UnoGame>{
    public:
        /* Ctor */
        Plus2();

        /* Method */
        void executeAction(UnoGame&); // Give the next player additional two cards and skip his/her turn
};

#endif