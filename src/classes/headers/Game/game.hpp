#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../Inventory/children/Player/player.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"

using namespace std;

class Game {
    private:
        int round;
        Player *players;
        const int nPlayers = 7;
        long long int point;
        DeckCard deck;
        bool isClockWise;
        int playerTurn;
    
    public:
        Game();
        Game(const Game& other);
        ~Game();
};

#endif