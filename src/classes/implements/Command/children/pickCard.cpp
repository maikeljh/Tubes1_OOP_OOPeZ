#include "../../../headers/Command/children/pickCard.hpp"
#include <limits>

/* Ctor */
PickCard::PickCard(){}

/* Choose card to use */
void PickCard::executeAction(UnoGame& Game){
    // Validasi ada kartu yang bisa dipakai atau tidak
    if(!checkValid(Game)){
        cout << "\nMaaf, kamu tidak punya kartu yang bisa dipakai. Silahkan draw!" << endl;
    } else {
        int input_number;
        UnoPlayer& playernow = Game.getPlayer(0);
        UnoCard SCard;

        // Print kartu yang ada dulu
        cout << "\nKartu yang dimiliki player sekarang: " << endl;
        playernow.printCard();

        bool validCard = false;
        // Validasi input dan kartu
        while(!validCard){
            try {
                cout << "\nSilahkan pilih nomor kartu yang ingin digunakan : ";
                cin >> input_number;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw InputActionInvalidExc();
                }
                if(!(input_number-1 >= 0 && input_number-1 < playernow.getDeckPlayer().size())){
                    throw InputNumberInvalidExc();
                } else {
                    // Validasi input kartu yang bisa dikeluarkan
                    SCard = playernow.getDeckPlayer()[input_number-1];
                    if (!(Game.getTop() == SCard)){
                        cout << "\nKartu tidak bisa dipakai. Silahkan pilih kartu lain!" << endl;
                    } else {
                        validCard = true;
                    }
                }
            } catch(GameException& err){
                cout << endl << err.what() << endl;
            }
        }
        
        /* add to deck card, retrieve from player deck */
        TableCard<UnoCard>& tableCard = Game.getTableCard();
        tableCard.push(playernow.getCard(input_number-1));
        playernow.getDeckPlayer().erase(playernow.getDeckPlayer().begin() + input_number-1);

        if (!SCard.getIsNumber()){
            if (SCard.getType() == "PLUS2"){
                Plus2 *plus2 = new Plus2();
                plus2->executeAction(Game);
            }
            else if (SCard.getType() == "PLUS4"){
                Plus4 *plus4 = new Plus4();
                plus4->executeAction(Game);
            }
            else if (SCard.getType() == "SKIP"){
                Skip *skip = new Skip();
                skip->executeAction(Game);
            }
            else if (SCard.getType() == "UNOREVERSE"){
                UnoReverse *unoReverse = new UnoReverse();
                unoReverse->executeAction(Game);
            }
            else if (SCard.getType() == "CHANGECOLOR"){
                ChangeColor *changeColor = new ChangeColor();
                changeColor->executeAction(Game);
            }
        }
        
        Game.setValid(true);
        Game.setAlreadyDraw(false);
    }
}

/* Check if the current player can use one of their cards or not */
bool PickCard::checkValid(UnoGame& Game){
    vector<UnoCard>& now = Game.getPlayer(0).getDeckPlayer();
    for(int i = 0; i < now.size(); i++){
        if(now[i] == Game.getTop()){
            return true;
        }
    }

    return false;
}