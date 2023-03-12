#include "../../headers/Inventory/children/Player/candyPlayer.hpp"

using namespace std;

CandyPlayer::CandyPlayer(): Player(){

}

CandyPlayer::CandyPlayer(DeckCard<Card>& DC, string nickname): Player(nickname){
    this->point = 0;
    this->getDeckPlayer().push_back(DC.pop());
    this->getDeckPlayer().push_back(DC.pop());
}

CandyPlayer& CandyPlayer::operator=(CandyPlayer& other){
    this->point = other.point;
    // vector<Card> aa = other.getDeckPlayer();
    // // this->mainDeck.push_back(other.mainDeck[0]);
    // // this->mainDeck.push_back(other.mainDeck[1]);
    // Card a = other.getDeckPlayer()[0];
    this->getDeckPlayer().push_back(other.getDeckPlayer()[0]);
    this->getDeckPlayer().push_back(other.getDeckPlayer()[1]);
    return *this;
}

CandyPlayer& CandyPlayer::operator+(const Card& add){
//     this->mainDeck.push_back(add);
//     return *this;
// }
    this->getDeckPlayer().push_back(add);
    return *this;
}
CandyPlayer& CandyPlayer::operator-(){
// Player& Player::operator-(){
//     this->mainDeck.pop_back();
//     return *this;
// }
    this->getDeckPlayer().pop_back();
    return *this;
}

bool CandyPlayer::operator>(const CandyPlayer& other){
// bool Player::operator>(const Player& other){
//     return this->point > other.point;
// }
}

bool CandyPlayer::operator<(const CandyPlayer& other){
// bool Player::operator<(const Player& other){
//     return this->point < other.point;
// }

}

bool CandyPlayer::operator==(const CandyPlayer& other){
// bool Player::operator==(const Player& other){
//     return (this->point == other.point);
    
// }
}

CandyPlayer::~CandyPlayer(){
}

void CandyPlayer::useAbilityCard(){
// void Player::useAbilityCard(){
//     this->ability.setUseable(false);
// }
    this->ability.setUseable(false);
}

bool CandyPlayer::checkValidAbilityCard(string ability){
// bool Player::checkValidAbilityCard(string ability){
//     return this->ability.getType() == ability;
// }
    return (this->ability.getType() == ability);
}

void CandyPlayer::addAbilityCard(const AbilityCard& AC){
// void Player::addAbilityCard(const AbilityCard& AC){
//     this->ability = AC;
// }
    this->ability = AC;
}

void CandyPlayer::addPoint(long long int round_points){
// void Player::addPoint(long long int round_points){
//     this->point += round_points;
// }
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



// void Player::printCard(){
//     cout << "1. " << this->mainDeck[0].getNumber() << " " << this->mainDeck[0].getColor() << endl;
//     cout << "2. " << this->mainDeck[1].getNumber() << " " << this->mainDeck[1].getColor() << endl;
// }