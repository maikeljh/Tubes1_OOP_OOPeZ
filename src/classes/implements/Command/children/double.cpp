#include "../../../headers/Command/children/double.hpp"

Double::Double(){
    commandId=3;
}

void Double::useAction(Game& Game){
    Player playernow = Game.getPlayer();
    if (playernow.checkValidAbilityCard("DOUBLE")){
        cout << playernow.getNickname() << " melakukan DOUBLE! Poin hadiah naik dari " << Game.getPoint();
        Game.setPoint(Game.getPoint()*2);
        cout << " menjadi " << Game.getPoint() << "!" << endl;
        playernow.useAbilityCard();
    } else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability DOUBLE." << endl;
    }
    // giliran dilanjut
    Next *next;
    next->useAction(Game);
}