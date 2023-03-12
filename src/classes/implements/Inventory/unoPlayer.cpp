#include "../../headers/Inventory/children/Player/unoPlayer.hpp"

using namespace std;

UnoPlayer::UnoPlayer(){}

UnoPlayer::UnoPlayer(DeckCard<UnoCard> &DC, string nickname):Player(nickname){

}

UnoPlayer& UnoPlayer::operator=(UnoPlayer& other){
    int j = 0;
    for (UnoCard i : other.getDeckPlayer()){
        this->getDeckPlayer().push_back(other.getDeckPlayer()[j]);
        j++;
    }
}
UnoPlayer& UnoPlayer::operator+(const UnoCard& add){
    
}
UnoPlayer& UnoPlayer::operator-(){}
UnoPlayer::~UnoPlayer(){}
void UnoPlayer::printCard(){
    int j = 1; 
    for (UnoCard i : getDeckPlayer()){
        cout << j << ". " << this->getDeckPlayer()[1].getNumber() << " " << this->getDeckPlayer()[1].getColor() << endl;
        j++;
    }
}