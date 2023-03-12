#include "../../../headers/Command/children/unoReverse.hpp"

UnoReverse::UnoReverse(){

}

void UnoReverse::executeActionUNO(UnoGame& UnoGame){
    vector<UnoPlayer>& players = UnoGame.getPlayers();
    reverse(players.begin(), players.end());
}