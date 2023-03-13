#include "../../../headers/Command/children/draw.hpp"
using namespace std;

Draw::Draw():Command(){}

void Draw::executeActionUNO(UnoGame& Game){
    UnoPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());
    
    // Ambil satu kartu
    UnoCard newCard = Game.getDeckCard().pop();
    playernow.push(newCard);
    cout << "Kamu mendapatkan kartu baru yaitu: ";
    if(newCard.getIsNumber()){
        cout << newCard.getNumber() << " " << newCard.getColor() << endl;
    } else {
        cout << newCard.getType() << " " << newCard.getColor() << endl;
    }
    Game.setValid(true);
}