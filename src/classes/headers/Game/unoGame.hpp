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
        TableCard<UnoCard> table;
        bool alreadyDraw;
        bool UNO;

    public:
        /* ctor, dtor */
        UnoGame();
        UnoGame(const UnoGame& other);
        ~UnoGame();

        /* getter */
        vector<UnoPlayer>& getPlayers();
        UnoPlayer& getPlayer(int idx);
        DeckCard<UnoCard>& getDeckCard();
        TableCard<UnoCard>& getTableCard();
        bool getAlreadyDraw();
        bool getUNO();
        UnoCard getTop();

        /* setter */
        void setAlreadyDraw(bool draw);
        void setUNO(bool uno);

        /* other functions */
        void startGame();
        int chooseWinner();
        bool isEndGame();
};

#endif