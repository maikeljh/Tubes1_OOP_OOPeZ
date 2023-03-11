#include "../../../headers/Command/children/next.hpp"

Next::Next():Command(){
    commandId = 1;
}

void Next::executeAction(CandyGame& Game){
    if (Game.getPlayerTurn()!=Game.getLastIdxTurn()){
        cout << "\nGiliran dilanjut ke pemain selanjutnya." << endl;
    }
    Game.setValid(true);
}