#include "../../../headers/Command/children/quarter.hpp"

Quarter::Quarter(){}

void Quarter::executeAction(CandyGame& Game){
    CandyPlayer& playernow = Game.getPlayer(0);
    if (playernow.checkValidAbilityCard("QUARTER")){
        if(!playernow.getAbilityCard().getUseable()){
            cout << "\nOops, kartu ability quarter-mu telah dimatikan sebelumnya :(.\nSilahkan lakukan perintah lain.\n" << endl;
        } else {
            cout << endl << playernow.getNickname() << " melakukan QUARTER! Poin hadiah";
            long long int prevPoint = Game.getPoint();
            Game.setPoint(prevPoint*0.25);
            if(Game.getPoint() == 0){
                Game.setPoint(1);
                cout << " tetap bernilai " << Game.getPoint() << "!" << endl;
            } else {
                cout << " turun dari " << prevPoint << " menjadi " << Game.getPoint() << "!" << endl;
            }
            playernow.useAbilityCard();
            Game.setValid(true);
        }
    } else {
        cout << "\nEts, tidak bisa. Kamu tidak punya kartu Ability QUARTER.\n" << endl;
    }
}