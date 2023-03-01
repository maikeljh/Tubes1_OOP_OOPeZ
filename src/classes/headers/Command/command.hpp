#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include "../Game/game.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"

using namespace std;

class Command {
    protected:
        int commandId;
    
    public:
        Command(){}
        Command(int commandId){this->commandId = commandId;}
        virtual void executeAction(Game& Game)=0;
        virtual void executeAction(DeckCard<Card>& DC, Game& Game)=0;
};

#endif