#include "../../../headers/Command/children/next.hpp"

Next::Next():Command(){}

void Next::executeAction(CandyGame& Game){
    cout << "\nGiliran dilanjut ke pemain selanjutnya." << endl;
    Game.setValid(true);
}