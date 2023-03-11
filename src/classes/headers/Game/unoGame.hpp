#ifndef UNO_GAME_HPP
#define UNO_GAME_HPP

#include "./game.hpp"
#include "../BaseCard/baseCard.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"

#include <iostream>
using namespace std;

class UnoGame : public Game {
    private:
        DeckCard<BaseCard> deck;

    public:
        UnoGame();
        UnoGame(const UnoGame& other);
        ~UnoGame();
        void startGame();
        int chooseWinner();
        DeckCard<BaseCard>& getDeckCard();
        bool isEndGame();

};

#endif