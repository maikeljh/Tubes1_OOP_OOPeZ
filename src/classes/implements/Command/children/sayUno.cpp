#include "../../../headers/Command/children/sayUno.hpp"

SayUno::SayUno():Command(){}

void SayUno::executeActionUNO(UnoGame& Game){
    UnoPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());
    if (playernow.getDeckPlayer().size() == 2){
        
    }
    else{
        playernow.push(Game.getDeckCard().pop());
        playernow.push(Game.getDeckCard().pop());
    }
}