#include "../../../headers/Command/children/next.hpp"

Next::Next():Command(){
    commandId = 1;
}

void Next::executeAction(CandyGame& Game){
    cout << "\nGiliran dilanjut ke pemain selanjutnya." << endl;
}