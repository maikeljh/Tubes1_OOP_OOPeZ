#ifndef SKIP_HPP
#define SKIP_HPP

#include "../command.hpp"
#include "../../Game/game.hpp"
class Skip: public Command {
public:
    Skip();
    void executeActionUNO(UnoGame&);
};

#endif