#include "../../headers/Value/Combination/combination.hpp"
#include "../generic.cpp"
#include <iostream>
#include <map>

using namespace std;

Combination::Combination(){}

double Combination::getValue(){
    return this->point;
}

string Combination::getCombo() {
    return this->combo;
}

void Combination::setValue(double value) {
    this->point = value;
}

void Combination::setCombo(string combo) {
    this->combo = combo;
}

void Combination::setComboCard(vector<Card> &combo) {
    for (int i = 0; i < combo.size(); i++) {
        this->comboCard.push_back(combo[i]);
    }
}

void Combination::setPlayerCard(vector <Card> &PC) {
    for (int i = 0; i < PC.size(); i++) {
        this->playerCard.push_back(PC[i]);
    }
}

void Combination::setTableCard(vector <Card> &TC) {
    for (int i = 0; i < TC.size(); i++) {
        this->tableCard.push_back(TC[i]);
    }
}

void Combination::clearCombo(){
    int size = this->comboCard.size();
    for(int i = 0; i < size ; i++){
        this->comboCard.pop_back();
    }
    this->combo = "";
    this->point = 0;
}

void Combination::mergeCard(vector <Card> &TC, vector <Card> &PC) {
    vector <Card> CC;
    for (int i = 0; i < 5; i++) {
        CC.push_back(TC[i]);
    }

    for (int i = 0; i < 2; i++) {
        CC.push_back(PC[i]);
    }

    // Sorting card berdasarkan angka dan warnanya

    this->quicksort(CC, 0, CC.size()-1);
    this->setComboCard(CC);
    this->setPlayerCard(PC);
    this->setTableCard(TC);
}

void Combination::printCombo() {
    if (this->combo != "Straight Flush" || this->combo != "Flush") {
        cout << this->combo << endl;
    }
    else {
        cout << this->combo << " " << this->comboCard[0].getColor() << endl;
    }
    for (int i = 0; i < this->comboCard.size() ; i++) {
        cout << this->comboCard[i].getNumber() << " " << this->comboCard[i].getColor() << " ";
    }
    cout << endl;

    // Print player card
    for (int i = 0; i < this->playerCard.size(); i++) {
       cout << this->playerCard[i].getNumber() << " " << this->playerCard[i].getColor() << " ";
    }
    cout << endl;
}

Combination::~Combination() {

}

bool Combination::operator<(Combination& other) {
    return this->point < other.point;
}

bool Combination::operator>(Combination& other) {
    return this->point > other.point;
}

bool Combination::operator==(Combination& other) {
    return this->point == other.point;
}

bool Combination::existPlayerCard() {
    for (int i = 0; i < this->comboCard.size(); i++) {
        if (this->comboCard[i] == this->playerCard[0] || this->comboCard[i] == this->playerCard[1]) {
            return true;
        }
    }
    return false;
}

bool Combination::isPlayerCard(Card &a) {
    return (this->playerCard[0] == a || this->playerCard[1] == a);
}

bool Combination::isStraightFlush() {
    bool temp;
    for (int i = this->comboCard.size()-1 ; i >= 4; i--) {
        temp = true;
        for (int j = i; j > i-4; j--) {
            if (this->comboCard[j].getNumber()-1 != this->comboCard[j-1].getNumber()-1 || this->comboCard[j].getColor() != this->comboCard[j-1].getColor()) {
                temp = false;
            }
        }
        if (temp == true) {
            break;
        }
    }
    return temp;
}

bool Combination::isFourOfaKind(){
    int maxSama = 0;
    for(int i = 0;i<this->comboCard.size()-1;i++){
        int tempSama = 0;
        for(int j = i+1;j<this->comboCard.size();j++){
            if(this->comboCard[i].getNumber()==this->comboCard[j].getNumber()){
                tempSama +=1;
            }
        }
        if(tempSama>maxSama){
            maxSama=tempSama;
        }
    }
    if(maxSama==3){
        return true;
    }
    return false;
}
bool Combination::isFullHouse(){
    map<int, int> comboMap;
    map<int, int>::iterator itr;
    for (int i = 0; i < this->comboCard.size(); i++) {
        if (comboMap.find(this->comboCard[i].getNumber()) == comboMap.end()) {
            comboMap[this->comboCard[i].getNumber()] = 1;
        }
        else {
            comboMap[this->comboCard[i].getNumber()]++;
        }
    }
    bool ada3 = false;
    bool ada2 = false;
    for (itr = comboMap.begin(); itr != comboMap.end(); itr++) {
        if (itr->second == 3) {
            ada3 = true;
        }
        else if (itr->second == 2) {
            ada2 = true;
        }
    }

    if (ada2 && ada3) {
        return true;
    }
    else {
        return false;
    }
}

