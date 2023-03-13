#include "../../../headers/Command/children/pass.hpp"

using namespace std;

Pass::Pass():Command(){}

void Pass::executeActionUNO(UnoGame& Game){
    cout << "\nGiliran dilanjut ke pemain selanjutnya." << endl;
    Game.setValid(true);
}
