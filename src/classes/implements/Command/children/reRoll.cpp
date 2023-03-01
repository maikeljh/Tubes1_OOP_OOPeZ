#include "../../../headers/Command/children/reRoll.hpp"

ReRoll::ReRoll():Command(){
    commandId=2;
}

void ReRoll::executeAction(Game& Game){
    // Buang Kartu
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    Card c = Game.getPlayer().pop();
    c = Game.getPlayer().pop();

    // Ambil Kartu Baru
    Game.getPlayer().push(Game.getDeckCard().pop());
    Game.getPlayer().push(Game.getDeckCard().pop());
    cout << "\nKamu mendapatkan 2 kartu baru yaitu:" << endl;
    Game.getPlayer().printCard();
    Game.getPlayer().useAbilityCard();

    // Giliran Dilanjut
    Next next;
    next.executeAction(Game);
}