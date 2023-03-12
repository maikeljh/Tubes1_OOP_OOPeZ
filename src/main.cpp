#include <iostream>
#include "./classes/headers/Game/candyGame.hpp"
#include "./classes/headers/Game/unoGame.hpp"

using namespace std;

int main(){
    cout << "Please choose a game :\n1. Candy Game\n2. Uno Game" << endl;
    string action = "";
    while(action != "1" && action != "2"){
        try {
            cout << "Enter option (1 or 2): ";
            cin >> action;
            if(action != "1" && action != "2"){
                throw "Input tidak valid!";
            }
        } catch (...){
            cout << "Input tidak valid!" << endl;
        }
    }

    if(action == "1"){
        CandyGame GG;
        GG.startGame();
    } else if(action == "2") {
        UnoGame GG;
        GG.startGame();
    }
}