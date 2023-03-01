#include "../../../headers/Command/children/double.hpp"

Double::Double(){
    commandId=3;
}

void Double::executeAction(Game& Game){
    Player playernow = Game.getPlayer();
    cout << playernow.getNickname() << " melakukan DOUBLE! Poin hadiah naik dari " << Game.getPoint();
    Game.setPoint(Game.getPoint()*2);
    cout << " menjadi " << Game.getPoint() << "!" << endl;
    // giliran dilanjut
    Next *next;
    next->executeAction(Game);
}