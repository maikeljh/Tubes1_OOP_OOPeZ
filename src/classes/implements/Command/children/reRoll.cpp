#include "../../../headers/Command/children/reRoll.hpp"

ReRoll::ReRoll():Command(){
    commandId=2;
}

void ReRoll::executeAction(CandyGame& Game){
    // Buang Kartu
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    Card c = Game.getPlayer(Game.getPlayerTurn()).pop();
    c = Game.getPlayer(Game.getPlayerTurn()).pop();

    // Ambil Kartu Baru
    Game.getPlayer(Game.getPlayerTurn()).push(Game.getDeckCard().pop());
    Game.getPlayer(Game.getPlayerTurn()).push(Game.getDeckCard().pop());
    cout << "\nKamu mendapatkan 2 kartu baru yaitu:" << endl;
    Game.getPlayer(Game.getPlayerTurn()).printCard();
    Game.getPlayer(Game.getPlayerTurn()).useAbilityCard();

    // Giliran Dilanjut
    Next next;
    next.executeAction(Game);
}