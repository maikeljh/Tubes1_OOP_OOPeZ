#include "../../../headers/Command/children/half.hpp"

#include "../../../headers/Command/children/quadruple.hpp"

Half::Half():Command(){}

void Half::executeAction(CandyGame& Game){
    cout << endl << Game.getPlayer(0).getNickname() << " melakukan HALF! Poin hadiah";
    Game.setPoint(Game.getPoint()*0.5);
    if(Game.getPoint() == 0){
        Game.setPoint(1);
        cout << " tetap bernilai " << Game.getPoint() << "!" << endl;
    } else {
        cout << " turun dari " << Game.getPoint() << " menjadi " << Game.getPoint() << "!" << endl;
    }
    Game.setValid(true);
}