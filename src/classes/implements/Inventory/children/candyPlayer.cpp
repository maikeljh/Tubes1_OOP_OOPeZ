#include "../../../headers/Inventory/children/Player/candyPlayer.hpp"

using namespace std;

/* Ctor */
CandyPlayer::CandyPlayer(): Player(){}

CandyPlayer::CandyPlayer(DeckCard<Card>& DC, string nickname): Player(nickname){
    this->point = 0;
    this->mainDeck.push_back(DC.pop());
    this->mainDeck.push_back(DC.pop());
}

/* Operators */
CandyPlayer& CandyPlayer::operator+(const Card& add){
    this->push(add);
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
Card CandyPlayer::getCard(int index){
    return this->mainDeck[index];
}

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

void CandyPlayer::addPoint(long long int round_points){
    this->point += round_points;
}

void CandyPlayer::push(const Card& PC){
   this->mainDeck.push_back(PC);
}

Card CandyPlayer::pop(){
    Card PCx;
    if(this->mainDeck.size() > 0){
        PCx = this->mainDeck.back();
        this->mainDeck.pop_back();
        return PCx;
    } else {
        cout << "\nKartu player sudah kosong" << endl;
        return PCx;
    }
}

void CandyPlayer::printCard(){
    cout << "1. " << this->mainDeck[0].getNumber() << " " << this->mainDeck[0].getColor() << endl;
    cout << "2. " << this->mainDeck[1].getNumber() << " " << this->mainDeck[1].getColor() << endl;
    if(this->ability.getType() != "" && this->ability.getUseable()){
        cout << "3. " << this->ability.getType() << " Ability Card" << endl;
    }
}