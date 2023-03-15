#include "../../../headers/Command/children/reRoll.hpp"

/* Ctor */
ReRoll::ReRoll(){}

/* Re-roll the current player cards with new cards from deck */
void ReRoll::executeAction(CandyGame& Game){
    CandyPlayer& playernow = Game.getPlayer(0);
    if (playernow.checkValidAbilityCard("RE-ROLL")){
        if(!playernow.getAbilityCard().getUseable()){
            cout << "\nOops, kartu ability ReRoll-mu telah dimatikan sebelumnya :(.\nSilahkan lakukan perintah lain.\n" << endl;
        } else {
            // Buang Kartu
            cout << "\nMelakukan pembuangan kartu yang sedang dimiliki" << endl;
            Game.getPlayer(0).useAbilityCard();
            Card c = Game.getPlayer(0).pop();
            c = Game.getPlayer(0).pop();

            // Ambil Kartu Baru
            Game.getPlayer(0).push(Game.getDeckCard().pop());
            Game.getPlayer(0).push(Game.getDeckCard().pop());
            cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;
            Game.getPlayer(0).printCard();

            Game.setValid(true);
        }
    } else {
        cout << "\nEts, tidak bisa. Kamu tidak punya kartu Ability RE-ROLL.\n" << endl;
    }
}