#include "../../headers/Inventory/children/Player/unoPlayer.hpp"

using namespace std;

UnoPlayer::UnoPlayer(){}

UnoPlayer::UnoPlayer(DeckCard<UnoCard> &DC, string nickname):Player(nickname){
// Gw baca2 awal main dapet 7 kartu, tapi nanti klo mo di modif gpp
    for (int i = 0; i < 7; i++){
        this->getDeckPlayer().push_back(DC.pop());
    }
}

UnoPlayer& UnoPlayer::operator+(const UnoCard& add){
    this->getDeckPlayer().push_back(add);
    return *this;
}

UnoPlayer& UnoPlayer::operator-(){
    this->getDeckPlayer().pop_back();
    return *this;
}
UnoPlayer::~UnoPlayer(){}

UnoCard UnoPlayer::getCard(int index){
    return this->getDeckPlayer()[index];
}

void UnoPlayer::printCard(){
    vector<UnoCard> deck = this->getDeckPlayer();
    for(int i = 0; i < deck.size(); i++){
        if(deck[i].getIsNumber()){
            cout << i+1 << ". " << deck[i].getNumber() << " " << deck[i].getColor() << endl;
        } else {
            cout << i+1 << ". " << deck[i].getType() << " " << deck[i].getColor() << endl;
        }
    }
}

void UnoPlayer::push(const UnoCard& PC){
   this->getDeckPlayer().push_back(PC);
}

UnoCard UnoPlayer::pop(){
    UnoCard PCx = this->getDeckPlayer().back();
    this->getDeckPlayer().pop_back();
    return PCx;
}