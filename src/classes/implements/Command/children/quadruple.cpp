#include "../../../headers/Command/children/quadruple.hpp"

Quadruple::Quadruple(){
    commandId=4;
}

void Quadruple::executeAction(Game& Game){
    Player playernow = Game.getPlayer();
    if (playernow.checkValidAbilityCard("QUADRUPLE")){
        cout << playernow.getNickname() << " melakukan QUADRUPLE! Poin hadiah naik dari " << Game.getPoint();
        Game.setPoint(Game.getPoint()*4);
        cout << " menjadi " << Game.getPoint() << "!" << endl;
        playernow.useAbilityCard();
    } else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE." << endl;
    }
    // giliran dilanjut
    Next *next;
    next->executeAction(Game);
}