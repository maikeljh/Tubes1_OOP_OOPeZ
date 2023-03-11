#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include "../Game/unoGame.hpp"
#include "../Game/candyGame.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"

using namespace std;

class Command {
    protected:
        int commandId;
    
    public:
        Command(){}
        Command(int commandId){this->commandId = commandId;}
        virtual void executeAction(CandyGame&){};
        virtual void executeActionUNO(UnoGame&){};
};

#endif