#ifndef SKIP_HPP
#define SKIP_HPP

#include "../command.hpp"
#include "../../Game/unoGame.hpp"

class Skip: public Command<UnoGame> {
    public:
        /* Ctor */
        Skip();

        /* Method */
        void executeAction(UnoGame&); // Skip the next player turn
};

#endif