bool Combination::isFlush() {
    map<string, int> dictWarna;
    map<string,int>::iterator itr;
    dictWarna["Green"] = 0;
    dictWarna["Red"] = 0;
    dictWarna["Yellow"] = 0;
    dictWarna["Blue"] = 0;

    for (int i = 0; i < this->comboCard.size(); i++) {
        if (this->comboCard[i].getColor() == "Green") {
            dictWarna["Green"]++;
        }
        else if (this->comboCard[i].getColor() == "Blue") {
            dictWarna["Blue"]++;
        }
        else if (this->comboCard[i].getColor() == "Yellow") {
            dictWarna["Yellow"]++;
        }
        else {
            dictWarna["Red"]++;
        }
    }

    for (itr = dictWarna.begin(); itr != dictWarna.end(); itr++) {
        if (itr->second == 5) {
            return true;
        }
    }
    return false;
}

bool Combination::isStraight() {
    bool temp;
    for (int i = this->comboCard.size()-1 ; i >= 4; i--) {
        temp = true;
        for (int j = i; j > i-4; j--) {
            if (this->comboCard[j].getNumber()-1 != this->comboCard[j-1].getNumber()) {
                temp = false;
            }
        }
        if (temp == true) {
            break;
        }
    }
    return temp;
}

bool Combination::isThreeOfaKind(){
    int maxSama = 0;
    for(int i = 0;i<this->comboCard.size()-1;i++){
        int tempSama = 0;
        for(int j = i+1;j<this->comboCard.size();j++){
            if(this->comboCard[i].getNumber()==this->comboCard[j].getNumber()){
                tempSama +=1;
            }
        }
        if(tempSama>maxSama){
            maxSama=tempSama;
        }
    }
    if(maxSama==2){
        return true;
    }
    return false;

}
bool Combination::isTwoPair(){
    int maxSama = 0;
    int nPair = 0;
    for(int i = 0;i<this->comboCard.size()-1;i++){
        int tempSama = 0;
        for(int j = i+1;j<this->comboCard.size();j++){
            if(this->comboCard[i].getNumber()==this->comboCard[j].getNumber()){
                tempSama +=1;
                nPair +=1;
            }
        }
        if(tempSama>maxSama){
            maxSama=tempSama;
        }
    }
    if(maxSama==1 && nPair==2){
        return true;
    }
    return false;
}

bool Combination::isPair(){
    int maxSama = 0;
    for(int i = 0;i<this->comboCard.size()-1;i++){
        int tempSama = 0;
        for(int j = i+1;j<this->comboCard.size();j++){
            if(this->comboCard[i].getNumber()==this->comboCard[j].getNumber()){
                tempSama +=1;
            }
        }
        if(tempSama>maxSama){
            maxSama=tempSama;
        }
    }
    if(maxSama==1){
        return true;
    }
    return false;

}

void Combination::straightFlush() {
    vector <Card> combo;
    int index;
    for (int i = this->comboCard.size()-1 ; i >= 4; i--) {
        bool temp = true;
        for (int j = i; j > i-4; j--) {
            if (this->comboCard[j].getNumber()-1 != this->comboCard[j-1].getNumber()-1 || this->comboCard[j].getColor() != this->comboCard[j-1].getColor()) {
                temp = false;
            }
        }
        if (temp == true) {
            index = i;
            break;
        }
    }

    for (int i = index-4; i < index+1; i++) {
        combo.push_back(this->comboCard[i]);
    }
    this->comboCard.clear();
    this->setComboCard(combo);
}

void Combination::fourOfaKind(){
    int maxSama = 0;
    Card cek;
    vector <Card> hasil;
    for(int i = 0;i<this->comboCard.size()-1;i++){
        int tempSama = 0;
        for(int j = i+1;j<this->comboCard.size();j++){
            if(this->comboCard[i].getNumber()==this->comboCard[j].getNumber()){
                tempSama +=1;
            }
        }
        if(tempSama>maxSama){
            maxSama=tempSama;
            cek = this->comboCard[i];
        }
    }
    for (int i = 0;i<this->comboCard.size();i++){
        if(this->comboCard[i].getNumber()==cek.getNumber()){
            Card temp = this->comboCard[i];
            hasil.push_back(temp);  
        }
    }
    this->comboCard.clear();
    this->setComboCard(hasil);
}

