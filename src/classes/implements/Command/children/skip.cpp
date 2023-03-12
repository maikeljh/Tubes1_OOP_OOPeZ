#include "../../../headers/Command/children/skip.hpp"

Skip::Skip(){

}

void Skip::executeActionUNO(UnoGame& UnoGame){
    vector<UnoPlayer>& players = UnoGame.getPlayers();
    players.push_back(players[0]);
    players.erase(players.begin());
}