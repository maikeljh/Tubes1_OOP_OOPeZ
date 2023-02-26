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
        Command();
        Command(int commandId);
        int commandParser(string command);
        virtual void useAction(Game& Game);
        virtual void useAbility(Game& Game);
        virtual void useAbility(DeckCard& DC, Game& Game);
};

#endif