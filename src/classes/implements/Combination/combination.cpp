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
    this->comboCard.clear();
    this->playerCard.clear();
    this->tableCard.clear();
    this->combo = "";
    this->point = 0;

}

void Combination::mergeCard(vector <Card> &TC, vector <Card> &PC) {
    vector <Card> PC1;
    vector <Card> TC1;
    vector <Card> CC;
    for (int i = 0; i < 5; i++) {
        CC.push_back(TC[i]);
        TC1.push_back(TC[i]);
    }

    for (int i = 0; i < 2; i++) {
        CC.push_back(PC[i]);
        PC1.push_back(PC[i]);
    }
    this->clearCombo();
    // Sorting card berdasarkan angka dan warnanya

    this->quicksort(CC, 0, CC.size()-1);
    this->setComboCard(CC);
    this->setPlayerCard(PC1);
    this->setTableCard(TC1);
}

void Combination::printCombo() {
    if (this->combo != "Straight Flush" || this->combo != "Flush") {
        cout << this->combo << endl;
    }
    else {
        cout << this->combo << " " << this->comboCard[0].getColor() << endl;
    }

    if (this->combo == "High Card") {
        if (this->playerCard[0].value() > this->playerCard[1].value()) {
            cout << this->playerCard[0].getNumber() << " " << this->playerCard[0].getColor() << endl;
        }
        else {
            cout << this->playerCard[1].getNumber() << " " << this->playerCard[1].getColor() << endl;
        }
    }
    else {
        for (int i = 0; i < this->comboCard.size() ; i++) {
            cout << this->comboCard[i].getNumber() << " " << this->comboCard[i].getColor() << " ";
        }
        cout << endl;
    }

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
        if (itr->second >= 5) {
            return true;
        }
    }
    return false;
}

