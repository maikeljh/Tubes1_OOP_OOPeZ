#include "../../../headers/Command/children/checkCard.hpp"

using namespace std;

/* Ctor */
CheckCard::CheckCard(){}

/* Print available player cards */
void CheckCard::executeAction(CandyGame& Game){
    CandyPlayer& now = Game.getPlayer(0);
    cout << "\nKartu Pemain " << now.getNickname() << " :" << endl;
    now.printCard();
    cout << endl;
}