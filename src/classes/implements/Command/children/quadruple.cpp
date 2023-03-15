#include "../../../headers/Command/children/quadruple.hpp"

/* Ctor */
Quadruple::Quadruple(){}

/* Quadruple the current game point */
void Quadruple::executeAction(CandyGame& Game){
    CandyPlayer& playernow = Game.getPlayer(0);
    if (playernow.checkValidAbilityCard("QUADRUPLE")){
        if(!playernow.getAbilityCard().getUseable()){
            cout << "\nOops, kartu ability quadruple-mu telah dimatikan sebelumnya :(.\nSilahkan lakukan perintah lain.\n" << endl;
        } else {
            cout << endl << playernow.getNickname() << " melakukan QUADRUPLE! Poin hadiah naik dari " << Game.getPoint();
            Game.setPoint(Game.getPoint()*4);
            cout << " menjadi " << Game.getPoint() << "!" << endl;
            playernow.useAbilityCard();
            Game.setValid(true);
        }
    } else {
        cout << "\nEts, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE.\n" << endl;
    }
}