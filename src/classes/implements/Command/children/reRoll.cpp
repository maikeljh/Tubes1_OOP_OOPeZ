#include "../../../headers/Command/children/reRoll.hpp"

ReRoll::ReRoll(){
    commandId=2;
}

void ReRoll::executeAction(Game& Game){
    // buang kartu
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    Player playernow = Game.getPlayer();
    Card c = playernow.pop();
    c = playernow.pop();
    // ambil kartu baru
    playernow.push(Game.getDeckCard().pop());
    playernow.push(Game.getDeckCard().pop());
    cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;
    playernow.printCard();
    playernow.useAbilityCard();
    // giliran dilanjut
    Next next;
    next.executeAction(Game);
}