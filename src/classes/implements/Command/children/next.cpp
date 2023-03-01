#include "../../../headers/Command/children/next.hpp"

Next::Next(){
    commandId = 1;
}

void Next::useAction(Game& Game){
    cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
    if (Game.getIsClockWise()){
        Game.setPlayerTurn(Game.getPlayerTurn()+1);
    } else {
        Game.setPlayerTurn(Game.getPlayerTurn()-1);
    }
}