#include "../../../headers/Command/children/double.hpp"

Double::Double():Command(){
    commandId=3;
}

void Double::executeAction(CandyGame& Game){
    Player playernow = Game.getPlayer(Game.getPlayerTurn());
    cout << endl << playernow.getNickname() << " melakukan DOUBLE! Poin hadiah naik dari " << Game.getPoint();
    Game.setPoint(Game.getPoint()*2);
    cout << " menjadi " << Game.getPoint() << "!" << endl;
    Game.setValid(true);
}