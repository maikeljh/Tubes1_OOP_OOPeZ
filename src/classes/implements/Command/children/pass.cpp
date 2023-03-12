#include "../../../headers/Command/children/pass.hpp"

using namespace std;

void Pass::executeActionUNO(UnoGame& Game){
    if (Game.getPlayerTurn()!=Game.getLastIdxTurn()){
        cout << "\nGiliran dilanjut ke pemain selanjutnya." << endl;
    }
    Game.setValid(true);
}