void Combination::fullHouse(){
    map<int, int> comboMap;
    map<int, int>::iterator itr;
    for (int i = 0; i < this->comboCard.size(); i++) {
        if (comboMap.find(this->comboCard[i].getNumber()) == comboMap.end()) {
            comboMap[this->comboCard[i].getNumber()] = 1;
        }
        else {
            comboMap[this->comboCard[i].getNumber()]++;
        }
    }
    int ada_3;
    int ada_2;
    for (itr = comboMap.begin(); itr != comboMap.end(); itr++) {
        if (itr->second == 3) {
            ada_3 = itr->first;
        }
        else if (itr->second == 2) {
            ada_2 = itr->first;
        }
    }

    vector<Card> combo;
    for (int i = 0; i < this->comboCard.size(); i++) {
        if (this->comboCard[i].getNumber() == ada_3 || this->comboCard[i].getNumber() == ada_2) {
            combo.push_back(this->comboCard[i]);
        }
    }

    this->comboCard.clear();
    this->setComboCard(combo);
}

void Combination::flush() {
    map<string, int> dictWarna;
    map<string,int>::iterator itr;
    string warna;
    dictWarna["Green"] = 0;
    dictWarna["Red"] = 0;
    dictWarna["Yellow"] = 0;
    dictWarna["Blue"] = 0;

    for (int i = 0; i < this->comboCard.size(); i++) {
        if (this->comboCard[i].getColor() == "Green") {
            dictWarna["Green"]++;
        }
        else if (this->comboCard[i].getColor() == "Blue") {
            dictWarna["Blue"]++;
        }
        else if (this->comboCard[i].getColor() == "Yellow") {
            dictWarna["Yellow"]++;
        }
        else {
            dictWarna["Red"]++;
        }
    }
    for (itr = dictWarna.begin(); itr != dictWarna.end(); itr++) {
        if (itr->second == 5) {
            warna = itr->first;
        }
    }

    vector<Card> combo;
    for (int i = 0; i < this->comboCard.size(); i++) {
        if (this->comboCard[i].getColor() == warna) {
            combo.push_back(this->comboCard[i]);
        }
    }
    this->comboCard.clear();
    this->setComboCard(combo);
}

void Combination::straight() {
    int index;
    vector <Card> combo;
    for (int i = this->comboCard.size()-1 ; i >= 4; i--) {
        bool temp = true;
        for (int j = i; j > i-4; j--) {
            if (this->comboCard[j].getNumber()-1 != this->comboCard[j-1].getNumber()) {
                temp = false;
            }
        }
        if (temp == true) {
            index = i;
            break;
        }
    }

    for (int i = index-4; i < index+1; i++) {
        combo.push_back(this->comboCard[i]);
    }

    this->comboCard.clear();
    this->setComboCard(combo);
}

void Combination::threeOfaKind(){
    int maxSama = 0;
    Card cek;
    vector <Card> hasil;
    for(int i = this->comboCard.size()-1;i> 0;i--){
        if(maxSama<2){
            int tempSama = 0;
            for(int j=i-1;j>=0;j--){
                if(this->comboCard[i].getNumber()==this->comboCard[j].getNumber()){
                tempSama +=1;
            }
            }
            if(tempSama>maxSama){
                maxSama=tempSama;
                cek = this->comboCard[i];
            }
        }
    }
    for (int i = 0;i<this->comboCard.size();i++){
        if(this->comboCard[i].getNumber()==cek.getNumber()){
            Card temp = this->comboCard[i];
            hasil.push_back(temp);  
        }
    }

    this->comboCard.clear();
    this->setComboCard(hasil);

}
void Combination::twoPair(){
    int nPair = 0;
    Card cek;
    Card cek2;
    vector <Card> hasil;
    for(int i = this->comboCard.size()-1;i> 0;i--){
        if(nPair<2){
            int tempSama = 0;
            for(int j=i-1;j>=0;j--){
                if(this->comboCard[i].getNumber()==this->comboCard[j].getNumber()){
                    tempSama +=1;
                    nPair+=1;
                }
            }
            if(tempSama==1){
                if(nPair==2){
                    cek2 = this->comboCard[i];
                }
                else {
                    cek = this->comboCard[i];
                }
            }
        }
    }
    int n = 0;
    for (int i = 0;i<this->comboCard.size();i++){
        if(n<2){
            if(this->comboCard[i].getNumber()==cek2.getNumber()){
                Card temp = this->comboCard[i];
                hasil.push_back(temp);  
                n++;
            }
        }
        else {
            if(this->comboCard[i].getNumber()==cek.getNumber()){
                Card temp = this->comboCard[i];
                hasil.push_back(temp);  
                n++;
            }
        }
    }

    this->comboCard.clear();
    this->setComboCard(hasil);
}
void Combination::pair(){
    int maxSama = 0;
    Card cek;
    vector <Card> hasil;
    for(int i = this->comboCard.size()-1;i> 0;i--){
        if(maxSama<1){
            int tempSama = 0;
            for(int j=i-1;j>=0;j--){
                if(this->comboCard[i].getNumber()==this->comboCard[j].getNumber()){
                tempSama +=1;
            }
            }
            if(tempSama>maxSama){
                maxSama=tempSama;
                cek = this->comboCard[i];
            }
        }
    }
    for (int i = 0;i<this->comboCard.size();i++){
        if(this->comboCard[i].getNumber()==cek.getNumber()){
            Card temp = this->comboCard[i];
            hasil.push_back(temp);  
        }
    }

    this->comboCard.clear();
    this->setComboCard(hasil);
}

