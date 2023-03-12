#include "../../../headers/Command/children/reverse.hpp"

Reverse::Reverse(){
    commandId=7;
}

void Reverse::executeAction(CandyGame& Game){
    Player& playernow = Game.getPlayer(Game.getPlayerTurn());
    if (playernow.checkValidAbilityCard("REVERSE")){
        if (!playernow.getAbilityCard().getUseable()){
            cout << "\nOops, kartu ability reversemu telah dimatikan sebelumnya:(.\nSilahkan lakukan perintah lain.\n" << endl;
        } else {
            cout << endl << playernow.getNickname() << " melakukan reverse!" << endl;
            cout << "(sisa) urutan eksekusi giliran ini : ";
            
            int i = (Game.getPlayerTurn() + 1) % Game.getNPlayers();
            while (i != (Game.getLastIdxTurn() + 1) % Game.getNPlayers()){
                cout << Game.getPlayer(i).getNickname();
                if (i != Game.getLastIdxTurn()){
                    cout << ", ";
                }
                i = (i+1) % Game.getNPlayers();
            }
            cout << endl;

            cout << "urutan eksekusi giliran selanjutnya : ";
            int nextFirstIdx = ((Game.getPlayerTurn()-1) % Game.getNPlayers() + Game.getNPlayers()) % Game.getNPlayers();
            i = nextFirstIdx;
            while (i != Game.getPlayerTurn()){
                cout << Game.getPlayer(i).getNickname();
                cout << ", ";
                i = ((i-1) % Game.getNPlayers() + Game.getNPlayers()) % Game.getNPlayers();
            }
            cout << Game.getPlayer(Game.getPlayerTurn()).getNickname() << endl;

            // set isReverse & next idxreverse
            Game.setFirstIdxTurn(nextFirstIdx);
            Game.setLastIdxTurn(Game.getPlayerTurn());
            Game.setIsReverse(true);

            playernow.useAbilityCard();

            Game.setValid(true);
        }
    } else {
        cout << "\nEts, tidak bisa. Kamu tidak punya kartu Ability REVERSE.\nSilahkan lakukan perintah lain.\n" << endl;
    }
}