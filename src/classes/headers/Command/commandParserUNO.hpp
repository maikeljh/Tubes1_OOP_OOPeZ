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
#include "./children/helpUno.hpp"
#include "../Exception/exception.h"

class CommandParserUNO{
    public:
        /* Ctor */
        CommandParserUNO();

        /* Method */
        Command<UnoGame> *parser(string inputCommand); // Parses input to create an object based on input
};

#endif