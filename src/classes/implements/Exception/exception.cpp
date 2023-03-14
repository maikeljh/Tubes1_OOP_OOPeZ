#include "../../headers/Exception/exception.h"

/* GameException */

/* Command Invalid Exception */
const char* CommandInvalidExc::what() const throw(){
    return "Command tidak valid!\n";
}

/* File Not Found Invalid Exception */
const char* FileInvalidExc::what() const throw(){
    return "File tidak ditemukan!\n";
}

/* Directory Not Found Invalid Exception */
const char* DirectoryInvalidExc::what() const throw(){
    return "Directory tidak ditemukan!\n";
}

/* Input File Invalid Exception */
const char* ConfigInvalidExc::what() const throw(){
    return "File config tidak sesuai format!\n";
}

/* Input Number Invalid Exception */
const char* InputNumberInvalidExc::what() const throw(){
    return "Angka yang dimasukkan tidak valid!\n";
}

/* Input Action Invalid Exception */
const char* InputActionInvalidExc::what() const throw(){
    return "Input tidak valid!\n";
}