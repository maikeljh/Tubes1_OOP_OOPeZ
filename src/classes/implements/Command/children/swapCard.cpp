#include "../../../headers/Command/children/swapCard.hpp"

SwapCard::SwapCard(){
    commandId = 8;
}

void SwapCard::executeAction(CandyGame& Game){
    int playerTurn = Game.getPlayerTurn();
    Player playernow = Game.getPlayer(playerTurn);
    if (playernow.getAbilityCard().getType() != "SWAPCARD"){
        cout << "Eits, kamu tidak memiliki kartu SWAPCARD!" << endl;
    } else if (playernow.checkValidAbilityCard("SWAPCARD")){
        cout << playernow.getNickname() << " melakukan SWAPCARD." << endl;
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
        cin >> p; // input nomor sesuai output list player yang bisa di-swap
        playerSwap.first = indexPlayers[p-1];
        indexPlayers.erase(indexPlayers.begin() + (p-1));
        
        // choose 2nd player to be swapped
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        for (int i = 0; i < indexPlayers.size(); i++){
            cout << i+1 << ". " << Game.getPlayer(indexPlayers[i]).getNickname() << endl;
        }

        cin >> p; // input nomor sesuai output list player yang bisa di-swap
        playerSwap.second = indexPlayers[p-1];
        indexPlayers.erase(indexPlayers.begin() + (p-1));


        // Choose cards to be swapped
        vector<int> cardSwap;
        cout << "Silakan pilih kartu kanan/kiri pemain " << Game.getPlayer(playerSwap.first).getNickname() << ":" << endl;
        cout << "1. Kanan\n2. Kiri\n";
        int option;
        cin >> option; // 1=kanan, 2=kiri
        cardSwap.push_back(option);

        cout << "Silakan pilih kartu kanan/kiri pemain " << Game.getPlayer(playerSwap.second).getNickname() << ":" << endl;
        cout << "1. Kanan\n2. Kiri\n";
        cin >> option; // 1=kanan, 2=kiri
        cardSwap.push_back(option);

        // swap
        Player& p0 = Game.getPlayer(playerSwap.first);
        Player& p1 = Game.getPlayer(playerSwap.second);
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
            if (cardSwap[1]==2){
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
        cout << "Oops, kartu SWAPCARD tidak dapat digunakan." << endl;
    }
}