#include "../../../headers/Command/children/half.hpp"

#include "../../../headers/Command/children/quadruple.hpp"

Half::Half(){
    commandId=5;
}

void Half::useAction(Game& Game){
    /*
    Player playernow = Game.getPlayer();
    if (playernow.checkValidAbilityCard("HALF")){
        cout << playernow.getNickname() << " melakukan HALF! Poin hadiah naik dari " << Game.getPoint();
        Game.setPoint(Game.getPoint()*4);
        cout << " menjadi " << Game.getPoint() << "!" << endl;
        //playernow.useAbilityCard();
    } else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability HALF." << endl;
    }
    */
    // giliran dilanjut
    Next *next;
    next->useAction(Game);
}