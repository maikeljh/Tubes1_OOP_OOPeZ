#include "../../../headers/Command/children/pass.hpp"

using namespace std;

/* Ctor */
Pass::Pass(){}

/* Pass the current player turn */
void Pass::executeAction(UnoGame& Game){
    if(Game.getAlreadyDraw()){
        cout << "\nGiliran dilanjut ke pemain selanjutnya." << endl;
        Game.setValid(true);
        Game.setAlreadyDraw(false);
    } else {
        cout << "\nEits, kamu belum melakukan DRAW sehingga tidak bisa pass.\n" << endl;
    }
}
