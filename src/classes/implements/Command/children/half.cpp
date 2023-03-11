#include "../../../headers/Command/children/half.hpp"

#include "../../../headers/Command/children/quadruple.hpp"

Half::Half():Command(){
    commandId=5;
}

void Half::executeAction(CandyGame& Game){
    cout << Game.getPlayer(Game.getPlayerTurn()).getNickname() << " melakukan DOUBLE! Poin hadiah turun dari " << Game.getPoint();
    Game.setPoint(Game.getPoint()*0.5);
    cout << " menjadi " << Game.getPoint() << "!" << endl;
    Next next;
    next.executeAction(Game);
}