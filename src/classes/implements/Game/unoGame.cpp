#include "../../headers/Game/unoGame.hpp"
#include "../../headers/CardGenerator/cardGenerator.hpp"
#include "../../headers/Command/commandParserUNO.hpp"

#include <iostream>
using namespace std;

/* ctor */
UnoGame::UnoGame():Game(),table(108), alreadyDraw(false), UNO(false){}

/* getter */
vector<UnoPlayer>& UnoGame::getPlayers(){
    return this->players;
}

UnoPlayer& UnoGame::getPlayer(int idx){
    return this->players[idx];
}

DeckCard<UnoCard>& UnoGame::getDeckCard(){
    return this->deck;
}

TableCard<UnoCard>& UnoGame::getTableCard(){
    return this->table;
}

bool UnoGame::getAlreadyDraw(){
    return this->alreadyDraw;
}

bool UnoGame::getUNO(){
    return this->UNO;
}

UnoCard UnoGame::getTop(){
    return this->table.pop();
}

/* setter */
void UnoGame::setAlreadyDraw(bool draw){
    this->alreadyDraw = draw;
}

void UnoGame::setUNO(bool uno){
    this->UNO = uno;
}

/* other methods */
void UnoGame::startGame(){
    string name;
    string action = "";
    cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&#BBGGPPPP5555555PPPGGBB#&&@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#BGGPP555555555555555555555P55J??7??????JYPB&@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&BGP5555555555555555555555555P5Y7~!7?JJJ????JJJJ?77JB@@@@@@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&BGP55555555555555555555PPP5555PY7^~JYJ7~^^^^^^^^^^~!?YY7~Y&@@@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#GP555555555555555555PPP55Y?7?5PPY~:?PY!^:^^^^^^^^^^^^^^^:~?5?^5@@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#GP555555555555555555P5YJ7!!!7?5:~5~:?&G~:^^^^::^!7?J?!~::^^^^::?G~!&@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@#GP5555555555555555555P57^!?JJJ?7~JB..!#@5:^^^^^:?G&@@@@@@&G?^:^^^^:^G7^#@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@&BP5555555555PPP55PP555557:!PB@7:^^^^.5PY@@G.^^^^:~#@&#&&@@@&GPBB7:^^^^^:B!~@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@&G5555555PPP55YJ7!!!~7Y5P5^:BBP5GB:^^^^^:G@@@~:^^^^:B5^~!!!75#G555G@?:^^^^:~#.J" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@&G5555PPP5YJ?!~~7?JJJJY?!~7Y7.BB55P@G.^^^^^^#@&:^^^^^^&.!P555J~^P#G#&B&~^^^^^.G?:" << endl;
    cout << "@@@@@@@@@@@@@@@@@&G555P5Y?7!!7?JP#G!!~^::^!JYJ!~..#B#&B&Y.^^^^:~@&:^^^^^:#~^P555PPJ.Y@BPB@J:^^^^:Y5 " << endl;
    cout << "@@@@@@@@@@@@@@@@BP55P57^7JJYJ?!~!@@~:^^^^^^:^~?YY!7@#PG&@7:^^^^:?@7:^^^^:?B.7PP555P? B#&@@?:^^^^.5Y." << endl;
    cout << "@@@@@@@@@@@@&#BG55557:7GB@?.^^^^:7@&^^^^^^^^^^^:~7YB&@@@@&~:^^^^.5#:^^^^^:JG^~J5PPP5 J@@@G:^^^^^:#^7" << endl;
    cout << "@@@@@@@#GY?77?:7P55::BBP5P#~:^^^^.Y@G:^^^^^^^^^^^^:^!YB@@@#:^^^^^.BG:^^^^^:!5Y!!!77~^#@#J:^^^^^.5Y.#" << endl;
    cout << "@@@#J77??JJJ75G ?PP? 5#55P&#:^^^^^:G@5.^^^^^.~^:^^^^^::~JG@G:^^^^^:&B^:^^^^^:~?JJJJY5Y7^:^^^^::55.G@" << endl;
    cout << "@#?^J#&?~^^:^.GY.YPP! G##&B#P.^^^^^:#@?:^^^^:7#P7^::^^^^::~?~:^^^^:~@&J^:^^^^^^:^^^^::^^^^^::7G?^B@@" << endl;
    cout << "7:Y&@@@P.^^^^^:#7:5P5^:&#PB&@J.^^^^:~@@~:^^^^:J@@&G?~::^^^^^::^^^^^:?@@&5!^::^^^^^^^^^^^::^?BP~?&@@@" << endl;
    cout << "!.#@@@@@Y.^^^^:~&^~PP5.~&&@@@@7:^^^^:?@#:^^^^^.P@@@@&GJ~::^^^^^^^^^^.Y@@@@#PJ!~^^^^^^~!?5B&G!~G@@@@@" << endl;
    cout << "@~^@@@@@@7:^^^^:7#.7PPJ ?@@@@@&^:^^^^.Y@G.^^^^^:B@@@@@@@BY!^:^^^^^^^^.G@@@@@@@@&####&@@@#5!!G@@@@@@@" << endl;
    cout << "@#:7@@@@@@~:^^^^.YG JPP? 5@@@@@B:^^^^^:B@Y.^^^^:^&@@@@@@@@@#57^:^^^^^::#@&@@@@@@@@@&BPJ!!Y#@@@@@@@@@" << endl;
    cout << "@@G Y@@@&##:^^^^^.GY.YPP! B@@@@@5.^^^^:!@@7:^^^^:7#7Y#@@@@@@@@#P7^^~!J5#5:!7?????7!~7YG&@@@@@@@@@@@@" << endl;
    cout << "@@@Y G@BP5BP:^^^^^:#7:5P5^:&@@@@&:^^^^^:#@&~:^^^^.YP .!JB@@@@@@@@&#@@@P~^?YYJJJJJY5B@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@7.#G55P@Y:^^^^:~#!^YP5.!@@@@G:^^^^^.#@@#:^^^^^.PJ.?7~~?G&@@@@&B5J~^?5P55PP55PB@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@&^~&GB&B&7:^^^^:~PY!!?^:&@@P^^^^^^:~@@@@P.:::^~?@~:5PY?~~?J7!~!7?Y5P555555PB&@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@#.7@#PG&@7:^^^^^:!JJJJ55?~:^^^^^:~#@@@@@Y?5G#@#?^!555PP5??J55PPP5555555PB&@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@P Y&&@@@@Y::^^^^^:^^^^:^^^^^^:^JPJ@@@@@@@@#G7:!5P555555PP55555555555P#@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@5 5@@@@@@#?^::^^^^^^^^^^::^75P7:.?@&B5J7~~!75P555555555555555555PB&@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@P.?&@@@@@@&P?!~^^^^^~!?5B#G!:75J:!~!7?Y55PP55555555555555555PG#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@@#7^5&@@@@@@@@&&###&@@@&5~^?5P5P555PPP5555555555555555555PB#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@@@@B7~?P#@@@@@@@@@&#PJ!~!J5P5555555555555555555555555PG#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@@@@@@&GJ777????77!!!!?Y5PP5555555555555555555555PGB#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@&#GP5YY555PP5555555555555555555PPGBB#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@&#BBGGPPPP5555PPPPPGGB##&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;

    cout << "\nHalo! Selamat Datang di Kompetisi Kartu UNO" << endl;

    CardGenerator CG;

    while(action != "y" && action != "n" && action != "no" && action != "yes"){
        try {
            cout << "\nApakah urutan kartu ingin dibaca dari file? (y or n) : ";
            cin >> action;

            if(action == "y" || action == "yes"){
                bool validDeck = false;
                while(!validDeck){
                    try{
                        string pathfile = "./config/";
                        string inputPath;
                        cout << "\nMasukkan nama file konfigurasi: ";
                        cin >> inputPath;
                        pathfile += inputPath + ".txt";
                        this->deck = CG.readUnoFile(pathfile);
                        validDeck = true;
                    } catch(GameException& err2){
                        cout << err2.what() << endl;
                    }
                }
            } else if (action == "n" || action == "no"){
                this->deck = CG.randomizeUnoCard();
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
        UnoPlayer newPlayer = UnoPlayer(this->deck, name);
        this->players.push_back(newPlayer);
    }
    
    CommandParserUNO CP;
    string command;

    // Initialize Card
    bool flag = false;
    while(!flag){
        this->getTableCard().push(this->deck.pop());
        if(this->getTop().getType()=="CHANGECOLOR"){
            cout<<"\nKartu pertama adalah Wild Card Change Color"<<endl;
            ChangeColor().executeAction(*this);
            flag = true;
        }
        else if(this->getTop().getType()=="PLUS4"){
            UnoCard temp = this->getDeckCard().getCard(1);
            for (int i = 0;i<this->getDeckCard().getSize()-1;i++){
                this->getDeckCard().setCard(this->getDeckCard().getCard(i),i+1);
                temp = this->getDeckCard().getCard(i+2);
            }
            this->getTableCard().clearTable();
            cout<<"\nKartu pertama adalah Wild Card PLUS4, mengulangi pengambilan kartu pertama."<<endl;
            cout<<"Pengambilan ulang kartu pertama ..."<<endl;
        }
        else {
            flag = true;
        }
    }

    while(!isEndGame()){
        cout << "\nKartu baru di atas meja adalah ";
        this->getTop().printDetail();
        cout << "\nSekarang adalah giliran pemain " << this->players[0].getNickname() << endl;
        while(!this->valid){
            try{
                cout << "Command : ";
                cin >> command;
                Command<UnoGame> *action = CP.parser(command);
                action->executeAction(*this);
                delete action;
            } catch(GameException& err){
                cout << endl << err.what() << endl;
            }
            if(this->deck.getNeff() < 5){
                this->deck = CG.randomizeUnoCard();
                UnoCard temp = this->table.pop();
                this->table.clearTable();
                this->table.push(temp);
                cout << "Deck kartu terbuat ulang karena sudah hampir habis.\n" << endl;
            }
        }
        this->valid = false;
        UnoPlayer& move = this->players[0];
        if (move.getDeckPlayer().size() == 1){
            if (!this->UNO){
                cout << "\nPlayer " << move.getNickname() << " lupa mengatakan UNO!" << endl;
                cout << "\nKartu yang didapat oleh " << move.getNickname() << ":\n";
                move = move + this->getDeckCard().pop();
                move.getCard(move.getDeckPlayer().size()-2).printDetail();
                move = move + this->getDeckCard().pop();
                move.getCard(move.getDeckPlayer().size()-1).printDetail();
            }
            this->setUNO(false);
        }
        this->players.push_back(move);
        this->players.erase(this->players.begin() + 0);
        this->UNO = false;
        if(this->deck.getNeff() < 5){
            this->deck = CG.randomizeUnoCard();
            UnoCard temp = this->table.pop();
            this->table.clearTable();
            this->table.push(temp);
            cout << "\nDeck kartu terbuat ulang karena sudah hampir habis." << endl;
        }
    }

    int winner = this->chooseWinner();
    cout << "\nPermainan berakhir." << endl;
    cout << "Permainan dimenangkan oleh " << this->getPlayer(winner).getNickname() << endl;
}

int UnoGame::chooseWinner(){
    for(int i = 0; i < 7; i++){
        if(this->players[i].getDeckPlayer().size() == 0){
            return i;
        }
    }

    return -1;
}

bool UnoGame::isEndGame(){
    for(int i = 0; i < 7; i++){
        if(this->players[i].getDeckPlayer().size() == 0){
            return true;
        }
    }

    return false;
}