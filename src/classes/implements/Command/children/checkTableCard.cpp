#include "../../../headers/Command/children/checkTableCard.hpp"

using namespace std;

CheckTableCard::CheckTableCard():Command(){}

void CheckTableCard::executeAction(CandyGame& Game){
    TableCard& now = Game.getTableCard();
    if(now.getNeff() == 0){
        cout << "\nTable card masih kosong\n" << endl;
    } else {
        cout << endl;
        now.printTable();
        cout << endl;
    }
}