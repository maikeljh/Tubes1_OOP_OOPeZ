#ifndef COMMANDPARSER_HPP
#define COMMANDPARSER_HPP

#include "command.hpp"
#include "./children/next.hpp"
#include "./children/reRoll.hpp"
#include "./children/double.hpp"
#include "./children/quadruple.hpp"
#include "./children/half.hpp"
#include "./children/quarter.hpp"
#include "./children/reverse.hpp"
#include "./children/swapCard.hpp"
#include "./children/switch.hpp"
#include "./children/abilityLess.hpp"

class CommandParser{
public:
    Command* parser(string inputCommand);
};

#endif