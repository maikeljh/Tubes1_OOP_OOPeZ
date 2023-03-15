#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include <stdexcept>
#include <iostream>
using namespace std;

/* Exception Parent */
class GameException : public exception{
    public:
        /* Pure virtual method */
        virtual const char* what() const throw()=0;
};

/* Exception Children */
class CommandInvalidExc : public GameException{
    public:
        const char* what() const throw(); // Throw if command invalid
};

class InputNumberInvalidExc : public GameException{
    public:
        const char* what() const throw(); // Throw if number invalid
};

class InputActionInvalidExc : public GameException{
    public:
        const char* what() const throw(); // Throw if action invalid
};

class FileInvalidExc : public GameException{
    public:
        const char* what() const throw(); // Throw if file not found
};

class ConfigInvalidExc : public GameException{
    public:
        const char* what() const throw(); // Throw if config file format invalid
};
#endif