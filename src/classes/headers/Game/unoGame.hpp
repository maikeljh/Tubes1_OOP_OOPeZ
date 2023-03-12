#ifndef UNO_GAME_HPP
#define UNO_GAME_HPP

#include "./game.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Inventory/children/Player/unoPlayer.hpp"

#include <iostream>
using namespace std;

class UnoGame : public Game {
    private:
        DeckCard<UnoCard> deck;
        vector<UnoPlayer> players;

    public:
        UnoGame();
        UnoGame(const UnoGame& other);
        ~UnoGame();
        void startGame();
        int chooseWinner();
        DeckCard<UnoCard>& getDeckCard();
        bool isEndGame();
        vector<UnoPlayer>& getPlayers();
        UnoPlayer& getPlayer(int idx);

};

#endif