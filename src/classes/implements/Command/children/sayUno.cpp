#include "../../../headers/Command/children/sayUno.hpp"

SayUno::SayUno():Command(){}

void SayUno::executeActionUNO(UnoGame& Game){
    UnoPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());
    if (playernow.getDeckPlayer().size() == 2){
        cout << "\nPemain " << playernow.getNickname() << " mengatakan UNO!" << endl;
        Game.setUNO(true);
    }
    else{
        cout << "\nKartumu tidak tersisa 2! Katakan UNO saat kartumu tersisa 2 dan akan mengeluarkan kartu!" << endl;
        cout << "\nKartu yang didapat oleh " << playernow.getNickname() << ":\n";
        playernow = playernow + Game.getDeckCard().pop();
        playernow = playernow + Game.getDeckCard().pop();
        int count = 0;
        while (count < 2){
            cout << count+1 << ". ";
            playernow.getCard(playernow.getDeckPlayer().size()+(count-2)).printDetail();
            count++;
        }
        cout << endl;
    }
}