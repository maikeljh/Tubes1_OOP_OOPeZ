#include "../../../headers/Command/children/abilityLess.hpp"

Abilityless::Abilityless(){
    commandId = 10;
}

void Abilityless::executeAction(CandyGame& Game){
    Player playernow = Game.getPlayer(Game.getPlayerTurn());
    int playerTurn = Game.getPlayerTurn();
    vector<Player> players;
    for (int i=0; i<Game.getNPlayers(); i++){
        players.push_back(Game.getPlayer(i));
    }
    if (!isAllAbilityUseable(players)){
        cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. ";
        cout << "Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia" << endl;
    } else if (playernow.checkValidAbilityCard("SWITCH")){
        cout << playernow.getNickname() << " akan mematikan kartu ablity lawan!" << endl;

        // choose a player
        cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
        for (int i=0; i<Game.getNPlayers(); i++){
            // print player list that can be switched (all exc the current player)
            if (i!=playerTurn){
                if (i<playerTurn){
                    cout << i+1 << ". ";
                } else {
                    cout << i << ". ";
                }
                cout << Game.getPlayer(i).getNickname() << endl;
            }
        }
        int idxAbilityless;
        cin >> idxAbilityless;
        if (idxAbilityless<playerTurn){
            idxAbilityless--;
        }

        // turn off ability
        Player playerAbilityless = Game.getPlayer(idxAbilityless);
        AbilityCard& targetAbilityCard = playerAbilityless.getAbilityCard();
        if (targetAbilityCard.getUseable()){
            targetAbilityCard.setUseable(false);
        } else {
            cout << "Kartu ability " << playerAbilityless.getNickname() << " telah dipakai sebelumnya." << endl;
            cout << "Yah, sayang penggunaan kartu ini sia-sia :(" << endl;
        }

        cout << "Kartu ability " << playerAbilityless.getNickname() << " telah dimatikan." << endl;
        playernow.useAbilityCard();

        // giliran dilanjut
        Next *next;
        next->executeAction(Game);
    } else {
        cout << "Eits, kamu tidak punya kartunya :P" << endl;
    }
}

bool Abilityless::isAllAbilityUseable(vector<Player> players){
    for (int i=0; i<players.size(); i++){
        if (!players[i].getAbilityCard().getUseable()){
            return false;
        }
        return true;
    }
}