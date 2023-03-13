#include "../../../headers/Command/children/unoReverse.hpp"

UnoReverse::UnoReverse(){

}

void UnoReverse::executeActionUNO(UnoGame& UnoGame){
    vector<UnoPlayer>& players = UnoGame.getPlayers();
    players.push_back(players.front());
    players.erase(players.begin());
    reverse(players.begin(), players.end());
}