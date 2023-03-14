#include "../../../headers/Command/children/endGame.hpp"

EndGame::EndGame():Command(){}

void EndGame::printLeaderboard(CandyGame& Game){
    vector<CandyPlayer>& players = Game.getPlayers();

    // Sort by point DESC
    for(int i = 0; i < players.size(); i++){
        for(int j = i + 1; j < players.size(); j++){
            if(players[j].getPoint() > players[i].getPoint()){
                CandyPlayer temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    cout << "\nPermainan berakhir." << endl;
    cout << "Leaderboard:" << endl;
    for(int i = 0; i < players.size(); i++){
        cout << "   " << i+1 << ". " << players[i].getNickname() << ": " << players[i].getPoint() << endl;
    }
    this->printWinner(Game);
}

void EndGame::printWinner(CandyGame& Game){
    int winner = Game.chooseWinner();
    cout << "Permainan dimenangkan oleh " << Game.getPlayer(winner).getNickname() << endl;
}