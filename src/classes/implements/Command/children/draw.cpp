#include "../../../headers/Command/children/draw.hpp"
using namespace std;

Draw::Draw():Command(){}

void Draw::executeActionUNO(UnoGame& Game){
    UnoPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());
    
    // Ambil satu kartu
    if(!Game.getAlreadyDraw()){
        UnoCard newCard = Game.getDeckCard().pop();
        playernow.push(newCard);
        cout << "\nKamu mendapatkan kartu baru yaitu: ";
        if(newCard.getIsNumber()){
            cout << newCard.getNumber() << " " << newCard.getColor() << endl;
        } else {
            cout << newCard.getType() << " " << newCard.getColor() << endl;
        }
        Game.setAlreadyDraw(true);
    }
    else{
        cout << "\nEits, kamu sudah melakukan DRAW pada ronde ini. Silahkan lakukan perintah lainnya!" << endl;
    }
}