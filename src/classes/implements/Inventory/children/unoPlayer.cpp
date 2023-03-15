#include "../../../headers/Inventory/children/Player/unoPlayer.hpp"

using namespace std;

/* Ctor */
UnoPlayer::UnoPlayer(){}

UnoPlayer::UnoPlayer(DeckCard<UnoCard> &DC, string nickname):Player(nickname){
    for (int i = 0; i < 7; i++){
        this->mainDeck.push_back(DC.pop());
    }
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

/* Getter */
UnoCard UnoPlayer::getCard(int index){
    return this->mainDeck[index];
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

void UnoPlayer::push(const UnoCard& PC){
   this->mainDeck.push_back(PC);
}

UnoCard UnoPlayer::pop(){
    UnoCard PCx;
    if(this->mainDeck.size() > 0){
        PCx = this->mainDeck.back();
        this->mainDeck.pop_back();
        return PCx;
    } else {
        cout << "\nKartu player sudah kosong" << endl;
        return PCx;
    }
}