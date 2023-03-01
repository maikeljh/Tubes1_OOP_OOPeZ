#include "../../../headers/Command/children/half.hpp"

#include "../../../headers/Command/children/quadruple.hpp"

Half::Half(){
    commandId=5;
}

void Half::executeAction(Game& Game){
    Player playernow = Game.getPlayer();
    cout << playernow.getNickname() << " melakukan DOUBLE! Poin hadiah turun dari " << Game.getPoint();
    Game.setPoint(Game.getPoint()*0.5);
    cout << " menjadi " << Game.getPoint() << "!" << endl;
    // giliran dilanjut
    Next *next;
    next->executeAction(Game);
}