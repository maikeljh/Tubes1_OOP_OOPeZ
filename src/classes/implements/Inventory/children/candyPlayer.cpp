#include "../../../headers/Inventory/children/Player/candyPlayer.hpp"

using namespace std;

/* Ctor */
CandyPlayer::CandyPlayer(): Player(){}

CandyPlayer::CandyPlayer(DeckCard<Card>& DC, string nickname): Player(nickname){
    this->point = 0;
    this->push(DC, 2);
}

/* Operators */
CandyPlayer& CandyPlayer::operator+(const Card& add){
    this->push(add);
    return *this;
}

CandyPlayer& CandyPlayer::operator+(long long int point){
    this->point += point;
    return *this;
}

CandyPlayer& CandyPlayer::operator-(const Card& min){
    for(int i = 0; i < this->mainDeck.size(); i++){
        if(this->mainDeck[i] == min){
            this->mainDeck.erase(this->mainDeck.begin() + i);
            break;
        }
    }
    return *this;
}

CandyPlayer& CandyPlayer::operator--(){
    Card trash = this->pop();
    return *this;
}

bool CandyPlayer::operator>(const CandyPlayer& other){
    return this->point > other.point;
}

bool CandyPlayer::operator<(const CandyPlayer& other){
    return this->point < other.point;
}

bool CandyPlayer::operator==(const CandyPlayer& other){
    return (this->point == other.point);
}

/* Getter */
Combination& CandyPlayer::getCombo(){
    return this->kombo;
}

long long int CandyPlayer::getPoint(){
    return this->point;
}

AbilityCard& CandyPlayer::getAbilityCard(){
    return this->ability;
}

/* Other methods */
void CandyPlayer::useAbilityCard(){
    this->ability.setUseable(false);
}

bool CandyPlayer::checkValidAbilityCard(string ability){
    return (this->ability.getType() == ability);
}

void CandyPlayer::addAbilityCard(const AbilityCard& AC){
    this->ability = AC;
}

void CandyPlayer::printCard(){
    cout << "1. " << this->mainDeck[0].getNumber() << " " << this->mainDeck[0].getColor() << endl;
    cout << "2. " << this->mainDeck[1].getNumber() << " " << this->mainDeck[1].getColor() << endl;
    if(this->ability.getType() != "" && this->ability.getUseable()){
        cout << "3. " << this->ability.getType() << " Ability Card" << endl;
    }
}