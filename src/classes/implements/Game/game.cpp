#include "../../headers/Game/game.hpp"
#include "../../headers/CardGenerator/cardGenerator.hpp"
#include "../../headers/Command/commandParser.hpp"
#include <iostream>

using namespace std;

Game::Game(){
    this->valid = false;
    this->playerTurn = 0;
}

Game::Game(const Game& other){
    this->valid = other.valid;
    this->playerTurn = other.playerTurn;
}

Game::~Game(){}

int Game::getNPlayers(){
    return this->nPlayers;
}

bool Game::getValid(){
    return this->valid;
}

void Game::setValid(bool val){
    this->valid = val;
}

int Game::getPlayerTurn(){
    return this->playerTurn;
}

void Game::setPlayerTurn(int turn){
    this->playerTurn = turn;
}