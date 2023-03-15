#ifndef UNO_GAME_HPP
#define UNO_GAME_HPP

#include "./game.hpp"
#include "../Inventory/children/DeckCard/deckCard.hpp"
#include "../Inventory/children/Player/unoPlayer.hpp"

#include <iostream>
using namespace std;

class UnoGame : public Game {
    private:
        DeckCard<UnoCard> deck; /* Deck Uno Card */
        vector<UnoPlayer> players; /* List of Uno Players */
        TableCard<UnoCard> table; /* Table Uno Card */
        bool alreadyDraw; /* True if the current player already draw (only 1 draw can be done per turn )*/
        bool UNO; /* True if someone says UNO! */

    public:
        /* ctor */
        UnoGame();

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

        /* other methods */
        void startGame();
        int chooseWinner();
        bool isEndGame();
};

#endif