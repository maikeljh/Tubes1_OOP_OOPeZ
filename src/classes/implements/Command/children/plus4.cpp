#include "../../../headers/Command/children/plus4.hpp"

Plus4::Plus4(){

}

void Plus4::executeActionUNO(UnoGame& UnoGame){
    UnoPlayer& playernow = UnoGame.getPlayer(0);
    DeckCard<UnoCard>& deck = UnoGame.getDeckCard();

    int count=0;
    while (count<4){
        playernow.push(deck.pop());
        count++;
    }
}