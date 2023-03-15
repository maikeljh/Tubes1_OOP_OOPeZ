#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include <stdexcept>
#include <iostream>
using namespace std;

class GameException : public exception{
    public:
        virtual const char* what() const throw()=0;
};

class CommandInvalidExc : public GameException{
    public:
        const char* what() const throw();
};

class InputNumberInvalidExc : public GameException{
    public:
        const char* what() const throw();
};

class InputActionInvalidExc : public GameException{
    public:
        const char* what() const throw();
};

class FileInvalidExc : public GameException{
    public:
        const char* what() const throw();
};

class ConfigInvalidExc : public GameException{
    public:
        const char* what() const throw();
};
#endif