#include "../../../headers/Inventory/children/Player/unoPlayer.hpp"

using namespace std;

/* Ctor */
UnoPlayer::UnoPlayer(){}

UnoPlayer::UnoPlayer(DeckCard<UnoCard> &DC, string nickname):Player(nickname){
    this->push(DC, 7);
}

/* Operators */
UnoPlayer& UnoPlayer::operator+(const UnoCard& add){
    this->push(add);
    return *this;
}

UnoPlayer& UnoPlayer::operator-(const UnoCard& min){
    for(int i = 0; i < this->mainDeck.size(); i++){
        if(this->mainDeck[i] == min){
            this->mainDeck.erase(this->mainDeck.begin() + i);
            break;
        }
    }
    return *this;
}

UnoPlayer& UnoPlayer::operator--(){
    UnoCard trash = this->pop();
    return *this;
}

/* Other methods */
void UnoPlayer::printCard(){
    vector<UnoCard> deck = this->mainDeck;
    for(int i = 0; i < deck.size(); i++){
        if(deck[i].getIsNumber()){
            cout << i+1 << ". " << deck[i].getNumber() << " " << deck[i].getColor() << endl;
        } else {
            cout << i+1 << ". " << deck[i].getType() << " " << deck[i].getColor() << endl;
        }
    }
}