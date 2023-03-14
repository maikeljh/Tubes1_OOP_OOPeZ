#include "../../../headers/Command/children/plus2.hpp"

Plus2::Plus2(){}

void Plus2::executeActionUNO(UnoGame& UnoGame){
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
    skip->executeActionUNO(UnoGame);
}