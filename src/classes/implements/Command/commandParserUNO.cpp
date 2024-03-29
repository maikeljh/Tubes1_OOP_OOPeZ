#include "../../headers/Command/commandParserUNO.hpp"

using namespace std;

/* Ctor */
CommandParserUNO::CommandParserUNO(){}

/* Parser */
Command<UnoGame>* CommandParserUNO::parser(string inputCommand){
    if (inputCommand == "DRAW"){
        Draw *draw = new Draw();
        return draw;
    } else if (inputCommand == "PASS"){
        Pass *pass = new Pass();
        return pass;
    } else if (inputCommand == "SAYUNO"){
        SayUno *sayUno = new SayUno();
        return sayUno;
    } else if (inputCommand == "PICKCARD"){
        PickCard *pickCard = new PickCard();
        return pickCard;
    } else if (inputCommand == "CHECKCARD") {
        SeeCards *seeCards = new SeeCards();
        return seeCards;
    } else if (inputCommand == "HELP") {
        HelpUno *helpUno = new HelpUno();
        return helpUno;  
    } else {
        throw CommandInvalidExc();
    }
}