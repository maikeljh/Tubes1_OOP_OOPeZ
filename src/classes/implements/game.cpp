#include "../headers/Game/game.hpp"
#include "../headers/CardGenerator/cardGenerator.hpp"
#include <iostream>

using namespace std;

Game::Game(){
    this->round = 0;
    this->players = new Player[this->nPlayers];
    this->point = 0;
    this->isClockWise = true;
    this->playerTurn = 0;
}

Game::Game(const Game& other){
    this->round = other.round;
    this->players = new Player[this->nPlayers];
    for(int i = 0; i < this->nPlayers; i++){
        this->players[i] = other.players[i];
    }
    this->point = other.point;
    this->isClockWise = other.isClockWise;
    this->playerTurn = other.playerTurn;
}

Game::~Game(){
    delete[] this->players;
}

void Game::startGame(){
    string name;
    string action;
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

            cout << "Apakah urutan kartu ingin dibaca dari file? (y or n) : ";
            cin >> action;

            if(action == "y" || action == "yes"){
                this->deck = CG.readFile("./config/orderCards.txt");
            } else {
                this->deck = CG.randomizeCard();
            }

            cout << "Urutan kartu berhasil dibuat" << endl;

            cout << "\nSilahkan input nama-nama pemain" << endl;

            for(int i = 1; i <= 7; i++){
                cout << "Pemain " << i << ": ";
                cin >> name;
                this->players[i-1] = Player(this->deck, name);
            }

            // TES KARTU PEMAIN
            for(int i = 0; i < 7; i++){
                cout << "\nKartu Pemain " << this->players[i].getNickname() << endl;
                this->players[i].printPlayerCard();
            }

}

int Game::chooseWinner(){
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

void Game::setRound(int round){
    this->round = round;
}

void Game::setPoint(long long int point){
    this->point = point;
}

void Game::setIsClockWise(bool isClockWise){
    this->isClockWise = isClockWise;
}

void Game::setPlayerTurn(int playerTurn){
    this->playerTurn = playerTurn;
}

int Game::getRound(){
    return this->round;
}  

long long int Game::getPoint(){
    return this->point;
}

bool Game::getIsClockWise(){
    return this->isClockWise;
}

int Game::getPlayerTurn(){
    return this->playerTurn;
}
