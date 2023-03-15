#include "../../../headers/Command/children/plus2.hpp"

/* Ctor */
Plus2::Plus2(){}

/* Give the next player additional two cards and skip his/her turn */
void Plus2::executeAction(UnoGame& UnoGame){
    UnoPlayer& playernext = UnoGame.getPlayer(1);
    DeckCard<UnoCard>& deck = UnoGame.getDeckCard();

    int count = 0;
    while (count < 2){
        playernext = playernext + deck.pop();
        count++;
    }
    
    cout << "\nKartu yang didapat oleh " << playernext.getNickname() << ":\n";
    count=0;
    while (count<2){
        cout << count+1 << ". ";
        playernext.getCard(playernext.getDeckPlayer().size()+(count-2)).printDetail();
        count++;
    }

    Skip *skip = new Skip();
    skip->executeAction(UnoGame);
}