double Combination::value() {
    double comboValue;
    //straight flush
    if (this->comboCard.size() >= 5 && this->existPlayerCard() && this->isStraightFlush()) {
        for (int i = 0; i < this->comboCard.size(); i++) {
            if (this->isPlayerCard(this->comboCard[i])) {
                comboValue = this->comboCard[i].value() + 12.5;
            }
        }
    }
    //four of a kind
    else if (this->comboCard.size() >= 4 && this->existPlayerCard() && this->isFourOfaKind()) {
        comboValue = maxValue(this->comboCard).value() + 11.11;
    }
    //full house
    else if (this->comboCard.size() >= 5 && this->existPlayerCard() && this->isFullHouse()) {
        int nCard1 = 0;
        int nCard2 = 0;
        vector <Card> Card1;
        vector <Card> Card2;
        int Card = this->comboCard[0].getNumber();
        for (int i = 0; i<this->comboCard.size();i++){
            if(this->comboCard[i].getNumber()==Card){
                nCard1++;
                Card1.push_back(this->comboCard[i]);
            }
            else {
                nCard2++;
                Card2.push_back(this->comboCard[i]);
            }
        }
        if(nCard1==3){
            comboValue = maxValue(Card1).value() + 9.72;
        }
        else {
            comboValue = maxValue(Card2).value() + 9.72;
        }
    }
    //flush
    else if (this->comboCard.size() >= 5 && this->existPlayerCard() && this->isFlush()) {
        comboValue = maxValue(this->comboCard).value() + 8.33;
    }
    //straight
    else if (this->comboCard.size() >= 5 && this->existPlayerCard() && this->isStraight()) {
        comboValue = maxValue(this->comboCard).value() + 6.94;
    }
    //three of a kind
    else if (this->comboCard.size() >= 3 && this->existPlayerCard() && this->isThreeOfaKind()) {
        bool green = false;
        bool blue = false;
        bool yellow = false;
        bool red = false;

        for (int i = 0;i<this->comboCard.size();i++){
            if (this->comboCard[i].getColor()=="Green"){
                green = true;
            }
            else if (this->comboCard[i].getColor()=="Blue"){
                blue = true;
            }
            else if (this->comboCard[i].getColor()=="Yellow"){
                yellow = true;
            }
            else if (this->comboCard[i].getColor()=="Red"){
                red = true;
            }
        }

        if(green && blue && yellow){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(1*0.02)+5.56;
        }
        else if (green && blue && red){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(2*0.02)+5.56;
        }
        else if (green && yellow && red){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(3*0.02)+5.56;
        }
        else if (blue && yellow && red){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(4*0.02)+5.56;
        }
        // comboValue = maxValue(this->comboCard).value() + 5.56; //rumus
    }
    //two pair
    else if (this->comboCard.size() >= 4 && this->existPlayerCard() && this->isTwoPair()) {
        int highetPairNumber = maxValue(this->comboCard).getNumber();
        bool green = false;
        bool blue = false;
        bool yellow = false;
        bool red = false;

        for (int i = 0;i<this->comboCard.size();i++){
            if(this->comboCard[i].getNumber()==highetPairNumber){
                if (this->comboCard[i].getColor()=="Green"){
                    green = true;
                }
                else if (this->comboCard[i].getColor()=="Blue"){
                    blue = true;
                }
                else if (this->comboCard[i].getColor()=="Yellow"){
                    yellow = true;
                }
                else if (this->comboCard[i].getColor()=="Red"){
                    red = true;
                }
            }
        }
        if(green && blue){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(1*0.015)+1.39 + 2.78;
        }
        else if (green && yellow){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(2*0.015)+1.39 + 2.78;
        }
        else if (blue && yellow){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(3*0.015)+1.39 + 2.78;
        }
        else if (green && red){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(4*0.015)+1.39 +2.78;
        }
        else if (blue && red){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(5*0.015)+1.39 + 2.78;
        }
        else if (yellow && red){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(6*0.015)+1.39 +2.78;
        }

        // comboValue = maxValue(this->comboCard).value() + 2.78;
    }
    //pair
    else if (this->comboCard.size() >= 2 && this->existPlayerCard() && this->isPair()) {
        bool green = false;
        bool blue = false;
        bool yellow = false;
        bool red = false;

        for (int i = 0;i<this->comboCard.size();i++){
            if (this->comboCard[i].getColor()=="Green"){
                green = true;
            }
            else if (this->comboCard[i].getColor()=="Blue"){
                blue = true;
            }
            else if (this->comboCard[i].getColor()=="Yellow"){
                yellow = true;
            }
            else if (this->comboCard[i].getColor()=="Red"){
                red = true;
            }
        }
        if(green && blue){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(1*0.015)+1.39;
        }
        else if (green && yellow){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(2*0.015)+1.39;
        }
        else if (blue && yellow){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(3*0.015)+1.39;
        }
        else if (green && red){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(4*0.015)+1.39;
        }
        else if (blue && red){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(5*0.015)+1.39;
        }
        else if (yellow && red){
            comboValue = (1.0*(maxValue(this->comboCard).getNumber())/10)+(6*0.015)+1.39;
        }
        // comboValue = maxValue(this->comboCard).value() + 1.39;//rumus
    }
    //highcard max value 
    else {
        comboValue = maxValue(this->playerCard).value();
    }

    return comboValue;
}

