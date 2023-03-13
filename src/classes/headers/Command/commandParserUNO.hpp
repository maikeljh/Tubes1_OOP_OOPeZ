#ifndef COMMANDPARSER_UNO_HPP
#define COMMANDPARSER_UNO_HPP

#include "command.hpp"
#include "./children/pickCard.hpp"
#include "./children/pass.hpp"
#include "./children/changeColor.hpp"
#include "./children/draw.hpp"
#include "./children/skip.hpp"
#include "./children/plus2.hpp"
#include "./children/plus4.hpp"
#include "./children/sayUno.hpp"
#include "./children/unoReverse.hpp"
#include "./children/seeCards.hpp"

class CommandParserUNO{
    public:
        CommandParserUNO();
        Command* parser(string inputCommand);
};

#endif