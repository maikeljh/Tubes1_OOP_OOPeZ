#include "../../../headers/Command/children/quarter.hpp"

Quarter::Quarter(){
    commandId=6;
}

void Quarter::executeAction(Game& Game){
    Player playernow = Game.getPlayer();
    if (playernow.checkValidAbilityCard("QUARTER")){
        cout << playernow.getNickname() << " melakukan QUARTER! Poin hadiah turun dari " << Game.getPoint();
        Game.setPoint(Game.getPoint()*0.25);
        cout << " menjadi " << Game.getPoint() << "!" << endl;
        playernow.useAbilityCard();
    } else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUARTER." << endl;
    }
    // giliran dilanjut
    Next *next;
    next->executeAction(Game);
}