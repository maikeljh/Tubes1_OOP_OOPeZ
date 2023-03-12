#include "../../../headers/Command/children/pickCard.hpp"
using namespace std;
PickCard::PickCard(){}

void PickCard::executeActionUNO(UnoGame& Game){
    int input_number;
    UnoPlayer& playernow = Game.getPlayer(Game.getPlayerTurn());

    // Print kartu yang ada dulu
    cout << "Kartu yang dimiliki player sekarang: " << endl;
    playernow.printCard();


    cout << "Silahkan pilih nomor kartu yang ingin digunakan!" << endl;
    cin >> input_number;
    // Validasi input (Belum Exception)
    while (!(input_number-1 >= 0 && input_number-1 <= playernow.getDeckPlayer().size())){
        cout << "Input nomor tidak valid. Silahkan input ulang!" << endl;
        cin >> input_number;
    }

    UnoCard& SCard = playernow.getDeckPlayer()[input_number-1];
    if (!SCard.getIsNumber()){}{
        if (SCard.getType() == "PLUS2"){
        }
        else if (SCard.getType() == "PLUS4"){}
        else if (SCard.getType() == "SKIP"){}
        else if (SCard.getType() == "UNOREVERSE"){}
        else if (SCard.getType() == "CHANGECOLOR"){}
    }
    playernow.getDeckPlayer().erase(playernow.getDeckPlayer().begin() + input_number-1);
    Game.setValid(true);
}