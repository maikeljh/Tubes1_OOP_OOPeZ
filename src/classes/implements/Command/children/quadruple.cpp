#include "../../../headers/Command/children/quadruple.hpp"

Quadruple::Quadruple(){
    commandId=4;
}

void Quadruple::executeAction(CandyGame& Game){
    Player playernow = Game.getPlayer(Game.getPlayerTurn());
    if (playernow.checkValidAbilityCard("QUADRUPLE")){
        cout << playernow.getNickname() << " melakukan QUADRUPLE! Poin hadiah naik dari " << Game.getPoint();
        Game.setPoint(Game.getPoint()*4);
        cout << " menjadi " << Game.getPoint() << "!" << endl;
        playernow.useAbilityCard();
        Game.setValid(true);
    } else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE." << endl;
    }
}