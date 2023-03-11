#include "../../../headers/Command/children/reRoll.hpp"

ReRoll::ReRoll():Command(){
    commandId=2;
}

void ReRoll::executeAction(Game& game){
    Game *now = &game;
    CandyGame temp = *(CandyGame*)now;

    // Buang Kartu
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    Card c = temp.getPlayer(game.getPlayerTurn()).pop();
    c = temp.getPlayer(game.getPlayerTurn()).pop();

    // Ambil Kartu Baru
    temp.getPlayer(game.getPlayerTurn()).push(temp.getDeckCard().pop());
    temp.getPlayer(game.getPlayerTurn()).push(temp.getDeckCard().pop());
    cout << "\nKamu mendapatkan 2 kartu baru yaitu:" << endl;
    temp.getPlayer(game.getPlayerTurn()).printCard();
    temp.getPlayer(game.getPlayerTurn()).useAbilityCard();

    // Giliran Dilanjut
    Next next;
    next.executeAction(game);
}