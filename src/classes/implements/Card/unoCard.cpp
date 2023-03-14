#include "../../headers/Value/Card/unoCard.hpp"

using namespace std;

/* ctor */
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

/* operators */
UnoCard& UnoCard::operator=(const UnoCard& other){
    number = other.number;
    color = other.color;
    type = other.type;
    useable = other.useable;
    isNumber = other.isNumber;
    return *this;
}

bool UnoCard::operator==(const UnoCard& other){
    if (this->isNumber && other.isNumber){
        // Keduanya kartu angka
        if (this->number == other.number || this->color == other.color){
            return true; // true jika angka sama atau warna sama
        } else {
            return false;
        }
    } else {
        // salah satunya atau keduanya kartu ability
        if (this->isNumber){
            // kartu pertama angka, kartu kedua ability
            if (this->color == other.color || other.color == "Black"){
                return true; // true jika warna sama atau ability card tanpa warna
            } else {
                return false;
            }
        } else if (other.isNumber){
            // kartu pertama ability, kartu kedua angka
            if (this->color == other.color || this->color == "Black"){
                return true; // true jika warna sama atau ability card tanpa warna
            } else {
                return false;
            }
        } else {
            // keduanya kartu ability
            if (this->color == other.color || this->type == other.type || this->color == "Black" || other.color == "Black"){
                return true; // true jika warna sama atau tipe sama atau ability card tanpa warna
            } else {
                return false;
            }
        }
    }
}

/* getter */
bool UnoCard::getIsNumber(){
    return this->isNumber;
}

/* other functions */
void UnoCard::printDetail(){
    if(this->isNumber){
        cout << this->number << " " << this->color << endl;
    } else {
        cout << this->type << " " << this->color << endl;
    }
}