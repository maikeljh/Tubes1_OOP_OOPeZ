#include "../../../headers/Command/children/checkTableCard.hpp"

using namespace std;

/* Ctor */
CheckTableCard::CheckTableCard(){}

/* Print available table cards */
void CheckTableCard::executeAction(CandyGame& Game){
    TableCard<Card>& now = Game.getTableCard();
    if(now.getNeff() == 0){
        cout << "\nTable card masih kosong\n" << endl;
    } else {
        cout << endl;
        now.printCard();
        cout << endl;
    }
}