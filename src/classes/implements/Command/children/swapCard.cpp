#include "../../../headers/Command/children/swapCard.hpp"

SwapCard::SwapCard(){
    commandId = 8;
}

void SwapCard::executeAction(CandyGame& Game){
    int playerTurn = Game.getPlayerTurn();
    Player playernow = Game.getPlayer(playerTurn);
    if (playernow.checkValidAbilityCard("SWAPCARD")){
        cout << playernow.getNickname() << " melakukan SWAPCARD." << endl;
        vector<int> playerSwap;

        // choose 1st player to be swapped
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        for (int i=0; i<Game.getNPlayers(); i++){
            // print player list that can be swapped (all exc the current player)
            if (i!=playerTurn){
                if (i<playerTurn){
                    cout << i+1 << ". ";
                } else {
                    cout << i << ". ";
                }
                cout << Game.getPlayer(i).getNickname() << endl;
            }
        }
        int p;
        cin >> p; // input nomor sesuai output list player yang bisa di-swap
        if (p<playerTurn){
            p--;
        }
        playerSwap.push_back(p);
        
        // choose 2nd player to be swapped
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        for (int i=0; i<Game.getNPlayers(); i++){
            // print player list that can be swapped (all exc the current player and the player chosen)
            if (i!=playerTurn && i!=playerSwap[0]){
                if (i<playerTurn && i<playerSwap[0]){
                    cout << i+1 << ". ";
                } else {
                    if (playerTurn<playerSwap[0]) {
                        if (i < playerSwap[0]){
                            cout << i << ". ";
                        } else {
                            cout << i-1 << ". ";
                        }
                        cout << i << ". ";
                    } else if (playerTurn>playerSwap[0]){
                        if (i < playerTurn){
                            cout << i << ". ";
                        } else {
                            cout << i-1 << ". ";
                        }
                    }
                }
                cout << Game.getPlayer(i).getNickname() << endl;
            }
        }
        cin >> p; // input nomor sesuai output list player yang bisa di-swap
        if (p<playerTurn && p<playerSwap[0]){
            p--;
        } else {
            if (playerTurn<playerSwap[0]){
                if (p > playerSwap[0]){
                    p++;
                }
            } else if (playerTurn>playerSwap[0]) {
                if (p > playerTurn){
                    p++;
                }
            }
        }
        playerSwap.push_back(p);

        
        // choose cards to be swapped
        int count = 0;
        vector<int> cardSwap;
        while (count<2){
            cout << "Silakan pilih kartu kanan/kiri pemain " << Game.getPlayer(playerSwap[count]).getNickname() << ":" << endl;
            cout << "1. Kanan\n2. Kiri\n";
            int option;
            cin >> option; // 1=kanan, 2=kiri
            cardSwap.push_back(option);
            count++;
        }

        // swap
        Player p0 = Game.getPlayer(playerSwap[0]);
        Player p1 = Game.getPlayer(playerSwap[1]);
        vector<Card>& deck0 = p0.getDeckPlayer();
        vector<Card>& deck1 = p1.getDeckPlayer();
        Card card0_1 = p0.pop();
        Card card0_0 = p0.pop();
        Card card1_1 = p1.pop();
        Card card1_0 = p1.pop();

        if (cardSwap[0]==0){
            if (cardSwap[1]==0){
                // 00 01 & 10 11 --> 10 01 & 00 11
                deck0.push_back(card1_0); // swapped
                deck0.push_back(card0_1);
                deck1.push_back(card0_0); // swapped
                deck1.push_back(card1_1);
            } else {
                // cardSwap[1]==1
                // 00 01 & 10 11 --> 11 01 & 10 00
                deck0.push_back(card1_1);
                deck0.push_back(card0_1);
                deck1.push_back(card1_0);
                deck1.push_back(card0_0);
            }
        } else {
            // cardSwap[0]==1
            if (cardSwap[1]==0){
                // 00 01 & 10 11 --> 00 10 & 01 11
                deck0.push_back(card0_0);
                deck0.push_back(card1_0);
                deck1.push_back(card0_1);
                deck1.push_back(card1_1);
            } else {
                // cardSwap[1]==1
                // 00 01 & 10 11 --> 00 11 & 10 01
                deck0.push_back(card0_0);
                deck0.push_back(card1_1);
                deck1.push_back(card1_0);
                deck1.push_back(card0_1);
            }
        }
        playernow.useAbilityCard();
        
        Game.setValid(true);
    } else {
        cout << "Oops, kartu SWAP CARD tidak dapat digunakan." << endl;
    }
}