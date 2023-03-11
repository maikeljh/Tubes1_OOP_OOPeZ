#include "../../../headers/Command/children/reverse.hpp"

Reverse::Reverse(){
    commandId=7;
}

void Reverse::executeAction(CandyGame& Game){
    Player playernow = Game.getPlayer(Game.getPlayerTurn());
    if (!playernow.getAbilityCard().getUseable()){
        cout << "Oops, kartu ability reversemu telah dimatikan sebelumnya:(. Silahkan lakukan perintah lain." << endl;
    }
    if (playernow.checkValidAbilityCard("REVERSE")){
        cout << playernow.getNickname() << " melakukan reverse!" << endl;
        cout << "(sisa) urutan eksekusi giliran ini : ";
        
        int i = Game.getPlayerTurn()+1;
        while (i!=Game.getLastIdxTurn()){
            cout << Game.getPlayer(i).getNickname();
            if (i!=(Game.getLastIdxTurn()-1) % Game.getNPlayers()){
                cout << ", ";
            }
            i = (i+1) % Game.getNPlayers();
        }
        cout << endl;

        cout << "urutan eksekusi giliran selanjutnya : ";
        // first: (playerturn-1) % nPlayers
        int nextFirstIdx = (Game.getPlayerTurn()-1) % Game.getNPlayers();
        cout << Game.getPlayer(nextFirstIdx).getNickname();
        i = (nextFirstIdx-1) % Game.getNPlayers();
        while (i!=nextFirstIdx){
            cout << Game.getPlayer(i).getNickname();
            while (i!=(nextFirstIdx+1) % Game.getNPlayers()){
                cout << ", ";
            }
            i = (i-1) % Game.getNPlayers();
        }

        // set isReverse & next idxreverse
        Game.setIdxReverse(nextFirstIdx);
        Game.setIsReverse(true);

        playernow.useAbilityCard();

        Game.setValid(true);
    } else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REVERSE.\nSilahkan lakukan perintah lain." << endl;
    }
}