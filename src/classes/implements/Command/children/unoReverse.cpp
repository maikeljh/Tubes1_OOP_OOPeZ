#include "../../../headers/Command/children/unoReverse.hpp"

/* Ctor */
UnoReverse::UnoReverse(){}

/* Execute reverse in UnoGame */
void UnoReverse::executeAction(UnoGame& UnoGame){
    vector<UnoPlayer>& players = UnoGame.getPlayers();
    players.push_back(players.front());
    players.erase(players.begin());
    reverse(players.begin(), players.end());
}