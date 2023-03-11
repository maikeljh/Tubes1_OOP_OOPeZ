#include "../../headers/Game/game.hpp"
#include "../../headers/CardGenerator/cardGenerator.hpp"
#include "../../headers/Command/commandParser.hpp"
#include <iostream>

using namespace std;

Game::Game(int max):table(max){
    this->isClockWise = true;
    this->playerTurn = 0;
    this->lastIdxTurn = 6;
}

Game::Game(const Game& other):table(5){
    for(int i = 0; i < this->nPlayers; i++){
        this->players.pop_back();
    }
    for(int i = 0; i < this->nPlayers; i++){
        this->players.push_back(other.players[i]);
    }
    this->isClockWise = other.isClockWise;
    this->playerTurn = other.playerTurn;
    this->lastIdxTurn = other.lastIdxTurn;
}

Game::~Game(){}

void Game::setIsClockWise(bool isClockWise){
    this->isClockWise = isClockWise;
}

void Game::setPlayerTurn(int playerTurn){
    this->playerTurn = playerTurn;
}

bool Game::getIsClockWise(){
    return this->isClockWise;
}

int Game::getPlayerTurn(){
    return this->playerTurn;
}

int Game::getLastIdxTurn(){
    return this->lastIdxTurn;
}

void Game::setLastIdxTurn(int last){
    this->lastIdxTurn = last;
}

Player& Game::getPlayer(){
    return this->players[this->playerTurn];
}

int Game::getNPlayers(){
    return this->nPlayers;
}