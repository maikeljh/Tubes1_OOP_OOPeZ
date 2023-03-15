#include "../../../headers/Command/children/plus4.hpp"
#include "../../../headers/Command/children/changeColor.hpp"

/* Ctor */
Plus4::Plus4(){}

/* Give the next player additional four cards, skip his/her turn, and choose color */
void Plus4::executeAction(UnoGame& UnoGame){
    UnoPlayer& playernext = UnoGame.getPlayer(1);
    DeckCard<UnoCard>& deck = UnoGame.getDeckCard();

    int count=0;
    while (count<4){
        playernext = playernext + deck.pop();
        count++;
    }
    
    cout << "\nKartu yang didapat oleh " << playernext.getNickname() << ":\n";
    count=0;
    while (count<4){
        cout << count+1 << ". ";
        playernext.getCard(playernext.getDeckPlayer().size()+(count-4)).printDetail();
        count++;
    }

    ChangeColor *changeColor = new ChangeColor();
    changeColor->executeAction(UnoGame);
    delete changeColor;

    Skip *skip = new Skip();
    skip->executeAction(UnoGame);
    delete skip;
}