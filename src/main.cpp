#include <iostream>
#include "./classes/headers/Game/candyGame.hpp"
#include "./classes/headers/Game/unoGame.hpp"
#include "./classes/headers/Exception/exception.h"
#include <limits>

using namespace std;

int main(){
    while(true){
        /* Choose which game to play */
        cout << "\nPlease choose a game :\n1. Candy Game\n2. Uno Game" << endl;
        string action = "";
        while(action != "1" && action != "2"){
            try {
                cout << "Enter option (1 or 2): ";
                cin >> action;
                /* Handling exception */
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw InputActionInvalidExc();
                }
                if(action != "1" && action != "2"){
                    throw InputNumberInvalidExc();
                }
            } catch (GameException& err){
                cout << err.what() << endl;
            }
        }

        /* Run Game */
        if(action == "1"){
            CandyGame GG;
            GG.startGame();
        } else if(action == "2") {
            UnoGame GG;
            GG.startGame();
        }

        /* Choose to play again or exit */
        action = "";
        cout << "\nLanjut?\n   1. Main Lagi\n   2. Exit" << endl;
        while(action != "1" && action != "2"){
            try {
                cout << "Enter option (1 or 2): ";
                cin >> action;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw InputActionInvalidExc();
                }
                if(action != "1" && action != "2"){
                    throw InputNumberInvalidExc();
                }
            } catch (GameException& err){
                cout << err.what() << endl;
            }
        }
        if(action == "2") {
            break;
        }
    }
    cout << "\nTerima kasih telah memainkan permainan kami :)" << endl;
}