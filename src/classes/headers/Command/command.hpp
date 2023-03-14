#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include "../Game/unoGame.hpp"
#include "../Game/candyGame.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Exception/exception.h"

using namespace std;

class Command {
    protected:
        int commandId;
    
    public:
        /* ctor */
        Command(){}
        Command(int commandId){this->commandId = commandId;}
        
        /* getter */
        int getCommandId();

        /* other functions */        
        virtual void executeAction(CandyGame&){};
        virtual void executeActionUNO(UnoGame&){};
};

#endif