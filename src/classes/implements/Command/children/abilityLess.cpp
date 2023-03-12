#include "../../../headers/Command/children/abilityLess.hpp"

Abilityless::Abilityless(){
    commandId = 10;
}

void Abilityless::executeAction(CandyGame& Game){
    CandyPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());
    int playerTurn = Game.getPlayerTurn();
    vector<CandyPlayer> players;
    for (int i = 0; i < Game.getNPlayers(); i++){
        if(i != playerTurn){
            players.push_back(Game.getPlayer(i));
        }
    }
    if (playernow.checkValidAbilityCard("ABILITYLESS")){
        if(!playernow.getAbilityCard().getUseable()){
            cout << "\nKartu Abilityless kamu sudah dipakai :(" << endl;
        } else if (isAllAbilityUsed(players)){
            cout << "\nEits, ternyata semua pemain sudah memakai kartu kemampuan.\n";
            cout << "Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia" << endl;
        } else {
            cout << endl << playernow.getNickname() << " akan mematikan kartu ablity lawan!" << endl;
            // choose a player
            cout << "\nSilahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
            for (int i = 0; i < Game.getNPlayers(); i++){
                // print player list that can be switched (all exc the current player)
                if (i != playerTurn){
                    if (i < playerTurn){
                        cout << i+1 << ". ";
                    } else {
                        cout << i << ". ";
                    }
                    cout << Game.getPlayer(i).getNickname() << endl;
                }
            }

            cout << endl;
            int idxAbilityless;
            do {
                try {
                    cout << "Pilihan : ";
                    cin >> idxAbilityless;
                    if(idxAbilityless < 1 || idxAbilityless > 6){
                        cout << "Pilihan tidak valid!\n" << endl;
                    }
                } catch(...){
                    cout << "Pilihan tidak valid!\n" << endl;
                }
            } while(idxAbilityless < 1 || idxAbilityless > 6);
            
            if (idxAbilityless<playerTurn){
                idxAbilityless--;
            }

            // Turn off ability
            CandyPlayer& playerAbilityless = Game.getPlayer(idxAbilityless);
            AbilityCard& targetAbilityCard = playerAbilityless.getAbilityCard();
            if (targetAbilityCard.getUseable()){
                targetAbilityCard.setUseable(false);
                cout << "\nKartu ability " << playerAbilityless.getNickname() << " telah dimatikan." << endl;
            } else {
                cout << "\nKartu ability " << playerAbilityless.getNickname() << " telah dipakai sebelumnya." << endl;
                cout << "Yah, sayang penggunaan kartu ini sia-sia :(" << endl;
            }
        }
        playernow.useAbilityCard();
        Game.setValid(true);
    } else {
        cout << "\nEits, kamu tidak punya kartunya :P\n" << endl;
    }
}

bool Abilityless::isAllAbilityUsed(vector<CandyPlayer> players){
    for (int i = 0; i < players.size(); i++){
        if (players[i].getAbilityCard().getUseable()){
            return false;
        }
    }
    return true;
}