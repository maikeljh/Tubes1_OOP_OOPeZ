#include "../../headers/Command/commandParserUNO.hpp"

using namespace std;

CommandParserUNO::CommandParserUNO(){}

Command* CommandParserUNO::parser(string inputCommand){
    if (inputCommand=="DRAW"){
        Draw *draw = new Draw();
        return draw;
    } else if (inputCommand=="PASS"){
        Pass *pass = new Pass();
        return pass;
    } else if (inputCommand=="SAYUNO"){
        SayUno *sayUno = new SayUno();
        return sayUno;
    } else {
        throw "Input tidak valid!";
    }

}