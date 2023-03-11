#include "../../../headers/Command/children/double.hpp"
#include "../../../headers/Game/game.hpp"

Double::Double():Command(){
    commandId=3;
}

void Double::executeAction(Game& game){
    Game *now = &game;
    CandyGame temp = *(CandyGame*)now;

    Player playernow = temp.getPlayer(temp.getPlayerTurn());
    cout << playernow.getNickname() << " melakukan DOUBLE! Poin hadiah naik dari " << temp.getPoint();
    temp.setPoint(temp.getPoint()*2);
    cout << " menjadi " << temp.getPoint() << "!" << endl;
    Next next;
    next.executeAction(game);
}