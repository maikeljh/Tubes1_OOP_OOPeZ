#include "../../../headers/Command/children/swapCard.hpp"
#include <limits>

SwapCard::SwapCard(){}

void SwapCard::executeAction(CandyGame& Game){
    int playerTurn = 0;
    CandyPlayer& playernow = Game.getPlayer(playerTurn);
    if (playernow.getAbilityCard().getType() != "SWAPCARD"){
        cout << "\nEits, kamu tidak memiliki kartu SWAPCARD!\n" << endl;
    } else if (playernow.getAbilityCard().getUseable()){
        cout << endl << playernow.getNickname() << " melakukan SWAPCARD." << endl;
        pair<int,int> playerSwap;
        vector<int> indexPlayers;
        // Choose 1st player to be swapped
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        for (int i = 0; i < Game.getNPlayers(); i++){
            // Print player list that can be swapped (all exc the current player)
            if (i!=playerTurn){
                if (i<playerTurn){
                    cout << i+1 << ". ";
                } else {
                    cout << i << ". ";
                }
                cout << Game.getPlayer(i).getNickname() << endl;
                indexPlayers.push_back(i);
            }
        }
        
        int p;
        bool validInput = false;
        while(!validInput){
            try{
                cout << "Pilihan : ";
                cin >> p; // input nomor sesuai output list player yang bisa di-swap
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw InputActionInvalidExc();
                }
                if(p < 1 || p > 6){
                    throw InputNumberInvalidExc();
                } else {
                    validInput = true;
                }
            } catch(GameException& err){
                cout << err.what() << endl;
            }
        }

        playerSwap.first = indexPlayers[p-1];
        indexPlayers.erase(indexPlayers.begin() + (p-1));
        
        // choose 2nd player to be swapped
        cout << "\nSilahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        for (int i = 0; i < indexPlayers.size(); i++){
            cout << i+1 << ". " << Game.getPlayer(indexPlayers[i]).getNickname() << endl;
        }

        validInput = false;
        while(!validInput){
            try{
                cout << "Pilihan : ";
                cin >> p; // input nomor sesuai output list player yang bisa di-swap
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw InputActionInvalidExc();
                }
                if(p < 1 || p > 5){
                    throw InputNumberInvalidExc();
                } else {
                    validInput = true;
                }
            } catch(GameException& err){
                cout << err.what() << endl;
            }
        }

        playerSwap.second = indexPlayers[p-1];
        indexPlayers.erase(indexPlayers.begin() + (p-1));

        // Choose cards to be swapped
        vector<int> cardSwap;
        cout << "\nSilakan pilih kartu kanan/kiri pemain " << Game.getPlayer(playerSwap.first).getNickname() << ":" << endl;
        cout << "1. Kanan\n2. Kiri\n";
        int option;

        validInput = false;
        while(!validInput){
            try{
                cout << "Pilihan : ";
                cin >> option; // input nomor sesuai output list player yang bisa di-swap
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw InputActionInvalidExc();
                }
                if(option < 1 || option > 2){
                    throw InputNumberInvalidExc();
                } else {
                    validInput = true;
                }
            } catch(GameException& err){
                cout << err.what() << endl;
            }
        }

        cardSwap.push_back(option);

        cout << "\nSilakan pilih kartu kanan/kiri pemain " << Game.getPlayer(playerSwap.second).getNickname() << ":" << endl;
        cout << "1. Kanan\n2. Kiri\n";
        
        validInput = false;
        while(!validInput){
            try{
                cout << "Pilihan : ";
                cin >> option; // input nomor sesuai output list player yang bisa di-swap
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw InputActionInvalidExc();
                }
                if(option < 1 || option > 2){
                    throw InputNumberInvalidExc();
                } else {
                    validInput = true;
                }
            } catch(GameException& err){
                cout << err.what() << endl;
            }
        }

        playernow.useAbilityCard();
        cardSwap.push_back(option);

        // swap
        CandyPlayer& p0 = Game.getPlayer(playerSwap.first);
        CandyPlayer& p1 = Game.getPlayer(playerSwap.second);
        vector<Card>& deck0 = p0.getDeckPlayer();
        vector<Card>& deck1 = p1.getDeckPlayer();
        Card card0_1 = p0.pop();
        Card card0_0 = p0.pop();
        Card card1_1 = p1.pop();
        Card card1_0 = p1.pop();
        if (cardSwap[0]==2){
            if (cardSwap[1]==2){
                // 00 01 & 10 11 --> 10 01 & 00 11
                deck0.push_back(card1_0); // swapped
                deck0.push_back(card0_1);
                deck1.push_back(card0_0); // swapped
                deck1.push_back(card1_1);
                cout << "\nPenggunaan SWAP CARD berhasil untuk kartu kiri pemain " << p0.getNickname() << " dan kartu kiri pemain " << p1.getNickname() << endl;
            } else {
                // cardSwap[1]==1
                // 00 01 & 10 11 --> 11 01 & 10 00
                deck0.push_back(card1_1);
                deck0.push_back(card0_1);
                deck1.push_back(card1_0);
                deck1.push_back(card0_0);
                cout << "\nPenggunaan SWAP CARD berhasil untuk kartu kiri pemain " << p0.getNickname() << " dan kartu kanan pemain " << p1.getNickname() << endl;
            }
        } else {
            // cardSwap[0]==1
            if (cardSwap[1]==2){
                // 00 01 & 10 11 --> 00 10 & 01 11
                deck0.push_back(card0_0);
                deck0.push_back(card1_0);
                deck1.push_back(card0_1);
                deck1.push_back(card1_1);
                cout << "\nPenggunaan SWAP CARD berhasil untuk kartu kanan pemain " << p0.getNickname() << " dan kartu kiri pemain " << p1.getNickname() << endl;
            } else {
                // cardSwap[1]==1
                // 00 01 & 10 11 --> 00 11 & 10 01
                deck0.push_back(card0_0);
                deck0.push_back(card1_1);
                deck1.push_back(card1_0);
                deck1.push_back(card0_1);
                cout << "\nPenggunaan SWAP CARD berhasil untuk kartu kanan pemain " << p0.getNickname() << " dan kartu kanan pemain " << p1.getNickname() << endl;
            }
        }
        
        Game.setValid(true);
    } else {
        cout << "\nOops, kartu SWAPCARD tidak dapat digunakan.\n" << endl;
    }
}