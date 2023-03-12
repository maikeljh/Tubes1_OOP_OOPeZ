#include "../../headers/Inventory/children/Player/candyPlayer.hpp"

using namespace std;

CandyPlayer::CandyPlayer(): Player(){}

CandyPlayer::CandyPlayer(DeckCard<Card>& DC, string nickname): Player(nickname){
    this->point = 0;
    this->getDeckPlayer().push_back(DC.pop());
    this->getDeckPlayer().push_back(DC.pop());
}

CandyPlayer& CandyPlayer::operator=(CandyPlayer& other){
    this->point = other.point;
    this->getDeckPlayer().push_back(other.getDeckPlayer()[0]);
    this->getDeckPlayer().push_back(other.getDeckPlayer()[1]);
    return *this;
}

CandyPlayer& CandyPlayer::operator+(const Card& add){
    this->getDeckPlayer().push_back(add);
    return *this;
}

CandyPlayer& CandyPlayer::operator-(){
    this->getDeckPlayer().pop_back();
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

CandyPlayer::~CandyPlayer(){}

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

Card CandyPlayer::getCard(int index){
    return this->getDeckPlayer()[index];
}

void CandyPlayer::push(const Card& PC){
   this->getDeckPlayer().push_back(PC);
}

Card CandyPlayer::pop(){
    Card PCx = this->getDeckPlayer().back();
    this->getDeckPlayer().pop_back();
    return PCx;
}

void CandyPlayer::printCard(){
    cout << "1. " << this->getDeckPlayer()[0].getNumber() << " " << this->getDeckPlayer()[0].getColor() << endl;
    cout << "2. " << this->getDeckPlayer()[1].getNumber() << " " << this->getDeckPlayer()[1].getColor() << endl;
    if(this->ability.getType() != "" && this->ability.getUseable()){
        cout << "3. " << this->ability.getType() << " Ability Card" << endl;
    }
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