bool Combination::isStraight() {
    bool temp = false;
    int idx = this->comboCard.size()-1;
    int count = 0;
    while (idx > 0) {
        if (this->comboCard[idx].getNumber() == this->comboCard[idx-1].getNumber() + 1) {
            count++;
        }
        else if (this->comboCard[idx].getNumber() == this->comboCard[idx-1].getNumber()) {
            count += 0;
        }
        else {
            count = 0;
        }
        idx--;

        if (count == 4) {
            temp = true;
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
    if(maxSama==1 && nPair>=2){
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

    cout << "Lewat sini ga 1" << endl;

    for (int i = 0; i < this->comboCard.size(); i++) {
        if (this->comboCard[i].getColor() == "Green") {
            dictWarna["Green"]++;
             cout << "Lewat sini ga 2" << endl;
        }
        else if (this->comboCard[i].getColor() == "Blue") {
            dictWarna["Blue"]++;
             cout << "Lewat sini ga 3" << endl;
        }
        else if (this->comboCard[i].getColor() == "Yellow") {
            dictWarna["Yellow"]++;
             cout << "Lewat sini ga 4" << endl;
        }
        else {
            dictWarna["Red"]++;
             cout << "Lewat sini ga 5" << endl;
        }
    }
    for (itr = dictWarna.begin(); itr != dictWarna.end(); itr++) {
        if (itr->second >= 5) {
            warna = itr->first;
             cout << "Lewat sini ga 6" << endl;
        }
    }

    vector<Card> combo;
    for (int i = 0; i < this->comboCard.size(); i++) {
        if (this->comboCard[i].getColor() == warna) {
             cout << "Lewat sini ga 7" << endl;
            combo.push_back(this->comboCard[i]);
        }
    }
    while (combo.size() > 5) {
        combo.erase(combo.begin());
    }
    this->comboCard.clear();
    this->setComboCard(combo);
}

void Combination::straight() {
    int idx = this->comboCard.size()-1;
    int count = 0;
    vector <Card> combo;
    while (idx > 0) {
        if (this->comboCard[idx].getNumber() == this->comboCard[idx-1].getNumber() + 1) {
            count++;
        }
        else if (this->comboCard[idx].getNumber() == this->comboCard[idx-1].getNumber()) {
            count += 0;
        }
        else {
            count = 0;
        }
        idx--;

        if (count == 4) {
            break;
        }
    }

    for (int i = idx; i <= i + 4; i++) {
        if (this->comboCard[i].getNumber() != this->comboCard[i+1].getNumber()) {
            combo.push_back(this->comboCard[i]);
        }
        if (combo.size() == 5) {
            break;
        }
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
    if (this->comboCard.size() >= 5 && this->isStraightFlush()) {
        if (this->existPlayerCard()) {
            for (int i = 0; i < this->comboCard.size(); i++) {
            if (this->isPlayerCard(this->comboCard[i])) {
                comboValue = this->comboCard[i].value() + 12.5;
            }
        }
        }
        else {
            comboValue = -1;
        }
    }
    //four of a kind
    else if (this->comboCard.size() >= 4 && this->isFourOfaKind()) {
        if (this->existPlayerCard()) {
            for (int i = 0; i < this->comboCard.size(); i++) {
                if (this->isPlayerCard(this->comboCard[i])) {
                    comboValue = this->comboCard[i].value() + 11.11;
                }
            }
        }
        else {
            comboValue = -1;
        }
    }
    //full house
    else if (this->comboCard.size() >= 5 && this->isFullHouse()) {
        if (this->existPlayerCard()) {
            int nCard1 = 0;
            int nCard2 = 0;
            bool flag = false;
            int Card = this->comboCard[0].getNumber();
            for (int i = 0; i<this->comboCard.size();i++){
                if(this->comboCard[i].getNumber()==Card){
                    nCard1+=1;
                }
                else {
                    nCard2+=1;
                }
            }
            if(nCard1==3){
                for (int i = 0; i<3;i++){
                    if(this->isPlayerCard(this->comboCard[i])){
                        flag = true;
                        comboValue = this->comboCard[i].value() + 9.72;
                    }
                }
                if(flag == false){
                    for (int i = 3; i<this->comboCard.size();i++){
                        if(this->isPlayerCard(this->comboCard[i])){
                            comboValue = this->comboCard[i].value() + 9.72;
                        }
                    }
                }
            }
            else {
                for (int i = 2; i<this->comboCard.size();i++){
                    if(this->isPlayerCard(this->comboCard[i])){
                        flag = true;
                        comboValue = this->comboCard[i].value() + 9.72;
                    }
                }
                if(flag == false){
                    for (int i = 0; i<2;i++){
                        if(this->isPlayerCard(this->comboCard[i])){
                            comboValue = this->comboCard[i].value() + 9.72;
                        }
                    }
                }
            }
        }
        else {
            comboValue = -1;
        }
    }
    //flush
    else if (this->comboCard.size() >= 5 && this->isFlush()) {
        if (this->existPlayerCard()) {
            for (int i = 0; i < this->comboCard.size(); i++) {
                if (this->isPlayerCard(this->comboCard[i])) {
                    comboValue = this->comboCard[i].value() + 8.33;
                }
            }
        }
        else {
            comboValue = -1;
        }
    }
    //straight
    else if (this->comboCard.size() >= 5 && this->isStraight()) {
        if (this->existPlayerCard()) {
            for (int i = 0; i < this->comboCard.size(); i++) {
                if (this->isPlayerCard(this->comboCard[i])) {
                    comboValue = this->comboCard[i].value() + 6.94;
                }
            }
        }
        else {
            comboValue = -1;
        }
    }
    //three of a kind
    else if (this->comboCard.size() >= 3 && this->isThreeOfaKind()) {
        if (this->existPlayerCard()) {
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

            for (int i = 0; i < this->comboCard.size(); i++) {
                if (this->isPlayerCard(this->comboCard[i])) {
                    comboValue = (1.0 * (this->comboCard[i].getNumber())/10);
                }
            }
            
            if(green && blue && yellow){
                comboValue += (1*0.02)+ 5.56;
            }
            else if (green && blue && red){
                comboValue += (2*0.02)+5.56;
            }
            else if (green && yellow && red){
                comboValue += (3*0.02)+5.56;
            }
            else if (blue && yellow && red){
                comboValue += (4*0.02)+5.56;
            }
        }
        else {
            comboValue = -1;
        }
        // comboValue = maxValue(this->comboCard).value() + 5.56; //rumus
    }
    //two pair
    else if (this->comboCard.size() >= 4 && this->isTwoPair()) {
        if (this->existPlayerCard()) {
            int highestPairNumber;
            for (int i = 0;i<this->comboCard.size();i++){
                if(this->isPlayerCard(this->comboCard[i])){
                    highestPairNumber = this->comboCard[i].getNumber();
                }
            }
            // int highetPairNumber = maxValue(this->comboCard).getNumber();
            bool green = false;
            bool blue = false;
            bool yellow = false;
            bool red = false;

            for (int i = 0;i<this->comboCard.size();i++){
                if(this->comboCard[i].getNumber()==highestPairNumber){
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

            for (int i = 0; i < this->comboCard.size(); i++) {
                if (this->isPlayerCard(this->comboCard[i])) {
                    comboValue = (1.0 * (this->comboCard[i].getNumber())/10);
                }
            }

            if(green && blue){
                comboValue += (1*0.015)+1.39 + 2.78;
            }
            else if (green && yellow){
                comboValue += (2*0.015)+1.39 + 2.78;
            }
            else if (blue && yellow){
                comboValue += (3*0.015)+1.39 + 2.78;
            }
            else if (green && red){
                comboValue += (4*0.015)+1.39 +2.78;
            }
            else if (blue && red){
                comboValue += (5*0.015)+1.39 + 2.78;
            }
            else if (yellow && red){
                comboValue += (6*0.015)+1.39 +2.78;
            }
        }
        else {
            comboValue = -1;
        }

        // comboValue = maxValue(this->comboCard).value() + 2.78;
    }
    //pair
    else if (this->comboCard.size() >= 2 && this->isPair()) {
        if (this->existPlayerCard()) {
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

            for (int i = 0; i < this->comboCard.size(); i++) {
                if (this->isPlayerCard(this->comboCard[i])) {
                    comboValue = (1.0 * (this->comboCard[i].getNumber())/10);
                }
            }

            if(green && blue){
                comboValue += (1*0.015) + 1.39;
            }
            else if (green && yellow){
                comboValue += (2*0.015) + 1.39;
            }
            else if (blue && yellow){
                comboValue += (3*0.015) + 1.39;
            }
            else if (green && red){
                comboValue += (4*0.015) + 1.39;
            }
            else if (blue && red){
                comboValue += (5*0.015) + 1.39;
            }
            else if (yellow && red){
                comboValue += (6*0.015) + 1.39;
            }
        }
        else {
            comboValue = -1;
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
        cout<<"Masuk sini 0a"<<endl;
        this->straightFlush();
        cout<<"Masuk sini 1a"<<endl;
        if (this->value() == -1) {
            cout<<"Masuk sini 2a"<<endl;
            this->comboCard.clear();
            cout<<"Masuk sini 2a-1"<<endl;
            this->mergeCard(this->tableCard, this->playerCard);
            cout<<"Masuk sini 2a-2"<<endl;
            this->comboLainSF();
            cout<<"Masuk sini 3a"<<endl;
        }
        else {
            cout<<"Masuk sini 4a"<<endl;
            this->setValue(this->value());
            cout<<"Masuk sini 5a"<<endl;
            this->setCombo("Straight Flush");
            cout<<"Masuk sini 6a"<<endl;
        }
    }
    else if (this->isFourOfaKind()) {
        cout<<"Masuk sini 0b"<<endl;
        this->fourOfaKind();
        cout<<"Masuk sini 1b"<<endl;
        if (this->value() == -1) {
            cout<<"Masuk sini 2b"<<endl;
            this->comboCard.clear();
            cout<<"Masuk sini 2b-1"<<endl;
            this->mergeCard(this->tableCard, this->playerCard);
            cout<<"Masuk sini 2b-2"<<endl;
            this->comboLainFK();
            cout<<"Masuk sini 3b"<<endl;
        }
        else {
            cout<<"Masuk sini 4b"<<endl;
            this->setValue(this->value());
            cout<<"Masuk sini 5b"<<endl;
            this->setCombo("Four of a Kind");
            cout<<"Masuk sini 6b"<<endl;
        }
    }
    else if (this->isFullHouse()) {
        cout<<"Masuk sini 0c"<<endl;
        this->fullHouse();
        cout<<"Masuk sini 1c"<<endl;
        if (this->value() == -1) {
            cout<<"Masuk sini 2c"<<endl;
            this->comboCard.clear();
            cout<<"Masuk sini 2c-1"<<endl;
            this->mergeCard(this->tableCard, this->playerCard);
            cout<<"Masuk sini 2c-2"<<endl;
            this->comboLainFH();
            cout<<"Masuk sini 3c"<<endl;
        }
        else {
            cout<<"Masuk sini 4c"<<endl;
            this->setValue(this->value());
            cout<<"Masuk sini 5c"<<endl;
            this->setCombo("Full House");
            cout<<"Masuk sini 6c"<<endl;
        }
    }
    else if (this->isFlush()) {
        cout<<"flush 1"<<endl;
        this->flush();
        cout<<"Masuk sini 1d"<<endl;
        if (this->value() == -1) {
            cout<<"Masuk sini 2d"<<endl;
            this->comboCard.clear();
            cout<<"Masuk sini 2d-1"<<endl;
            this->mergeCard(this->tableCard, this->playerCard);
            cout<<"Masuk sini 2d-2"<<endl;
            this->comboLainFlush();
            cout<<"Masuk sini 3d"<<endl;
        }
        else {
            cout<<"Masuk sini 4d"<<endl;
            cout<<"flush 2"<<endl;
            this->setValue(this->value()); // ini ada fakap kadang jd crash blm tau triggernya apa
            cout<<"Masuk sini 5d"<<endl;
            cout<<"flush 3"<<endl;
            this->setCombo("Flush");
            cout<<"Masuk sini 6d"<<endl;
        }
    }
    else if (this->isStraight()) {
        cout<<"Masuk sini 0e"<<endl;
        this->straight();
        cout<<"Masuk sini 1e"<<endl;
        if (this->value() == -1) {
            cout<<"Masuk sini 2e"<<endl;
            this->comboCard.clear();
            cout<<"Masuk sini 2e-1"<<endl;
            this->mergeCard(this->tableCard, this->playerCard);
            cout<<"Masuk sini 2e-2"<<endl;
            this->comboLainStraight();
            cout<<"Masuk sini 3e"<<endl;
        }
        else {
            cout<<"Masuk sini 4e"<<endl;
            this->setValue(this->value());
            cout<<"Masuk sini 5e"<<endl;
            this->setCombo("Straight");
            cout<<"Masuk sini 6e"<<endl;
        }
    }
    else if (this->isThreeOfaKind()) {
        cout<<"Masuk sini 0f"<<endl;
        this->threeOfaKind();
        cout<<"Masuk sini 1f"<<endl;
        if (this->value() == -1) {
            cout<<"Masuk sini 2f"<<endl;
            this->comboCard.clear();
            cout<<"Masuk sini 2f-1"<<endl;
            this->mergeCard(this->tableCard, this->playerCard);
            cout<<"Masuk sini 2f-2"<<endl;
            this->comboLainTK();
            cout<<"Masuk sini 3f"<<endl;
        } 
        else {
            cout<<"Masuk sini 4f"<<endl;
            this->setValue(this->value());
            cout<<"Masuk sini 5f"<<endl;
            this->setCombo("Three of a Kind");
            cout<<"Masuk sini 6f"<<endl;
        }
    }
    else if (this->isTwoPair()) {
        cout<<"Masuk sini 0g"<<endl;
        this->twoPair();
        cout<<"Masuk sini 1g"<<endl;
        if (this->value() == -1) {
            cout<<"Masuk sini 2g"<<endl;
            this->comboCard.clear();
            cout<<"Masuk sini 2g-1"<<endl;
            this->mergeCard(this->tableCard, this->playerCard);
            cout<<"Masuk sini 2g-2"<<endl;
            this->comboLainTwoP();
            cout<<"Masuk sini 3g"<<endl;
        }
        else {
            cout<<"Masuk sini 4g"<<endl;
            this->setValue(this->value());
            cout<<"Masuk sini 5g"<<endl;
            this->setCombo("Two Pair");
            cout<<"Masuk sini 6g"<<endl;
        }
    }
    else if (this->isPair()) {
        cout<<"Masuk sini 0h"<<endl;
        this->pair();
        if (this->value() == -1) {
            cout<<"Masuk sini 1h"<<endl;
            this->comboCard.clear();
            cout<<"Masuk sini 2h-1"<<endl;
            this->mergeCard(this->tableCard, this->playerCard);
            cout<<"Masuk sini 2h-2"<<endl;
            this->comboLainPair();
            cout<<"Masuk sini 3h"<<endl;
        }
        else {
            cout<<"Masuk sini 4h"<<endl;
            this->setValue(this->value());
            cout<<"Masuk sini 5h"<<endl;
            this->setCombo("Pair");
            cout<<"Masuk sini 6h"<<endl;
        }
    }
    else {
        Card highest = maxValue(this->playerCard);
        this->comboCard.clear();
        this->comboCard.push_back(highest);
        this->setValue(this->value());
        this->setCombo("High Card");
    }
}

void Combination::comboLainSF() {
    cout<<"Masuk sini 0i"<<endl;
    this->comboLainFlush();
    cout<<"Masuk sini 1i"<<endl;
    if (this->value() == -1) {
        cout<<"Masuk sini 2i"<<endl;
        this->comboCard.clear();
        cout<<"Masuk sini 2i-1"<<endl;
        this->mergeCard(this->tableCard, this->playerCard);
        cout<<"Masuk sini 2i-2"<<endl;
        this->comboLainFlush();
        cout<<"Masuk sini 3i"<<endl;
    }
    else {
        cout<<"Masuk sini 4i"<<endl;
        this->setValue(this->value());
        cout<<"Masuk sini 5i"<<endl;
        this->setCombo("Flush");
        cout<<"Masuk sini 6i"<<endl;
    }
}

void Combination::comboLainFK() {
    cout<<"Masuk sini 0j"<<endl;
    this->fullHouse();
    cout<<"Masuk sini 1j"<<endl;
    if (this->value() == -1) {
        cout<<"Masuk sini 2j"<<endl;
        this->comboCard.clear();
        cout<<"Masuk sini 2j-1"<<endl;
        this->mergeCard(this->tableCard, this->playerCard);
        cout<<"Masuk sini 2j-2"<<endl;
        this->comboLainFH();
        cout<<"Masuk sini 3j"<<endl;
    }
    else {
        cout<<"Masuk sini 4j"<<endl;
        this->setValue(this->value());
        cout<<"Masuk sini 5j"<<endl;
        this->setCombo("Full House");
        cout<<"Masuk sini 6j"<<endl;
    }
    
}

void Combination::comboLainFH() {
    cout<<"Masuk sini 0k"<<endl;
    this->threeOfaKind();
    cout<<"Masuk sini 1k"<<endl;
    if (this->value() == -1) {
        cout<<"Masuk sini 2k"<<endl;
        this->comboCard.clear();
        cout<<"Masuk sini 2k-1"<<endl;
        this->mergeCard(this->tableCard, this->playerCard);
        cout<<"Masuk sini 2k-2"<<endl;
        this->comboLainTK();
        cout<<"Masuk sini 3k"<<endl;
    }
    else {
        cout<<"Masuk sini 4k"<<endl;
        this->setValue(this->value());
        cout<<"Masuk sini 5k"<<endl;
        this->setCombo("Three of a Kind");
        cout<<"Masuk sini 6k"<<endl;
    }
}

void Combination::comboLainFlush() {
    cout<<"Masuk sini 0l"<<endl;
    this->straight();
    cout<<"Masuk sini 1l"<<endl;
    if (this->value() == -1) {
        cout<<"Masuk sini 2l"<<endl;
        this->comboCard.clear();
        cout<<"Masuk sini 2l-1"<<endl;
        this->mergeCard(this->tableCard, this->playerCard);
        cout<<"Masuk sini 2l-2"<<endl;
        this->comboLainStraight();
        cout<<"Masuk sini 3l"<<endl;
    }
    else {
        cout<<"Masuk sini 4l"<<endl;
        this->setValue(this->value());
        cout<<"Masuk sini 5l"<<endl;
        this->setCombo("Straight");
        cout<<"Masuk sini 6l"<<endl;
    }
}

void Combination::comboLainStraight() {
    cout<<"Masuk sini 0m"<<endl;
    this->threeOfaKind();
    cout<<"Masuk sini 1m"<<endl;
    if (this->value() == -1) {
        cout<<"Masuk sini 2m"<<endl;
        this->comboCard.clear();
        cout<<"Masuk sini 2m-1"<<endl;
        this->mergeCard(this->tableCard, this->playerCard);
        cout<<"Masuk sini 2m-2"<<endl;
        this->comboLainTK();
        cout<<"Masuk sini 3m"<<endl;
    }
    else {
        cout<<"Masuk sini 4m"<<endl;
        this->setValue(this->value());
        cout<<"Masuk sini 5m"<<endl;
        this->setCombo("Three of a Kind");
        cout<<"Masuk sini 6m"<<endl;
    }
}

void Combination::comboLainTK() {
    cout<<"Masuk sini 0n"<<endl;
    this->twoPair();
    cout<<"Masuk sini 1n"<<endl;
    if (this->value() == -1) {
        cout<<"Masuk sini 2n"<<endl;
        this->comboCard.clear();
        cout<<"Masuk sini 2n-1"<<endl;
        this->mergeCard(this->tableCard, this->playerCard);
        cout<<"Masuk sini 2n-2"<<endl;
        this->comboLainTwoP();
        cout<<"Masuk sini 3n"<<endl;
    }
    else {
        cout<<"Masuk sini 4n"<<endl;
        this->setValue(this->value());
        cout<<"Masuk sini 5n"<<endl;
        this->setCombo("Two Pair");
        cout<<"Masuk sini 6n"<<endl;
    }
}

void Combination::comboLainTwoP() {
    cout<<"Masuk sini 0o"<<endl;
    this->pair();
    cout<<"Masuk sini 1o"<<endl;
    if (this->value() == -1) {
        cout<<"Masuk sini 2o"<<endl;
        this->comboCard.clear();
        cout<<"Masuk sini 2o-1"<<endl;
        this->mergeCard(this->tableCard, this->playerCard);
        cout<<"Masuk sini 2o-2"<<endl;
        this->comboLainPair();
        cout<<"Masuk sini 3o"<<endl;
    }
    else {
        cout<<"Masuk sini 7o"<<endl;
        this->setValue(this->value());
        cout<<"Masuk sini 8o"<<endl;
        this->setCombo("Pair");
        cout<<"Masuk sini 9o"<<endl;
    }
}

void Combination::comboLainPair() {
    cout<<"Masuk sini 1p"<<endl;
    Card highest = maxValue(this->playerCard);
    this->comboCard.clear();
    cout<<"Masuk sini 2p"<<endl;
    this->comboCard.push_back(highest);
    cout<<"Masuk sini 3p"<<endl;
    this->setValue(this->value());
    cout<<"Masuk sini 4p"<<endl;
    this->setCombo("High Card");
    cout<<"Masuk sini 5p"<<endl;
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
