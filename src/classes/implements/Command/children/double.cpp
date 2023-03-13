#include "../../../headers/Command/children/double.hpp"

Double::Double():Command(){
    commandId=3;
}

void Double::executeAction(CandyGame& Game){
    CandyPlayer playernow = Game.getPlayer(0);
    cout << endl << playernow.getNickname() << " melakukan DOUBLE! Poin hadiah naik dari " << Game.getPoint();
    Game.setPoint(Game.getPoint()*2);
    cout << " menjadi " << Game.getPoint() << "!" << endl;
    Game.setValid(true);
}