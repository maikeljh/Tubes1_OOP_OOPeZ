#include "../../../headers/Command/children/half.hpp"

#include "../../../headers/Command/children/quadruple.hpp"

Half::Half():Command(){
    commandId=5;
}

void Half::executeAction(Game& Game){
    cout << Game.getPlayer().getNickname() << " melakukan DOUBLE! Poin hadiah turun dari " << Game.getPoint();
    Game.setPoint(Game.getPoint()*0.5);
    cout << " menjadi " << Game.getPoint() << "!" << endl;
    Next next;
    next.executeAction(Game);
}