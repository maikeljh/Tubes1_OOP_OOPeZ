#include "../../../headers/Command/children/skip.hpp"

Skip::Skip(){

}

void Skip::executeAction(UnoGame& UnoGame){
    vector<UnoPlayer>& players = UnoGame.getPlayers();
    players.push_back(players.front());
    players.erase(players.begin());
    cout << "\nPlayer " << players[0].getNickname() << " dilewatkan." << endl;
}