#include "../../../headers/Command/children/pass.hpp"

using namespace std;

Pass::Pass():Command(){}

void Pass::executeActionUNO(UnoGame& Game){
    if(Game.getAlreadyDraw()){
        cout << "\nGiliran dilanjut ke pemain selanjutnya." << endl;
        Game.setValid(true);
        Game.setAlreadyDraw(false);
    } else {
        cout << "\nEits, kamu belum melakukan DRAW sehingga tidak bisa pass." << endl;
    }
}
