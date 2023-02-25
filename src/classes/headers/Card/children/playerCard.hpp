#ifndef PLAYER_CARD_HPP
#define PLAYER_CARD_HPP

#include <iostream>
#include "../card.hpp"

using namespace std;

class PlayerCard: public Card {
    private:
        int owner;

    public:
        PlayerCard();
        PlayerCard(const Card& C);
        PlayerCard(const Card& C, int owner);
        PlayerCard(const PlayerCard& other);
        PlayerCard& operator=(Card&);
        void setOwner(int id);
};

#endif