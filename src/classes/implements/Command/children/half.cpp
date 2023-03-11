#include "../../../headers/Command/children/half.hpp"

#include "../../../headers/Command/children/quadruple.hpp"

Half::Half():Command(){
    commandId=5;
}

void Half::executeAction(Game& game){
    Game *now = &game;
    CandyGame temp = *(CandyGame*)now;

    cout << temp.getPlayer(temp.getPlayerTurn()).getNickname() << " melakukan DOUBLE! Poin hadiah turun dari " << temp.getPoint();
    temp.setPoint(temp.getPoint()*0.5);
    cout << " menjadi " << temp.getPoint() << "!" << endl;
    Next next;
    next.executeAction(game);
}