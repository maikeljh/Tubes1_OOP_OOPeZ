#include "../../headers/Game/candyGame.hpp"
#include "../../headers/CardGenerator/cardGenerator.hpp"
#include "../../headers/Command/commandParser.hpp"
#include "../generic.cpp"
#include <iostream>

using namespace std;

/* ctor, dtor */
CandyGame::CandyGame():Game(),table(5){
    this->round = 0;
    this->point = 0;
    this->phase = 0;
}

CandyGame::CandyGame(const CandyGame& other):Game(other),table(5){
    this->round = other.round;
    this->point = other.point;
    this->phase = other.phase;
}

CandyGame::~CandyGame(){}

/* getter */
int CandyGame::getRound(){
    return this->round;
}

long long int CandyGame::getPoint(){
    return this->point;
}

vector<CandyPlayer>& CandyGame::getPlayers(){
    return this->players;
}

CandyPlayer& CandyGame::getPlayer(int idx){
    return this->players[idx];
}

DeckCard<Card>& CandyGame::getDeckCard(){
    return this->deck;
}

DeckCard<AbilityCard>& CandyGame::getAbilityDeckCard(){
    return this->deckAbility;
}

TableCard<Card>& CandyGame::getTableCard(){
    return this->table;
}

int CandyGame::getPhase(){
    return this->phase;
}

long long int CandyGame::getMaxPoint(){
    return this->maxPoint;
}

/* setter */
void CandyGame::setRound(int round){
    this->round = round;
}

void CandyGame::setPoint(long long int point){
    this->point = point;
}

void CandyGame::setPhase(int phase){
    this->phase = phase;
}


/* other functions */
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
                throw InputActionInvalidExc();
            }
        } catch (GameException& err){
            cout << err.what() << endl;
        }
    }

    cout << "Urutan kartu berhasil dibuat" << endl;
    cout << "\nSilahkan input nama-nama pemain" << endl;

    for(int i = 1; i <= 7; i++){
        cout << "Pemain " << i << ": ";
        cin >> name;
        CandyPlayer newPlayer = CandyPlayer(this->deck, name);
        this->players.push_back(newPlayer);
    }
    
    CommandParser CP;
    string command;
    
    while(!isEndGame()){
        cout << "\nPERMAINAN KE-" << ++this->phase;
        this->point = 64;
        while(this->round < 6){
            this->round++;
            cout << "\nRONDE " << this->round << endl;;
            if(this->round == 2){
                cout << "Kartu ability telah dibagikan ke seluruh pemain" << endl;
                this->deckAbility = CG.generateAbilityDeck();
                for(int i = 0; i < 7; i++){
                    this->players[i].addAbilityCard(this->deckAbility.pop());
                }
            }
            this->playerTurn = 0;
            for(int i = 0; i < 7; i++){
                cout << "\nSekarang adalah giliran pemain " << this->players[0].getNickname() << endl;
                while(!this->valid){
                    try{
                        cout << "Command : ";
                        cin >> command;
                        Command *action = CP.parser(command);
                        action->executeAction(*this);
                        delete action;
                    } catch(GameException& err){
                        cout << err.what() << endl;
                    }
                }
                CandyPlayer& move = this->players[0];
                this->players.push_back(move);
                this->players.erase(this->players.begin() + 0);
                this->valid = false;
                this->playerTurn++;
            }
            if(this->round < 6){
                Card newTableCard = this->deck.pop();
                cout << "\nTelah tertambah di meja yaitu Kartu " << newTableCard.getNumber() << " " << newTableCard.getColor() << endl;
                this->table.push(newTableCard);
            }
            CandyPlayer& move = this->players[0];
            this->players.push_back(move);
            this->players.erase(this->players.begin() + 0);
        }

        // Penambahan poin untuk pemenang babak
        for (int i = 0; i < 7; i++) {
            this->players[i].getCombo().mergeCard(this->table.getTableCard(), this->players[i].getDeckPlayer());
            cout << "\nSaat penggabungan";
            this->players[i].getCombo().printCombo();
            this->players[i].getCombo().makeCombo();
            cout << "Combo akhir : " << endl;
            this->players[i].getCombo().printCombo();
            cout << "Kartu player " << this->players[i].getNickname() << endl;
            this->players[i].printCard();
            cout << "Dengan poin combo sebesar : " << this->players[i].getCombo().getValue() << endl;
        }

        int roundWinner = this->chooseRoundWinner();
        this->players[roundWinner].addPoint(this->point);
        cout << "\nSelamat kepada pemain " << this->players[roundWinner].getNickname() << " telah memenangkan babak dan memperoleh poin sebanyak " << this->point << endl;
        cout << "Dengan combo "; this->players[roundWinner].getCombo().printCombo();
        cout << "Kartu player " << this->players[roundWinner].getNickname() << endl;
        this->players[roundWinner].printCard();
        cout << "Dengan poin combo sebesar : " << this->players[roundWinner].getCombo().getValue() << endl;

        if(!isEndGame()){
            // Restart Game clear
            this->round = 0;
            for(int i = 0; i < 7; i++){
                --this->players[i];
                --this->players[i];
                this->players[i].getCombo().clearCombo();
                this->players[i].getAbilityCard().setType("");
                this->players[i].getAbilityCard().setUseable(false);
            }
            this->table.clearTable();
            
            cout << "\nKartu dikembalikan dan disusun ulang" << endl;
            // Buang Kartu Dari Deck
            while(this->deck.getNeff() != 0){
                --this->deck;
            }
            
            action = "";
            // Generate Deck Again
            while(action != "y" && action != "n" && action != "no" && action != "yes"){
                try {
                    cout << "Apakah urutan kartu ingin dibaca dari file? (y or n) : ";
                    cin >> action;

                    if(action == "y" || action == "yes"){
                        this->deck = CG.readFile("./config/orderCards.txt");
                    } else if (action == "n" || action == "no"){
                        this->deck = CG.randomizeCard();
                    } else {
                        throw InputActionInvalidExc();
                    }
                } catch (GameException& err){
                    cout << err.what() << endl;
                }
            }
            // Restart Game Player Card
            for(int i = 0; i < 7; i++){
                this->players[i] = this->players[i] + this->deck.pop();
                this->players[i] = this->players[i] + this->deck.pop();
            }
        }
    }

    // Print leaderboard and winner
    EndGame GG;
    GG.printLeaderboard(*this);
}

int CandyGame::chooseWinner(){
    return findIndexMaxValue(this->players);
}

int CandyGame::chooseRoundWinner() {
    vector<Combination> combos;
    for(int i = 0; i < 7; i++){
        combos.push_back(this->players[i].getCombo());
    }
    return findIndexMaxValue(combos);
}

bool CandyGame::isEndGame(){
    CandyPlayer maximum = maxValue<CandyPlayer>(this->players);
    if(maximum.getPoint() >= this->maxPoint){
        return true;
    } else {
        return false;
    }
}