#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>

using namespace std;

class Command {
    protected:
        int commandId;
    
    public:
        Command();
        Command(int commandId);
        int commandParser(string command);
        virtual void useAbility(Game& Game);
        virtual void useAbility(DeckCard& DC, Game& Game);
};

#endif