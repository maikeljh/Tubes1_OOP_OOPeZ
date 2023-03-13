#include "../../../headers/Command/children/sayUno.hpp"

SayUno::SayUno():Command(){}

void SayUno::executeActionUNO(UnoGame& Game){
    UnoPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());
    if (playernow.getDeckPlayer().size() == 2){
        Game.setUNO(true);
    }
    else{
        cout << "Kartumu tidak tersisa 1! Katakan UNO saat kartumu tersisa 2 dan akan mengeluarkan kartu!" << endl;
        cout << "\nKartu yang didapat oleh " << playernow.getNickname() << ":\n";
        playernow.push(Game.getDeckCard().pop());
        playernow.push(Game.getDeckCard().pop());
    }
}