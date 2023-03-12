#include "../../../headers/Command/children/quarter.hpp"

Quarter::Quarter(){
    commandId=6;
}

void Quarter::executeAction(CandyGame& Game){
    CandyPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());
    if (playernow.checkValidAbilityCard("QUARTER")){
        if(!playernow.getAbilityCard().getUseable()){
            cout << "\nOops, kartu ability quarter-mu telah dimatikan sebelumnya :(.\nSilahkan lakukan perintah lain.\n" << endl;
        } else {
            cout << endl << playernow.getNickname() << " melakukan QUARTER! Poin hadiah turun dari " << Game.getPoint();
            Game.setPoint(Game.getPoint()*0.25);
            cout << " menjadi " << Game.getPoint() << "!" << endl;
            playernow.useAbilityCard();
            Game.setValid(true);
        }
    } else {
        cout << "\nEts, tidak bisa. Kamu tidak punya kartu Ability QUARTER.\n" << endl;
    }
}