#include "../../../headers/Command/children/plus2.hpp"

Plus2::Plus2(){

}

void Plus2::executeActionUNO(UnoGame& UnoGame){
    UnoPlayer& playernow = UnoGame.getPlayer(0);
    DeckCard<UnoCard>& deck = UnoGame.getDeckCard();

    int count=0;
    while (count<2){
        playernow.push(deck.pop());
        count++;
    }
}