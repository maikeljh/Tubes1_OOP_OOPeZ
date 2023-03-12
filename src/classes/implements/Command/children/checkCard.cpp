#include "../../../headers/Command/children/checkCard.hpp"

using namespace std;

CheckCard::CheckCard():Command(){}

void CheckCard::executeAction(CandyGame& Game){
    CandyPlayer& now = Game.getPlayer(Game.getPlayerTurn());
    cout << "\nKartu Pemain " << now.getNickname() << " :" << endl;
    now.printCard();
    cout << endl;
}