void Combination::makeCombo() {
    if (this->isStraightFlush()) {
        this->straightFlush();
        this->setValue(this->value());
        this->setCombo("Straight Flush");
    }
    else if (this->isFourOfaKind()) {
        this->fourOfaKind();
        this->setValue(this->value());
        this->setCombo("Four of a Kind");
    }
    else if (this->isFullHouse()) {
        this->fullHouse();
        this->setValue(this->value());
        this->setCombo("Full House");
    }
    else if (this->isFlush()) {
        cout<<"flush 1"<<endl;
        this->flush();
        cout<<"flush 2"<<endl;
        this->setValue(this->value()); // ini ada fakap kadang jd crash blm tau triggernya apa
        cout<<"flush 3"<<endl;
        this->setCombo("Flush");
    }
    else if (this->isStraight()) {
        this->straight();
        this->setValue(this->value());
        this->setCombo("Straight");
    }
    else if (this->isThreeOfaKind()) {
        this->threeOfaKind();
        this->setValue(this->value());
        this->setCombo("Three of a Kind");
    }
    else if (this->isTwoPair()) {
        this->twoPair();
        this->setValue(this->value());
        this->setCombo("Two Pair");
    }
    else if (this->isPair()) {
        this->pair();
        this->setValue(this->value());
        this->setCombo("Pair");
    }
    else {
        Card highest = maxValue(this->comboCard);
        this->comboCard.clear();
        this->comboCard.push_back(highest);
        this->setValue(this->value());
        this->setCombo("High Card");
    }
}

void Combination::quicksort(vector <Card>& CC, int low, int high) {
    if (low < high) {
        double pivot = CC[high].value();
        int i = low-1;
        for (int j = low; j < high; j++) {
            if (CC[j].value() <= pivot) {
                i += 1;
                Card temp = CC[i];
                CC[i] = CC[j];
                CC[j] = temp;
            }
        }
        Card temp = CC[i+1];
        CC[i+1] = CC[high];
        CC[high] = temp;
        int pi = i + 1;

        quicksort(CC, low, pi-1);
        quicksort(CC, pi+1, high);
    }

}
