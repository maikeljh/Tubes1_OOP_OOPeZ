#include "../../../headers/Command/children/next.hpp"

Next::Next():Command(){
    commandId = 1;
}

void Next::executeAction(Game& Game){
    cout << "\nGiliran dilanjut ke pemain selanjutnya." << endl;
    if (Game.getIsClockWise()){
        Game.setPlayerTurn(Game.getPlayerTurn()+1);
    } else {
        Game.setPlayerTurn(Game.getPlayerTurn()-1);
    }
}

void Next::executeAction(DeckCard<Card>& DC, Game& Game){
    cout << "\nGiliran dilanjut ke pemain selanjutnya." << endl;
    if (Game.getIsClockWise()){
        Game.setPlayerTurn(Game.getPlayerTurn()+1);
    } else {
        Game.setPlayerTurn(Game.getPlayerTurn()-1);
    }
}