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