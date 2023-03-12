#include "../../../headers/Command/children/endGame.hpp"

EndGame::EndGame():Command(){}

void EndGame::printLeaderboard(Game& Game){
    vector<Player> players = Game.getPlayers();
    cout << "\nPermainan berakhir." << endl;
    cout << "Leaderboard:" << endl;
    for(int i = 0; i < players.size(); i++){
        cout << "   " << i+1 << ". " << players[i].getNickname() << ": " << players[i].getPoint() << endl;
    }
    this->printWinner(Game);
}

void EndGame::printWinner(Game& Game){
    int winner = Game.chooseWinner();
    cout << "Permainan dimenangkan oleh " << Game.getPlayer(winner).getNickname() << endl;
}