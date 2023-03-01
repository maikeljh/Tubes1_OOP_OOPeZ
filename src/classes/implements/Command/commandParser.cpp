#include "../../headers/Command/commandParser.hpp"

Command* CommandParser::parser(string inputCommand){
    if (inputCommand=="NEXT"){
        Next *next;
        return next;
    } else if (inputCommand=="RE-ROLL"){
        ReRoll *reroll;
        return reroll;
    } else if (inputCommand=="DOUBLE"){
        Double *doubles;
        return doubles;
    } else if (inputCommand=="QUADRUPLE"){
        Quadruple *quadruple;
        return quadruple;
    } else if (inputCommand=="HALF"){
        Half *half;
        return half;
    } else if (inputCommand=="QUARTER"){
        Quarter *quarter;
        return quarter;
    } else if (inputCommand=="REVERSE"){
        Reverse *reverse;
        return reverse;
    } else if (inputCommand=="SWAP CARD"){
        SwapCard *swapcard;
        return swapcard;
    } else if (inputCommand=="SWITCH"){
        Switch *switches;
        return switches;
    } else if (inputCommand=="ABILITYLESS"){
        Abilityless *abilityless;
        return abilityless;
    }
}