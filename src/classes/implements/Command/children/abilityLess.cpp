#include "../../../headers/Command/children/abilityLess.hpp"
#include "../../../headers/Exception/exception.h"
#include <limits>

/* Ctor */
Abilityless::Abilityless(){}

/* Execute abilityless */
void Abilityless::executeAction(CandyGame& Game){
    CandyPlayer& playernow = Game.getPlayer(0);
    int playerTurn = 0;
    vector<CandyPlayer> players;
    vector<int> indexPlayers;

    for (int i = 0; i < Game.getNPlayers(); i++){
        if(i != playerTurn){
            players.push_back(Game.getPlayer(i));
            indexPlayers.push_back(i);
        }
    }

    if (playernow.checkValidAbilityCard("ABILITYLESS")){
        if(!playernow.getAbilityCard().getUseable()){
            cout << "\nKartu Abilityless kamu sudah dipakai :(" << endl;
        } else if (isAllAbilityUsed(players)){
            playernow.useAbilityCard();
            cout << "\nEits, ternyata semua pemain sudah memakai kartu kemampuan.\n";
            cout << "Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia" << endl;
        } else {
            cout << endl << playernow.getNickname() << " akan mematikan kartu ablity lawan!" << endl;
            // choose a player
            cout << "\nSilahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
            for (int i = 0; i < players.size(); i++){
                // print player list that can be switched (all exc the current player)
                cout << i+1 << ". ";
                cout << players[i].getNickname() << endl;
            }

            int idxAbilityless;
            do {
                try {
                    cout << "Pilihan : ";
                    cin >> idxAbilityless;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        throw InputActionInvalidExc();
                    }
                    if(idxAbilityless < 1 || idxAbilityless > 6){
                        throw InputNumberInvalidExc();
                    }
                } catch(GameException& err){
                    cout << err.what() << endl;
                }
            } while(idxAbilityless < 1 || idxAbilityless > 6);
            

            // Turn off ability
            playernow.useAbilityCard();
            CandyPlayer& playerAbilityless = Game.getPlayer(indexPlayers[idxAbilityless-1]);
            AbilityCard& targetAbilityCard = playerAbilityless.getAbilityCard();
            if (targetAbilityCard.getUseable()){
                targetAbilityCard.setUseable(false);
                cout << "\nKartu ability " << playerAbilityless.getNickname() << " telah dimatikan." << endl;
            } else {
                cout << "\nKartu ability " << playerAbilityless.getNickname() << " telah dipakai sebelumnya." << endl;
                cout << "Yah, sayang penggunaan kartu ini sia-sia :(" << endl;
            }
        }
        
        Game.setValid(true);
    } else {
        cout << "\nEits, kamu tidak punya kartunya :P\n" << endl;
    }
}

/* Check if all other players' ability have been used */
bool Abilityless::isAllAbilityUsed(vector<CandyPlayer> players){
    for (int i = 0; i < players.size(); i++){
        if (players[i].getAbilityCard().getUseable()){
            return false;
        }
    }
    return true;
}