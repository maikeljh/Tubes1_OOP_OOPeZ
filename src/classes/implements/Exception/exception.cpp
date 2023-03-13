#include "../../headers/Exception/exception.h"

/* GameException */

/* Command Invalid Exception */
const char* CommandInvalidExc::what() const throw(){
    return "Command tidak valid!\n";
}

/* Input File Invalid Exception */
const char* InputFileInvalidExc::what() const throw(){
    return "File tidak ditemukan!\n";
}

/* Input Number Invalid Exception */
const char* InputNumberInvalidExc::what() const throw(){
    return "Angka yang dimasukkan tidak valid!\n";
}

/* Input Action Invalid Exception */
const char* InputActionInvalidExc::what() const throw(){
    return "Input tidak valid!\n";
}