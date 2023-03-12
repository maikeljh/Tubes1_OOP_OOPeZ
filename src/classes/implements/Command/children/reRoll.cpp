#include "../../../headers/Command/children/reRoll.hpp"

ReRoll::ReRoll():Command(){
    commandId=2;
}

void ReRoll::executeAction(CandyGame& Game){
    Player playernow = Game.getPlayer(Game.getPlayerTurn());
    if (playernow.checkValidAbilityCard("RE-ROLL")){
        // Buang Kartu
        cout << "\nMelakukan pembuangan kartu yang sedang dimiliki" << endl;
        Card c = Game.getPlayer(Game.getPlayerTurn()).pop();
        c = Game.getPlayer(Game.getPlayerTurn()).pop();

        // Ambil Kartu Baru
        Game.getPlayer(Game.getPlayerTurn()).push(Game.getDeckCard().pop());
        Game.getPlayer(Game.getPlayerTurn()).push(Game.getDeckCard().pop());
        cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;
        Game.getPlayer(Game.getPlayerTurn()).printCard();
        Game.getPlayer(Game.getPlayerTurn()).useAbilityCard();

        Game.setValid(true);
    } else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability RE-ROLL." << endl;
    }
}