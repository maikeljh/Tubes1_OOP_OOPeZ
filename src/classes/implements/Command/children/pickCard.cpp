#include "../../../headers/Command/children/pickCard.hpp"

PickCard::PickCard():Command(){}

void PickCard::executeActionUNO(UnoGame& Game){
    int input_number;
    UnoPlayer& playernow = Game.getPlayer(0);
    UnoCard SCard;

    // Print kartu yang ada dulu
    cout << "\nKartu yang dimiliki player sekarang: " << endl;
    playernow.printCard();

    bool validCard = false;
    // Validasi input dan kartu
    while(!validCard){
        cout << "\nSilahkan pilih nomor kartu yang ingin digunakan : ";
        cin >> input_number;
        if(!(input_number-1 >= 0 && input_number-1 <= playernow.getDeckPlayer().size())){
            cout << "\nInput nomor tidak valid. Silahkan input ulang!" << endl;
        } else {
            // Validasi input kartu yang bisa dikeluarkan
            SCard = playernow.getDeckPlayer()[input_number-1];
            if (!(Game.getTop() == SCard)){
                cout << "\nKartu tidak bisa dipakai. Silahkan pilih kartu lain!" << endl;
            } else {
                validCard = true;
            }
        }
    }
    
    if (!SCard.getIsNumber()){}{
        if (SCard.getType() == "PLUS2"){
            Plus2 *plus2 = new Plus2();
            plus2->executeActionUNO(Game);
        }
        else if (SCard.getType() == "PLUS4"){
            Plus4 *plus4 = new Plus4();
            plus4->executeActionUNO(Game);
        }
        else if (SCard.getType() == "SKIP"){
            Skip *skip = new Skip();
            skip->executeActionUNO(Game);
        }
        else if (SCard.getType() == "UNOREVERSE"){
            UnoReverse *unoReverse = new UnoReverse();
            unoReverse->executeActionUNO(Game);
        }
        else if (SCard.getType() == "CHANGECOLOR"){
            ChangeColor *changeColor = new ChangeColor();
            changeColor->executeActionUNO(Game);
        }
    }

    /* add to deck card, retrieve from player deck */
    TableCard<UnoCard>& tableCard = Game.getTableCard();
    tableCard.addCard(playernow.getCard(input_number-1));
    playernow.getDeckPlayer().erase(playernow.getDeckPlayer().begin() + input_number-1);
    
    Game.setValid(true);
    Game.setAlreadyDraw(false);
}