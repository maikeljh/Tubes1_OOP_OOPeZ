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
        PlayerCard(int owner);
        PlayerCard(const PlayerCard& other);
        PlayerCard& operator=(const Card&);
        ~PlayerCard();
        void setOwner(int id);
};

#endif