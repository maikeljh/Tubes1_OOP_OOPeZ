#include "../../headers/Command/commandParser.hpp"

using namespace std;

CommandParser::CommandParser(){}

Command* CommandParser::parser(string inputCommand){
    if (inputCommand=="NEXT"){
        Next *next = new Next();
        return next;
    } else if (inputCommand=="RE-ROLL"){
        ReRoll *reroll = new ReRoll();
        return reroll;
    } else if (inputCommand=="DOUBLE"){
        Double *doubles = new Double();
        return doubles;
    } else if (inputCommand=="QUADRUPLE"){
        Quadruple *quadruple = new Quadruple();
        return quadruple;
    } else if (inputCommand=="HALF"){
        Half *half = new Half();
        return half;
    } else if (inputCommand=="QUARTER"){
        Quarter *quarter = new Quarter();
        return quarter;
    } else if (inputCommand=="REVERSE"){
        Reverse *reverse = new Reverse();
        return reverse;
    } else if (inputCommand=="SWAP CARD"){
        SwapCard *swapcard = new SwapCard();
        return swapcard;
    } else if (inputCommand=="SWITCH"){
        Switch *switches = new Switch();
        return switches;
    } else if (inputCommand=="ABILITYLESS"){
        Abilityless *abilityless = new Abilityless();
        return abilityless;
    } else {
        throw "Command tidak valid";
    }
}