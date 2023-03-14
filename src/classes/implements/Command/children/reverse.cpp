#include "../../../headers/Command/children/reverse.hpp"
#include "../../../headers/Command/commandParser.hpp"

Reverse::Reverse(){
    commandId=7;
}

void Reverse::executeAction(CandyGame& Game){
    CandyPlayer& playernow = Game.getPlayer(0);
    CandyPlayer tempPlayer = Game.getPlayer(0);

    if (playernow.checkValidAbilityCard("REVERSE")){
        if (!playernow.getAbilityCard().getUseable()){
            cout << "\nOops, kartu ability reverse-mu telah dimatikan sebelumnya :(.\nSilahkan lakukan perintah lain.\n" << endl;
        } else {
            playernow.useAbilityCard();
            tempPlayer.useAbilityCard();
            cout << endl << playernow.getNickname() << " melakukan reverse!" << endl;

            // Reverse Algorithm
            vector<CandyPlayer>& players = Game.getPlayers();
            vector<CandyPlayer> temp;
            while(players.size() != 0){
                temp.push_back(players.back());
                players.pop_back();
            }
            for(int i = 0; i < Game.getPlayerTurn() - 1; i++){
                temp.push_back(temp.front());
                temp.erase(temp.begin());
            }
            for(int i = 0; i < Game.getNPlayers(); i++){
                players.push_back(temp[i]);
            }

            if(Game.getPlayerTurn() == 0){
                players.insert(players.begin(), players[players.size()-1]);
                players.pop_back();
            }

            cout << "(sisa) urutan eksekusi giliran ini : ";
            
            if(Game.getPlayerTurn() == Game.getNPlayers() - 1){
                cout << "-" << endl;
            } else {
                int upperbound = Game.getNPlayers() - Game.getPlayerTurn();
                for(int i = 1; i < upperbound; i++){
                    cout << Game.getPlayer(i).getNickname();
                    if (i != upperbound - 1){
                        cout << ", ";
                    }
                }
                cout << endl;
            }

            cout << "urutan eksekusi giliran selanjutnya : ";
            int nextIdx = (Game.getNPlayers() - Game.getPlayerTurn() + 1) % Game.getNPlayers();
            for(int i = 0; i < Game.getNPlayers()-1; i++){
                cout << Game.getPlayer(nextIdx).getNickname();
                cout << ", ";
                nextIdx = ((nextIdx + 1) % Game.getNPlayers() + Game.getNPlayers()) % Game.getNPlayers();
            }
            cout << Game.getPlayer(nextIdx).getNickname() << endl << endl;

            cout << "Sekarang adalah giliran pemain " << tempPlayer.getNickname() << " lagi." << endl;

            players.insert(players.begin(), tempPlayer);

            CommandParser CP;
            string command;

            while(!Game.getValid()){
                try{
                    cout << "Command : ";
                    cin >> command;
                    Command *action = CP.parser(command);
                    action->executeAction(Game);
                    delete action;
                } catch(GameException& err){
                    cout << err.what() << endl;
                }
            }

            players.erase(players.begin());
        }
    } else {
        cout << "\nEts, tidak bisa. Kamu tidak punya kartu Ability REVERSE.\nSilahkan lakukan perintah lain.\n" << endl;
    }
}