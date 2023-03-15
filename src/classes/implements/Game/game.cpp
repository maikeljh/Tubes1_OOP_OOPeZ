#include "../../headers/Game/game.hpp"
#include "../../headers/CardGenerator/cardGenerator.hpp"
#include "../../headers/Command/commandParser.hpp"
#include <iostream>

using namespace std;

/* ctor */
Game::Game(){
    this->valid = false;
    this->playerTurn = 0;
}

/* getter */
int Game::getNPlayers(){
    return this->nPlayers;
}

bool Game::getValid(){
    return this->valid;
}

int Game::getPlayerTurn(){
    return this->playerTurn;
}

/* setter*/
void Game::setPlayerTurn(int turn){
    this->playerTurn = turn;
}

void Game::setValid(bool val){
    this->valid = val;
}