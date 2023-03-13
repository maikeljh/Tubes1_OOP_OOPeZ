#include "../../headers/Value/Card/unoCard.hpp"

using namespace std;

UnoCard::UnoCard(){}

UnoCard::UnoCard(int number, string color, string type){
    this->number = number;
    this->color = color;
    this->type = type;
    if (number>=0 && number<=9){
        isNumber = true;
    } else {
        isNumber = false;
    }
}

UnoCard& UnoCard::operator=(const UnoCard& other){
    number = other.number;
    color = other.color;
    type = other.type;
    useable = other.useable;
    isNumber = other.isNumber;
    return *this;
}

bool UnoCard::operator==(UnoCard& other){
    if (getIsNumber() && other.getIsNumber()){
        // keduanya kartu angka
        if (getNumber()==other.getNumber() || getColor()==other.getColor()){
            return true; // true jika angka sama atau warna sama
        }
    } else {
        // salah satunya atau keduanya kartu ability
        if (getIsNumber()){
            // kartu pertama angka, kartu kedua ability
            if (getColor()==other.getColor() || other.getColor()==""){
                return true; // true jika warna sama atau ability card tanpa warna
            }
        } else if (other.getIsNumber()){
            // kartu pertama ability, kartu kedua angka
            if (getColor()==other.getColor() || getColor()==""){
                return true; // true jika warna sama atau ability card tanpa warna
            }
        } else {
            // keduanya kartu ability
            if (getColor()==other.getColor() || getType()==other.getType() || getColor()=="" || other.getColor()==""){
                return true; // true jika warna sama atau tipe sama atau ability card tanpa warna
            }
        }
    }
    return false; // else
}

bool UnoCard::getIsNumber(){
    return this->isNumber;
}

void UnoCard::printDetail(){
    if(this->isNumber){
        cout << this->number << " " << this->color << endl;
    } else {
        cout << this->type << " " << this->color << endl;
    }
}