#include "../../../headers/Command/children/pickCard.hpp"

PickCard::PickCard():Command(){}

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

    // Validasi input kartu yang bisa dikeluarkan
    UnoCard& SCard = playernow.getDeckPlayer()[input_number-1];
    
    while (!(Game.getTop()==SCard)){
        cout << "Input nomor tidak valid. Silahkan input ulang!" << endl;
        cin >> input_number;
    }

    
    if (!SCard.getIsNumber()){}{
        if (SCard.getType() == "PLUS2"){
            Plus2 *plus2;
            plus2->executeActionUNO(Game);
        }
        else if (SCard.getType() == "PLUS4"){
            Plus4 *plus4;
            plus4->executeActionUNO(Game);
        }
        else if (SCard.getType() == "SKIP"){
            Skip *skip;
            skip->executeActionUNO(Game);
        }
        else if (SCard.getType() == "UNOREVERSE"){
            UnoReverse *unoReverse;
            unoReverse->executeActionUNO(Game);
        }
        else if (SCard.getType() == "CHANGECOLOR"){
            ChangeColor *changeColor;
            changeColor->executeActionUNO(Game);
        }
    }
    /* add to deck card, retrieve from player deck */
    TableCard<UnoCard>& tableCard = Game.getTableCard();
    tableCard.addCard(playernow.getCard(input_number-1));
    playernow.getDeckPlayer().erase(playernow.getDeckPlayer().begin() + input_number-1);

    /* next player */
    Pass *pass;
    pass->executeActionUNO(Game);
    
    Game.setValid(true);
}