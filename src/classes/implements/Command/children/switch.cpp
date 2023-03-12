#include "../../../headers/Command/children/switch.hpp"

Switch::Switch(){
    commandId = 9;
}

void Switch::executeAction(CandyGame& Game){
    Player& playernow = Game.getPlayer(Game.getPlayerTurn());
    int playerTurn = Game.getPlayerTurn();
    if (playernow.getAbilityCard().getType() != "SWITCH"){
        cout << "\nEits, kamu tidak memiliki kartu SWITCH!\n" << endl;
    } else if (playernow.checkValidAbilityCard("SWITCH")){
        cout << endl << playernow.getNickname() << " melakukan switch!" << endl;
        cout << "Kartumu sekarang adalah:" << endl;
        playernow.printCard();

        // choose a player
        cout << "\nSilahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        for (int i=0; i<Game.getNPlayers(); i++){
            // print player list that can be switched (all exc the current player)
            if (i!=playerTurn){
                if (i<playerTurn){
                    cout << i+1 << ". ";
                } else {
                    cout << i << ". ";
                }
                cout << Game.getPlayer(i).getNickname() << endl;
            }
        }
        
        int idxSwitch;
        bool validInput = false;
        while(!validInput){
            try{
                cout << "Pilihan : ";
                cin >> idxSwitch; // input nomor sesuai output list player yang bisa di-switch
                if(idxSwitch < 1 || idxSwitch > 6){
                    cout << "\nInput tidak valid!\n" << endl;
                } else {
                    validInput = true;
                }
            } catch(...){
                cout << "\nInput tidak valid!\n" << endl;
            }
        }

        if (idxSwitch <= playerTurn){
            idxSwitch--;
        }

        // switch
        Player& playerSwitch = Game.getPlayer(idxSwitch);
        vector<Card>& deck0 = playernow.getDeckPlayer();
        vector<Card>& deck1 = playerSwitch.getDeckPlayer();
        Card cardnow_1 = playernow.pop();
        Card cardnow_0 = playernow.pop();
        Card cardswitch_1 = playerSwitch.pop();
        Card cardswitch_0 = playerSwitch.pop();

        deck0.push_back(cardswitch_0);
        deck0.push_back(cardswitch_1);
        deck1.push_back(cardnow_0);
        deck1.push_back(cardnow_1);

        cout << "\nKedua kartu " << playernow.getNickname() << " telah ditukar dengan " << playerSwitch.getNickname() << "!" << endl;
        cout << "Kartumu sekarang adalah:" << endl;
        playernow.printCard();
        playernow.useAbilityCard();

        Game.setValid(true);
    } else {
        cout << "\nOops, kartu ability switchmu telah dimatikan sebelumnya :(.\nSilahkan lakukan perintah lain.\n";
    }
}