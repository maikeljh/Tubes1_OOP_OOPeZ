#include "../../../headers/Command/children/draw.hpp"
using namespace std;

void Draw::executeActionUNO(UnoGame& UG){
    UnoPlayer& playernow = UG.getPlayer(UG.getPlayerTurn());
    
    // Ambil satu kartu
    // playernow.push(UG.getDeckCard().pop());
    cout << "Kamu mendapatkan kartu baru yaitu: " << endl;
    // playernow.printCard()
    UG.setValid(true);
}