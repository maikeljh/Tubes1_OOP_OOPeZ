#include "../../../headers/Command/children/reRoll.hpp"

ReRoll::ReRoll(){
    commandId=2;
}

void ReRoll::executeAction(DeckCard<Card>& DeckCard, Game& Game){
    // buang kartu
    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    Player playernow = Game.getPlayer();
    Card c = playernow.pop();
    c = playernow.pop();
    // ambil kartu baru
    playernow.push(DeckCard.pop());
    playernow.push(DeckCard.pop());
    cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;
    playernow.printPlayerCard();
    playernow.useAbilityCard();
    // giliran dilanjut
    Next *next;
    next->executeAction(Game);
}