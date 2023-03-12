#include "../../headers/Inventory/children/Player/unoPlayer.hpp"

using namespace std;

UnoPlayer::UnoPlayer(){}

UnoPlayer::UnoPlayer(DeckCard<BaseCard> &DC, string nickname): Player(nickname){

}

UnoPlayer& UnoPlayer::operator=(UnoPlayer& other){
    int j = 0;
    for (BaseCard i : other.getDeckPlayer()){
        this->getDeckPlayer().push_back(other.getDeckPlayer()[j]);
        j++;
    }
}
UnoPlayer& UnoPlayer::operator+(const BaseCard& add){
    
}
UnoPlayer& UnoPlayer::operator-(){}
UnoPlayer::~UnoPlayer(){}
void UnoPlayer::printCard(){
    int j = 1; 
    for (BaseCard i : getDeckPlayer()){
        cout << j << ". " << this->getDeckPlayer()[1].getNumber() << " " << this->getDeckPlayer()[1].getColor() << endl;
        j++;
    }
}