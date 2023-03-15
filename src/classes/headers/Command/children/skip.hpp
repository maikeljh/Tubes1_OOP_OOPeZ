#ifndef SKIP_HPP
#define SKIP_HPP

#include "../command.hpp"
#include "../../Game/unoGame.hpp"
class Skip: public Command<UnoGame> {
    public:
        Skip();
        void executeAction(UnoGame&);
};

#endif