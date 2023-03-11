#include "../../../headers/Command/children/reverse.hpp"

Reverse::Reverse(){
    commandId=7;
}

void Reverse::executeAction(Game& Game){
    Player playernow = Game.getPlayer();
    if (playernow.checkValidAbilityCard("REVERSE")){
        cout << playernow.getNickname() << " melakukan reverse!" << endl;
        cout << "(sisa) urutan eksekusi giliran ini : ";
    }
}