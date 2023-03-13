#include "../../../headers/Command/children/sayUno.hpp"

SayUno::SayUno():Command(){}

void SayUno::executeActionUNO(UnoGame& Game){
    UnoPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());
    if (playernow.getDeckPlayer().size() == 2){
        
    }
    else{
        cout << "Kartumu tidak tersisa 1! Katakan UNO saat kartumu tersisa 2 dan akan mengeluarkan kartu!" << endl;
        playernow.push(Game.getDeckCard().pop());
        playernow.push(Game.getDeckCard().pop());
    }
}