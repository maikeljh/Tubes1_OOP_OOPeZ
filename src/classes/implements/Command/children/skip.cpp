#include "../../../headers/Command/children/skip.hpp"

Skip::Skip(){

}

void Skip::executeActionUNO(UnoGame& UnoGame){
    vector<UnoPlayer>& players = UnoGame.getPlayers();
    players.push_back(players.front());
    players.erase(players.begin());
    cout << "Player " << players[0].getNickname() << " dilewatkan." << endl;
}