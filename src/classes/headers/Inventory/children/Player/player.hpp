#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include "../../inventoryHolder.hpp"
#include "../DeckCard/deckCard.hpp"
#include "../../../Value/Card/abilityCard.hpp"
#include "../../../Value/Combination/combination.hpp"

using namespace std;

template <class T>
class Player: public InventoryHolder<T>{
    protected:
        int id; /* Player's ID */
        string nickname; /* Player's nickname */
        vector<T> mainDeck; /* Player's deck card */
        static int playersCreated; /* Determine how many players have been created */
    
    public:
        /* Ctor */
        Player();
        Player(string nickname);

        /* Pure virtual methods */
        virtual T getCard(int index) = 0;
        virtual void push(const T& PC) = 0;
        virtual T pop() = 0;
        virtual void printCard() = 0;

        /* Getter */
        string getNickname();
        int getID();
        vector<T>& getDeckPlayer();
};

template class Player<Card>;
template class Player<AbilityCard>;
template class Player<UnoCard>;

#endif