#include "../../../headers/Command/children/next.hpp"

/* Ctor */
Next::Next(){}

/* Pass the turn to next player */
void Next::executeAction(CandyGame& Game){
    cout << "\nGiliran dilanjut ke pemain selanjutnya." << endl;
    Game.setValid(true);
}