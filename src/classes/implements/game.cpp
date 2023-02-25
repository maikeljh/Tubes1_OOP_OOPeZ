#include "../headers/Game/game.hpp"
#include <iostream>

using namespace std;

Game::Game(){
    this->round = 0;
    this->players = new Player[this->nPlayers];
    this->point = 0;
    this->isClockWise = true;
    this->playerTurn = 0;
}

Game::Game(const Game& other){
    this->round = other.round;
    this->players = new Player[this->nPlayers];
    for(int i = 0; i < this->nPlayers; i++){
        this->players[i] = other.players[i];
    }
    this->point = other.point;
    this->isClockWise = other.isClockWise;
    this->playerTurn = other.playerTurn;
}

Game::~Game(){
    delete[] this->players;
}

void Game::startGame(){
    cout << "Halo! Selamat Datang di Kompetisi Kartu ala Kerajaan Permen" << endl;
}

int Game::chooseWinner(){
    double maximum = 0;
    int idx = 0;
    for(int i = 0; i < 7; i++){
        if(this->players[i].getCombo().getValue() > maximum){
            maximum = this->players[i].getCombo().getValue();
            idx = i;
        }
    }
    
    return idx;
}

void Game::setRound(int round){
    this->round = round;
}

void Game::setPoint(long long int point){
    this->point = point;
}

void Game::setIsClockWise(bool isClockWise){
    this->isClockWise = isClockWise;
}

void Game::setPlayerTurn(int playerTurn){
    this->playerTurn = playerTurn;
}

int Game::getRound(){
    return this->round;
}  

long long int Game::getPoint(){
    return this->point;
}

bool Game::getIsClockWise(){
    return this->isClockWise;
}

int Game::getPlayerTurn(){
    return this->playerTurn;
}
