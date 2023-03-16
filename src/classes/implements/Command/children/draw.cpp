#include "../../../headers/Command/children/draw.hpp"
using namespace std;

/* Ctor */
Draw::Draw(){}

/* Execute draw card from UNO deck */
void Draw::executeAction(UnoGame& Game){
    UnoPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());
    
    // Ambil satu kartu
    if(!Game.getAlreadyDraw()){
        UnoCard newCard = Game.getDeckCard().pop();
        playernow = playernow + newCard;
        cout << "\nKamu mendapatkan kartu baru yaitu: ";
        
        if(newCard.getIsNumber()){
            cout << newCard.getNumber() << " " << newCard.getColor() << endl;
        } else {
            cout << newCard.getType() << " " << newCard.getColor() << endl;
        }

        cout << endl;
        Game.setAlreadyDraw(true);
    }
    else{
        cout << "\nEits, kamu sudah melakukan DRAW pada ronde ini. Silahkan lakukan perintah lainnya!" << endl;
    }
}