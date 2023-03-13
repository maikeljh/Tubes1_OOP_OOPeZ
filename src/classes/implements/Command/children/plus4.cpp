#include "../../../headers/Command/children/plus4.hpp"

Plus4::Plus4(){

}

void Plus4::executeActionUNO(UnoGame& UnoGame){
    UnoPlayer& playernext = UnoGame.getPlayer(1);
    DeckCard<UnoCard>& deck = UnoGame.getDeckCard();
    cout << "sini" << endl;
    int count=0;
    while (count<4){
        playernext.push(deck.pop());
        count++;
    }
    
    cout << "Kartu yang didapat oleh " << playernext.getNickname() << ":\n";
    count=0;
    while (count<4){
        cout << count+1 << ". ";
        playernext.getCard(playernext.getDeckPlayer().size()+(count-2)).printDetail();
        count++;
    }

    Skip *skip = new Skip();
    skip->executeActionUNO(UnoGame);
}