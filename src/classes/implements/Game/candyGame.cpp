#include "../../headers/Game/candyGame.hpp"
#include "../../headers/CardGenerator/cardGenerator.hpp"
#include "../../headers/Command/commandParser.hpp"
#include <iostream>

using namespace std;

CandyGame::CandyGame():Game(5){
    this->round = 0;
    this->point = 0;
}

CandyGame::CandyGame(const CandyGame& other):Game(other){
    this->round = other.round;
    this->point = other.point;
}

CandyGame::~CandyGame(){}

void CandyGame::startGame(){
    string name;
    string action = "";
    cout << "@@@@@@@@@@@@@@@@@G7^P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "@@@@@@@@@@@@@@@@J   !??JY5PB#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "@@@@@@@@@@@@@@&!         ....:~?5#G!!#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "@@@@@@@@@@@@@#^    :^^^~Y~^^^^:     ^&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "@@@@@@@&#BGPB^   .!^:.^!?:...:!!:  !&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "@@@&GJ!~^^^!^    ^~..JB#JY~7^7?:! ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "@@GY~::^^^~7:.   .7:.??Y##B#PY.~!Y@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "@P7?J?!^^~7!~~~~: .~^^~!Y55Y?~~~Y@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "B7??7???7JYJJJ!^~7!~~~~~~~~^^:^!!&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "57????77J5???JY?7JYJJJJJJ????JJ^JYJ5G&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "G77?????JYJJJYJYYJJYY?JJJ???JYJG@&BPYY?P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" <<
            "@P?77?7?5JJJJJJYYJY5!^^~!?JJG&@@@@@@@#7.!#@@@@@@@@@@@@@@@@@&BP5JJYYJ?YP#@@@@@@@@\n" <<
            "@@#PJ?7JY???????????JJ?7!~^^7YG&@@@@@@B::B@@@@@@@@@@@@@&&&Y!^^~!~^~YP~^^7G@@@@@@\n" <<
            "@@@@@#GGJ???????????????JJJYY7~^!JP##Y~7B@@@@@@@@@@@@&~..!#?~~?^    &5^7^^5&@@@@\n" <<
            "@@@@@@@#???????????????????P@@@#P~:^^:7G&@@@@@@@@@@@@B.  ^YJJY?!~~^?G!^77!??&@@@\n" <<
            "@@@@@@@B55YYJJJJJJJ????????P@@@G!^Y#B5?~^!?5B&@@@@@@@5!!?~?#&#P!^~7J^^~^~~~^Y@@@\n" <<
            "@@@@@@@G5555P55555555555555P@@#??#@@@@@@#PJ:.^J&@@@@@&G?~^?JJ?5G5!!?~~~~^^^^~&@@\n" <<
            "@@@@@@@@B555PBGGGGGPPPGGG555#@@&@@@@@@@@@@@G?Y7~75&@@@&J^~YB#B#55~~~^~~~~~~~^P@@\n" <<
            "@@@@@@@@@#P55B@@@@@@@@@@@B55P@@@@@@@@@@@@@@@@@GY77!Y#@@?!7~75GGJ!^^^~~~~~~~~^Y@@\n" <<
            "@@@@@@@@@@&P55G@@@@@@@@@@@G55B@@@@@@@@@@@@@@@@@@@@BJ!?GY~^^^^~~^^~~7!^~~~~~~^J@@\n" <<
            "@@@@@@@@@@@&P55G@@@@@@@@@@@G55P@@@@@@@@@@@@@@@@@@@@@&57!!!!!!~~!!7!!7!^~~~~~^5@@\n" <<
            "@@@@@@@@@@@@&&J.J@@@@@@@@@@@&Y.7@@@@@@@@@@@@@@@@@@@@@@@#P7!!!!!!!!7!~~~~~~~^~&@@\n" <<
            "@@@@@@@@@@@@@@G.~@@@@@@@@@@@@@5.!&@@@@@@@@@@@@@@@@@@@@@&BJ!~!!!!!~^^^~~~~^^~YG#@\n" <<
            "@@@@@@@@@@@@@@P.7@@@@@@@@@@@@@@P:~#@@@@@@@@@@@@@@@@B5?7!!YG7^^^^^^^^^^~^^^?BB&@@\n" <<
            "@@@@@@@@@@@@@@!.G@@@@@@@@@@@@@@@B^^B@@@@@@@@@@@@@@@#GPB#@@@@GJ^~!~~!!^^!YB@@@@@@\n" <<
            "@@@@@@@@@@@@@J.J@@@@@@@@@@@@@@@@@#~:G@@@@@@@@@@@@@@@@@@@@@@@@@?~#&@B7!5&@@@@@@@@\n" <<
            "@@@@@@@@@@BB?.Y@@@@@@@@@@@@@@@@@@@&!:P&&@@@@@@@@@@@@@@@@@@@@@@&77&5!Y@@@@@@@@@@@\n" <<
            "@@@@@@@@@@?~~~P@@@@@@@@@@@@@@@@@@@@#~^~7@@@@@@@@@@@@@@@@@@@@@@@@Y!!?5P&@@@@@@@@@\n" <<
            "@@@@@@@@@@@&BB&@@@@@@@@@@@@@@@@@@@@#7?5&@@@@@@@@@@@@@@@@@@@&@@@P!5&#P^?@@@@@@@@@\n" <<
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P7PJ!B@@&Y~Y@@@@@@@@@\n" <<
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P77&@@@@#&@@@@@@@@@@\n";

    cout << "\nHalo! Selamat Datang di Kompetisi Kartu ala Kerajaan Permen" << endl;

    CardGenerator CG;

    while(action != "y" && action != "n" && action != "no" && action != "yes"){
        try {
            cout << "\nApakah urutan kartu ingin dibaca dari file? (y or n) : ";
            cin >> action;

            if(action == "y" || action == "yes"){
                this->deck = CG.readFile("./config/orderCards.txt");
            } else if (action == "n" || action == "no"){
                this->deck = CG.randomizeCard();
            } else {
                throw "Input tidak valid!";
            }
        } catch (...){
            cout << "Input tidak valid!" << endl;
        }
    }

    cout << "Urutan kartu berhasil dibuat" << endl;
    cout << "\nSilahkan input nama-nama pemain" << endl;

    for(int i = 1; i <= 7; i++){
        cout << "Pemain " << i << ": ";
        cin >> name;
        Player newPlayer = Player(this->deck, name);
        this->players.push_back(newPlayer);
    }
    
    CommandParser CP;
    string command;
    
    while(!isEndGame()){
        this->point = 64;
        this->firstIdxTurn = 0;
        this->lastIdxTurn = 6;
        while(this->round < 6){
            this->playerTurn = this->firstIdxTurn;
            this->round++;
            cout << "\nRONDE " << this->round;
            if(this->round == 2){
                this->deckAbility = CG.generateAbilityDeck();
                for(int i = 0; i < 7; i++){
                    this->players[i].addAbilityCard(this->deckAbility.pop());
                }
            }
            for(int i = 0; i < 7; i++){
                cout << "\nSekarang adalah giliran pemain " << this->players[playerTurn].getNickname() << endl;
                while(!this->valid){
                    try{
                        cout << "Command : ";
                        cin >> command;
                        Command *action = CP.parser(command);
                        action->executeAction(*this);
                        delete action;
                    } catch(...){
                        cout << "\nCommand tidak valid!\n" << endl;
                    }
                }
                if(this->isClockWise){
                    this->playerTurn = (this->playerTurn + 1) % 7;
                } else {
                    this->playerTurn = ((this->playerTurn - 1) % 7 + 7) % 7;
                }
                this->valid = false;
            }
            if(this->round < 6){
                this->table.addCard(this->deck.pop());
            }
            if(this->isReverse){
                this->isClockWise = !this->isClockWise;
                this->isReverse = false;
            } else {
                if(this->isClockWise){
                    this->firstIdxTurn = (this->firstIdxTurn + 1) % 7;
                    this->lastIdxTurn = (this->lastIdxTurn + 1) % 7;
                } else {
                    this->firstIdxTurn = ((this->firstIdxTurn - 1) % 7 + 7) % 7;
                    this->lastIdxTurn = ((this->lastIdxTurn - 1) % 7 + 7) % 7;
                }
            }
        }

        // Penambahan poin untuk pemenang babak
        for (int i = 0; i < 7; i++) {
            this->players[i].getCombo().mergeCard(this->table.getTableCard(), this->players[i].getDeckPlayer());
            cout << "\nSaat penggabungan";
            this->players[i].getCombo().printCombo();
            this->players[i].getCombo().makeCombo();
            cout << "Combo akhir : " << endl;
            this->players[i].getCombo().printCombo();
            cout << "DENGAN POIN  " << this->players[i].getCombo().getValue() << endl;
        }

        int roundWinner = this->chooseRoundWinner();
        this->players[roundWinner].addPoint(this->point);
        cout << "\nSelamat kepada pemain " << this->players[roundWinner].getNickname() << " telah memenangkan babak dan memperoleh poin sebanyak " << this->point << endl;
        cout << "Dengan combo "; this->players[roundWinner].getCombo().printCombo();
        cout << "DENGAN POIN  " << this->players[roundWinner].getCombo().getValue() << endl;

        // Restart Game
        this->round = 0;
        this->deck = CG.randomizeCard();
        for(int i = 0; i < 7; i++){
            Card erase = this->players[i].pop();
            erase = this->players[i].pop();
            this->players[i].push(this->deck.pop());
            this->players[i].push(this->deck.pop());
            this->players[i].getCombo().clearCombo();
            this->players[i].getAbilityCard().setType("");
            this->players[i].getAbilityCard().setUseable(false);
        }
        this->table.clearTable();
    }
    cout << "\nSELAMAT KEPADA PEMENANG YAITU " << this->players[chooseWinner()].getNickname();
}

int CandyGame::chooseRoundWinner() {
    Combination maximum = this->players[0].getCombo();
    int idx = 0;
    for (int i = 1; i < 7; i++) {
        if (this->players[i].getCombo() > maximum) {
            maximum = this->players[i].getCombo();
            idx = i;
        }
    }
    return idx;
}


int CandyGame::chooseWinner(){
    double maximum = 0;
    int idx = 0;
    for(int i = 0; i < 7; i++){
        if(this->players[i].getCombo().getValue() > maximum){
            maximum = this->players[i].getCombo().getValue();
            idx = i;
        }
    }
    
    return idx;
}

void CandyGame::setRound(int round){
    this->round = round;
}

void CandyGame::setPoint(long long int point){
    this->point = point;
}

int CandyGame::getRound(){
    return this->round;
}  

long long int CandyGame::getPoint(){
    return this->point;
}

bool CandyGame::isEndGame(){
    for(int i = 0; i < this->nPlayers; i++){
        if(this->players[i].getPoint() >= this->maxPoint){
            return true;
        }
    }

    return false;
}

DeckCard<Card>& CandyGame::getDeckCard(){
    return this->deck;
}