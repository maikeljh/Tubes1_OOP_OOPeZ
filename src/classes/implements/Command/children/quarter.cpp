#include "../../../headers/Command/children/quarter.hpp"

Quarter::Quarter(){
    commandId=6;
}

void Quarter::executeAction(CandyGame& Game){
    Player playernow = Game.getPlayer(Game.getPlayerTurn());
    if (playernow.checkValidAbilityCard("QUARTER")){
        cout << playernow.getNickname() << " melakukan QUARTER! Poin hadiah turun dari " << Game.getPoint();
        Game.setPoint(Game.getPoint()*0.25);
        cout << " menjadi " << Game.getPoint() << "!" << endl;
        playernow.useAbilityCard();
        Game.setValid(true);
    } else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUARTER." << endl;
    }
}