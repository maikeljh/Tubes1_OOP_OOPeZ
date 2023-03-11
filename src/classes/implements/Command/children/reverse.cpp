#include "../../../headers/Command/children/reverse.hpp"

Reverse::Reverse(){
    commandId=7;
}

void Reverse::executeAction(Game& game){
    Game *now = &game;
    CandyGame temp = *(CandyGame*)now;

    Player playernow = temp.getPlayer(temp.getPlayerTurn());
    if (playernow.checkValidAbilityCard("REVERSE")){
        cout << playernow.getNickname() << " melakukan reverse!" << endl;
        cout << "(sisa) urutan eksekusi giliran ini : ";
        
        int i = temp.getPlayerTurn()+1;
        while (i!=temp.getLastIdxTurn()){
            cout << temp.getPlayer(i).getNickname();
            if (i!=(temp.getLastIdxTurn()-1) % temp.getNPlayers()){
                cout << ", ";
            }
            i = (i+1) % temp.getNPlayers();
        }
        cout << endl;

        cout << "urutan eksekusi giliran selanjutnya : ";
        // first: (playerturn-1) % nPlayers
        int nextFirstIdx = (temp.getPlayerTurn()-1) % temp.getNPlayers();
        cout << temp.getPlayer(nextFirstIdx).getNickname();
        i = (nextFirstIdx-1) % temp.getNPlayers();
        while (i!=nextFirstIdx){
            cout << temp.getPlayer(i).getNickname();
            while (i!=(nextFirstIdx+1) % temp.getNPlayers()){
                cout << ", ";
            }
            i = (i-1) % temp.getNPlayers();
        }

        // set isReverse & next idxreverse
        temp.setIdxReverse(nextFirstIdx);
        temp.setIsReverse(true);

        // giliran dilanjut
        Next *next;
        next->executeAction(game);
    } else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REVERSE.\nSilahkan lakukan perintah lain." << endl;
    }
}