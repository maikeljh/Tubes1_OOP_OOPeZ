#include "../../../headers/Command/children/draw.hpp"
using namespace std;

void Draw::executeActionUNO(UnoGame& Game){
    UnoPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());
    
    // Ambil satu kartu
    playernow.push(Game.getDeckCard().pop());
    cout << "Kamu mendapatkan kartu baru yaitu: " << endl;
    playernow.printCard();
    Game.setValid(true);
}